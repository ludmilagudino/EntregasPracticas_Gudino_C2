// Fill out your copyright notice in the Description page of Project Settings.

#include "ArtifactAssembler.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FragmentItem.h"

AArtifactAssembler::AArtifactAssembler()
{
    PrimaryActorTick.bCanEverTick = false;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

    CollectedCount = 0;
    RequiredFragments = 0;
    bIsActive = false;
}

void AArtifactAssembler::BeginPlay()
{
    Super::BeginPlay();

    // Material inicial (inactivo)
    if (InactiveMaterial)
    {
        MeshComponent->SetMaterial(0, InactiveMaterial);
    }

    // Buscamos TODOS los FragmentItem del nivel
    TArray<AActor*> FoundFragments;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFragmentItem::StaticClass(), FoundFragments);

    // Bucle para suscribirnos al delegado de cada uno
    for (AActor* Actor : FoundFragments)
    {
        AFragmentItem* Fragment = Cast<AFragmentItem>(Actor);
        if (Fragment)
        {
            Fragment->OnFragmentPicked.AddDynamic(this, &AArtifactAssembler::OnFragmentPickedHandler);
        }
    }

    RequiredFragments = FoundFragments.Num();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue,
            FString::Printf(TEXT("Ensamblador listo. Fragmentos en el nivel: %d"), RequiredFragments));
    }
}

void AArtifactAssembler::OnFragmentPickedHandler(int FragmentID)
{
    CollectedCount++;

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Orange,
            FString::Printf(TEXT("Ensamblador: recib\u00ed fragmento %d (%d/%d)"),
                FragmentID, CollectedCount, RequiredFragments));
    }

    // si ya juntamos todos, se activa
    if (CollectedCount >= RequiredFragments)
    {
        bIsActive = true;

        if (ActiveMaterial)
        {
            MeshComponent->SetMaterial(0, ActiveMaterial);
        }

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green,
                TEXT("\u00a1ENSAMBLADOR ACTIVADO! Interactu\u00e1 para reconstruir el artefacto"));
        }
    }
}

void AArtifactAssembler::Interact_Implementation(AActor* Interactor)
{
    if (!bIsActive)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow,
                TEXT("Primero necesitas recolectar todos los fragmentos"));
        }
        return;
    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Magenta,
            TEXT("Reconstruyendo artefacto... espera 3 segundos"));
    }

    // Iniciamos el timer
    GetWorldTimerManager().SetTimer(
        TimerHandleFinalAction,
        this,
        &AArtifactAssembler::FinalAction,
        3.0f,
        false
    );
}

void AArtifactAssembler::FinalAction()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
            TEXT("\u00a1ARTEFACTO RECONSTRUIDO!"));
    }

    // Spawnea el artefacto final si hay uno asignado
    if (ArtifactToSpawn)
    {
        GetWorld()->SpawnActor<AActor>(
            ArtifactToSpawn,
            GetActorLocation() + FVector(0, 0, 100),
            GetActorRotation()
        );
    }

    // Se destruye el ensamblador 
    Destroy();
}