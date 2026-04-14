// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageItem.h"
#include "EntregasPracticasCharacter.h"

ADamageItem::ADamageItem()
{
    DamageAmount = 10.0f;
}

void ADamageItem::Interact_Implementation(AActor* Interactor)
{
    AEntregasPracticasCharacter* Character = Cast<AEntregasPracticasCharacter>(Interactor);
    if (Character)
    {
        Character->TakeDamageAmount(DamageAmount);
    }

    Destroy();
}