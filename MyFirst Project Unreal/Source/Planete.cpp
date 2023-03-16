// Fill out your copyright notice in the Description page of Project Settings.


#include "Planete.h"
#include "Util.h"


// Sets default values
APlanete::APlanete()
{
	PrimaryActorTick.bCanEverTick = true;
	planetMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = planetMesh;
}

void APlanete::BeginPlay()
{
	Super::BeginPlay();
	InitObject();
}
void APlanete::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//DRAW_SPHERE(GetActorLocation() + 20 * 150, 20, FColor::Yellow, 5);
}

//
void APlanete::InitObject()
{
	const float _randSizeScale = useRandomScale? FMath::FRandRange(0.5f, 5) : 1;
	initScale = GetActorScale() * _randSizeScale;
	SetActorScale3D(initScale);
}
void APlanete::ShapeApproch()
{
	//SetActorScale3D(initScale);
}
//
void APlanete::UpdateSize(const FVector& _location)
{
	const float _currentDistance = GetCurrentDistanceTo(_location);
	SetActorScale3D(initScale * (1-(_currentDistance/initDistance)));
}

