// Fill out your copyright notice in the Description page of Project Settings.


#include "Galaxy.h"
#include "Util.h"
#include "SpaceCrab_Correction.h"


#pragma region Constructor
AGalaxy::AGalaxy()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}
#pragma region Constructor



void AGalaxy::BeginPlay()
{
	Super::BeginPlay();
	InitGalaxy(currentShip);
}
void AGalaxy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugGalaxy();
	UpdatePlanetSize(currentShip);
}

void AGalaxy::DrawDebugGalaxy()
{
	if (!currentShip)
		return;
	for (APlanete* _planet : allPlanets)
	{
		if (!_planet)
			continue;
		const FVector _ploc = _planet->GetActorLocation(),
					 _shipLocation = currentShip->GetActorLocation();

		DRAW_BOX(_ploc, FVector(100), FColor::Green, 2);
		DRAW_LINE(_ploc, GetActorLocation(), FColor::Green, 2);
		DRAW_LINE(_ploc, _shipLocation, FColor::Red, 2);
		DRAW_TEXT(FMath::Lerp(_ploc, _shipLocation, 0.5f), FString::Printf(TEXT("%f/ùf"), _planet->GetCurrentDistanceTo(_shipLocation), _planet->GetMaxDistance()), FColor::White, 1.2f);
	}

	DRAW_TEXT(GetActorLocation(), FString::Printf(TEXT("Galaxy center %s"), TO_CHAR_STR(GetActorLocation())), FColor::White, 1.f);
	DRAW_BOX(GetActorLocation(), FVector(20), FColor::Yellow, 2);
}
void AGalaxy::UpdatePlanetSize(const ASpaceCrab_Correction* _ship)
{
	if (!_ship)
		return;
	for (APlanete* _planet : allPlanets)
	{
		if (!_planet)
			continue;
		_planet->UpdateSize(_ship->GetActorLocation());
	}
}
void AGalaxy::InitGalaxy(ASpaceCrab_Correction* _ship)
{
	//GetWorld()->GetFirstPlayerController()->SetViewTarget(this);//sur joueur par rapport à la galaxie
	if (!currentShip)
		return;
	currentShip = _ship;
	for (APlanete* _planet : allPlanets)
	{
		if (!_planet)
			continue;
		_planet->SetInitDistance(_ship->GetActorLocation());
	}
}
