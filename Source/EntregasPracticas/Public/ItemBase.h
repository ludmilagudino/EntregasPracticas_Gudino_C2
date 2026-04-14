// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "ItemBase.generated.h"

UCLASS()
class ENTREGASPRACTICAS_API AItemBase : public AActor, public IInteractable
{
    GENERATED_BODY()

public:
    AItemBase();

protected:
    virtual void BeginPlay() override;

    // Malla 3D del ítem para que se vea en el mundo
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
    class UStaticMeshComponent* MeshComponent;

public:
    virtual void Tick(float DeltaTime) override;

    // Implementación de Interact() de la Interface IInteractable 
    virtual void Interact_Implementation(AActor* Interactor) override;
};