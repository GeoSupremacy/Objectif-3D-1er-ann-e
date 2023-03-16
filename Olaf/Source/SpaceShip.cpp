// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShip.h"
#include "InputUtils.h"
#include "Utils.h"

// Sets default values
ASpaceShip::ASpaceShip()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CREATE_TO(UStaticMeshComponent, "mesh");
	RootComponent = mesh;
	pawn = CREATE_TO(AMyFirstPawn, "Pawn");
	movement = CREATE_TO(UInputComponent, "Movement");
	AddOwnedComponent(movement);
	
}
void ASpaceShip::BeginPlay()
{
	Super::BeginPlay();
	FPC->SetViewTarget(this);
	
}
void ASpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!movement)
		return;
	pawn->SetupPlayerInputComponent(PLAYER);
}

