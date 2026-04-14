// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "DamageItem.generated.h"

UCLASS()
class ENTREGASPRACTICAS_API ADamageItem : public AItemBase
{
    GENERATED_BODY()

public:
    ADamageItem();

    // Cantidad de daño que aplica al jugador al interactuar
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
    float DamageAmount;

    virtual void Interact_Implementation(AActor* Interactor) override;
};