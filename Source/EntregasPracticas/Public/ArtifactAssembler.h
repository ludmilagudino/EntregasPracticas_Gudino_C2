// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "ArtifactAssembler.generated.h"

UCLASS()
class ENTREGASPRACTICAS_API AArtifactAssembler : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArtifactAssembler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // Malla visual del ensamblador
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Assembler")
    class UStaticMeshComponent* MeshComponent;

    // fragmentos recolectados
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Assembler")
    int CollectedCount;

    // Cuantos necesita
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Assembler")
    int RequiredFragments;

    // esta activo?
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Assembler")
    bool bIsActive;

    // materiales para cambiar visualmente según el estado (se asignan en el editor)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assembler")
    class UMaterialInterface* InactiveMaterial;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assembler")
    class UMaterialInterface* ActiveMaterial;

    // actor que se spawnea como "artefacto reconstruido"
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assembler")
    TSubclassOf<AActor> ArtifactToSpawn;

    // handle del timer
    FTimerHandle TimerHandleFinalAction;

    // Funcion que responde al delegado de cada FragmentItem
    UFUNCTION()
    void OnFragmentPickedHandler(int FragmentID);

    // Funcion que se ejecuta cuando el timer termina
    UFUNCTION()
    void FinalAction();

public:
    virtual void Interact_Implementation(AActor* Interactor) override;
};