// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible.h"
#include "Utils.h"

// Sets default values
ACollectible::ACollectible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	trigger = CREATE(UBoxComponent, "Trigger");
	RootComponent = trigger;
	meshCollector = CREATE(UStaticMeshComponent, "Mesh");
	ATTACH_TO(meshCollector, RootComponent);
}
void ACollectible::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACollectible::NotifyActorBeginOverlap(AActor* _other)
{
	AMario* _mario = Cast <AMario> (_other);
	if (!_mario)
		return;
	CollectibleBehaviour(_mario);
}

void ACollectible::CollectibleBehaviour(AMario* _mario)
{
}


