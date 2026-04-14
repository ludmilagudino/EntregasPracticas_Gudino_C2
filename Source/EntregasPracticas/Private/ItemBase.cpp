// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemBase.h"
#include "Components/StaticMeshComponent.h"

AItemBase::AItemBase()
{
    PrimaryActorTick.bCanEverTick = false;

    // Creamos la malla y la usamos como raíz del actor
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
}

void AItemBase::BeginPlay()
{
    Super::BeginPlay();
}

void AItemBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Versión vacía en la clase base, los hijos la sobreescriben con su lógica
void AItemBase::Interact_Implementation(AActor* Interactor)
{
    UE_LOG(LogTemp, Warning, TEXT("ItemBase: Interact base llamado."));
}