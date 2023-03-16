// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCrab.h"
#include "Util.h"
#include "InputUtils.h"


#pragma region Constructor
ASpaceCrab::ASpaceCrab()
{
	
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	
}
#pragma endregion Constructor
#pragma region UE_METHODS
void ASpaceCrab::BeginPlay()
{
	Super::BeginPlay();
	initScale = GetActorScale();//
	initLocation = GetActorLocation();
	SetupInput();
}
void ASpaceCrab::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
	PlaneteApproch();
}
#pragma endregion UE_METHODS
#pragma region Ascenseur
void ASpaceCrab::SetupInput()
{
	BIND_AXIS(HORIZONTAL, this, &ASpaceCrab::SetHorizontal);
	BIND_AXIS(VERTICAL, this, &ASpaceCrab::SetVertical);
	BIND_AXIS(ROTATE, this, &ASpaceCrab::SetRotation);
	BIND_AXIS(SCALE, this, &ASpaceCrab::SetDynamicScale);
	BIND_ACTION(RESPAWN, EInputEvent::IE_Pressed, this, &ASpaceCrab::Respawn);
	BIND_AXIS(ALTITUDE, this, &ASpaceCrab::SetAltitude);
}
void ASpaceCrab::SetHorizontal(float _axis)
{
	if(!canMove)
		return;
	const FVector _direction = GetActorForwardVector().GetSafeNormal() * horizontaleSpeed;
	SetActorLocation(GetActorLocation() + (_direction * _axis));
}
void ASpaceCrab::SetVertical(float _axis)
{
	if (!canMove)
		return;
	const FVector _direction = GetActorRightVector().GetSafeNormal() * verticaleSpeed;
	SetActorLocation(GetActorLocation() + (_direction * _axis));
}
void ASpaceCrab::SetRotation(float _axis)
{
	if (!canRotate)
		return;
	AddActorLocalRotation(FRotator(0, rotateSpeed * -_axis * DELTATIME, 0));
}
void ASpaceCrab::SetScale(float _axis) {    }
void ASpaceCrab::SetAltitude(float _axis)
{
	if (!canMove)
		return;
	const FVector _direction = GetActorUpVector().GetSafeNormal() * altitudeSpeed;
	SetActorLocation(GetActorLocation() + (_direction * _axis));
}
#pragma endregion Ascenseur
#pragma region CUSTOM_METHODS
UFUNCTION() void ASpaceCrab::StopRotation()
{
	return SetCanRotate(false);
}
UFUNCTION() void ASpaceCrab::StopMovement()
{
	return SetCanMove(false);
}
UFUNCTION() void ASpaceCrab::StopScaling()
{
	return SetCanScaling(false);
}
void ASpaceCrab::SetDynamicScale(float _axis){   }
void ASpaceCrab::DrawDebug()
{
	
	if (!canSeeAxe)
		return;
	DRAW_SPHERE(GetActorLocation(), 120, FColor::Red, 5);
	//DRAW_LINE(GetActorLocation(), 120, FColor::Green, 2);
	
	for (auto collect :Collector)
	{
		DRAW_SPHERE(collect->GetActorLocation(), 120, FColor::Yellow, 5);
		DRAW_LINE(GetActorLocation(), collect->GetActorLocation(), FColor::Green, 2);
	}
	
}
void ASpaceCrab::PlaneteApproch()
{
	for (auto collect : Collector)
		collect->SetActorScale3D(GetActorLocation()/100);
	
}
#pragma endregion CUSTOM_METHODS
