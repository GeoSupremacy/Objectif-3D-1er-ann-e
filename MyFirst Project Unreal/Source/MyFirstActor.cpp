// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstActor.h"
#include "Util.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	InitObject();
	
}

#pragma region CUSTOM_METHODS
void AMyFirstActor::MoveToLocation(const FVector& _target)
{
	originLocation = _target;
	MoveToLocation();
}
void AMyFirstActor::MoveToLocation()
{
	if (!isInstanceSpawn)
		return;
	SetActorLocation(GetSpawnLocation());
	/*
	LOG("toto");
	LOG_W("toto");
	LOG_E("toto");
	/*LOG_SCREEN(5, FColor::Red, "Toto %s", *GetActorLocation().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString("Toto"));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString("Toto"));
	//UE_LOG(LogTemp, Warning, TEXT(" origine"), );*/
}
void AMyFirstActor::MoveToLocation_Interp(const float& _speed)
{
	if (!canMove)
		return;
	//GetWorld()->DeltaTimeSeconds;
	const FVector _result = FMath::VInterpConstantTo(GetActorLocation(), GetSpawnLocation(), DELTATIME, _speed);
	SetActorLocation(_result);
}
FVector AMyFirstActor::GetFromPoint() const
{
	return GetActorLocation();
}
void AMyFirstActor::InitObject()
{
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
	mesh->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("'/Engine/BasicShapes/BasicShapesMaterial.BasicShapesMaterial'")));
}
void AMyFirstActor::DrawDebug()
{
	if (!drawDebug)
		return;
	DRAW_SPHERE(GetActorLocation(), 100, FColor::Green, 2);
	DRAW_SPHERE(GetSpawnLocation(), 100, FColor::Yellow, 2);
	DRAW_BOX(fromLocation, FVector(100), FColor::Magenta, 2);
	DRAW_LINE(GetSpawnLocation(), fromLocation, FColor::Red, 2);
	DRAW_LINE(GetSpawnLocation(), GetActorLocation(), FColor::Red, 2);
	DRAW_TEXT(fromLocation, *fromLocation.ToCompactString(), FColor::Red, 1.1f);
	//DrawDebugSphere(_world, GetActorLocation(), 100, 20, FColor::Green);
	//DrawDebugLine(_world, originLocation, GetActorLocation(), FColor::Red);
	//DrawDebugSphere(_world, fromLocation, 100, 20, FColor::Magenta);
	//DrawDebugString(_world, fromLocation, *fromLocation.ToCompactString()); //Quand on est en possession FlushDebugStrings(_world);
}
#pragma endregion CUSTOM_METHODS
#pragma region UE_METHODS
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();
	if (isControledBye)
		return;
	//canMove = !;
		isInstanceSpawn;
	fromLocation = GetFromPoint();
	MoveToLocation();
}
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
	MoveToLocation_Interp(speed);
}
#pragma endregion UE_METHODS
