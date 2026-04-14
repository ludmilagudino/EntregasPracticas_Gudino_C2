// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FragmentComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ENTREGASPRACTICAS_API UFragmentComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UFragmentComponent();

protected:
    virtual void BeginPlay() override;

    // Lista de ids de los fragmentos ya recolectados
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fragments")
    TArray<int> CollectedFragments;

    // cuantos fragmentos hay en total para completar el artefacto (configurable en el editor)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fragments")
    int TotalFragmentsRequired;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // Función para agregar un fragmento recolectado a la lista
    UFUNCTION(BlueprintCallable, Category = "Fragments")
    void AddFragment(int FragmentID);

    // Función para verificar si ya juntamos todos los fragmentos
    UFUNCTION(BlueprintCallable, Category = "Fragments")
    bool IsArtifactComplete() const;
};