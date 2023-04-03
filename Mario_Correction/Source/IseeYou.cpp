// Fill out your copyright notice in the Description page of Project Settings.


#include "IseeYou.h"
#include "Utils.h"

// Sets default values
AIseeYou::AIseeYou()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CREATE(UStaticMeshComponent, "Mesh");
}
void AIseeYou::BeginPlay()
{
	Super::BeginPlay();
	
}
void AIseeYou::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DRAW_LINE(GetActorLocation(), GetActorLocation() + GetActorForwardVector().GetSafeNormal() * 200, FColor::Red, 5);
}

