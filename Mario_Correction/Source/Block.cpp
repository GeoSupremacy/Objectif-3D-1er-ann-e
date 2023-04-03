// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"

// Sets default values
ABlock::ABlock()
{
 	
	PrimaryActorTick.bCanEverTick = false;
	meshBlock =CREATE(UStaticMeshComponent,"MeshBlock");
	RootComponent = meshBlock;
	downTrigger = CREATE(UBoxComponent, "D_Trigger");
	ATTACH_TO(downTrigger, RootComponent);
}
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void ABlock::Init()
{
	if (!downTrigger)
		return;
	downTrigger->OnComponentBeginOverlap.AddDynamic(this, &ABlock::OnDownTrigger);
}
void ABlock::DownBehaviour(AMario* _Mario)
{
}

UFUNCTION() void ABlock::OnDownTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMario* _mario = Cast<AMario>(OtherActor);
	if (!_mario)
		return;
	DownBehaviour(_mario);
}

