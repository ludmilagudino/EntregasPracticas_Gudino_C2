#include "FragmentItem.h"
#include "EntregasPracticasCharacter.h"
#include "FragmentComponent.h"

AFragmentItem::AFragmentItem()
{
    FragmentID = 0;
}

void AFragmentItem::Interact_Implementation(AActor* Interactor)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan,
            FString::Printf(TEXT("Fragmento %d recolectado!"), FragmentID));
    }

    // agregar  el fragmento al componente del personaje 
    AEntregasPracticasCharacter* Character = Cast<AEntregasPracticasCharacter>(Interactor);
    if (Character && Character->FragmentComp)
    {
        Character->FragmentComp->AddFragment(FragmentID);
    }

    // disparar el delegado para avisar al ArtifactAssembler
    OnFragmentPicked.Broadcast(FragmentID);

    Destroy();
}