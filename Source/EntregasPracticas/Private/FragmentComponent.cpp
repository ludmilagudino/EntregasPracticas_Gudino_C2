// Fill out your copyright notice in the Description page of Project Settings.

#include "FragmentComponent.h"

UFragmentComponent::UFragmentComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    TotalFragmentsRequired = 3; 
}

void UFragmentComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UFragmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UFragmentComponent::AddFragment(int FragmentID)
{
    CollectedFragments.Add(FragmentID);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan,
            FString::Printf(TEXT("Mochila: fragmento %d agregado (%d/%d)"),
                FragmentID, CollectedFragments.Num(), TotalFragmentsRequired));
    }
}

bool UFragmentComponent::IsArtifactComplete() const
{
    return CollectedFragments.Num() >= TotalFragmentsRequired;
}