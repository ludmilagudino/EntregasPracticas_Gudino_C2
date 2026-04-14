// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "FragmentItem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFragmentPicked, int, FragmentID);

UCLASS()
class ENTREGASPRACTICAS_API AFragmentItem : public AItemBase
{
    GENERATED_BODY()

public:
    AFragmentItem();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fragment")
    int FragmentID;

    UPROPERTY(BlueprintAssignable, Category = "Fragment")
    FOnFragmentPicked OnFragmentPicked;

    virtual void Interact_Implementation(AActor* Interactor) override;
};