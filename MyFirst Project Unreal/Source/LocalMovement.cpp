// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalMovement.h"
#include "Util.h"

#pragma region Constructor
ALocalMovement::ALocalMovement()
{

	PrimaryActorTick.bCanEverTick = true;
	local = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = local;
	InitObject();
}
#pragma endregion Constructor
#pragma region UE_METHODS
void ALocalMovement::BeginPlay()
{
	Super::BeginPlay();
	initScale = GetActorScale();
	oneEndTimer.AddDynamic(this, &ALocalMovement::StopMovement);
	oneEndTimer.AddDynamic(this, &ALocalMovement::StopRotation);

}
void ALocalMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		DrawDebugAxis();
		Move();
		Rotation();
		Scaling();
		UpdateTimer(timer);
		Breath(scaleSpeed);
		DrawMovement();
}
#pragma endregion UE_METHODS
#pragma region CUSTOM_METHODS
void ALocalMovement::InitObject()
{
	local->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
	local->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("Material'/Engine/EditorMaterials/Cloth/CameraLitDoubleSided.CameraLitDoubleSided'")));
}
void ALocalMovement::DrawDebugAxis()
{
	if (!CanSeeAxe)
		return;

		const FVector _location = GetActorLocation();
		const FVector _right = GetActorRightVector().GetSafeNormal(),
			_fwd = GetActorForwardVector().GetSafeNormal(),
			_up = GetActorUpVector().GetSafeNormal();

		//FWD
		DRAW_LINE(_location, _location + _fwd * 200, FColor::Red, 2);
		DRAW_SPHERE(_location + _fwd * 100, 20, FColor::Red, 2);

		//RIGHT
		DRAW_LINE(_location, _location + _right * 200, FColor::Red, 2);
		DRAW_SPHERE(_location + _right * 100, 20, FColor::Green, 2);

		//UP
		DRAW_LINE(_location, _location + _up * 200, FColor::Red, 2);
		DRAW_SPHERE(_location + _up * 200, 20, FColor::Blue, 2);
}
void ALocalMovement::Move()
{
	if (!canMove)
		return;
	MoveOneDirection(FVector(GetDistanceRight(), 0, 0), moveSpeed);
	MoveOneDirection(FVector(0, GetDistanceUp(), 0), moveSpeed);
	MoveOneDirection(FVector(0, 0, GetDistanceForward()), moveSpeed);
}
UFUNCTION() void ALocalMovement::StopRotation()
{
	SetCanRotate(false);
}
UFUNCTION() void ALocalMovement::StopMovement()
{
	SetCanMove(false);
}
UFUNCTION() void ALocalMovement::StopScaling()
{
	return SetCanScaling(false);
}
void ALocalMovement::Rotate(const FRotator &_rotation, const float _speed)
{
	
	const FRotator _nexRotation = GetActorRotation()+ _rotation* _speed* DELTATIME;
	SetActorRotation(_nexRotation);
}
void ALocalMovement::Scale(const FScale2D& _scaling, const float _speed)
{
	const FScale2D _nextScaling;
}
void ALocalMovement::Rotation()
{
	if (!canRotate)
		return;
	Rotate(FRotator(GetDistanceRight(), 0, 0), rotateSpeed);
	Rotate(FRotator(0, GetDistanceUp(), 0), rotateSpeed);
	Rotate(FRotator(0, 0, GetDistanceForward()), rotateSpeed);
}
void ALocalMovement::Scaling()
{
}
void ALocalMovement::UpdateTimer(float& _timer)
{
	if (!timerStarted)
		return;
	_timer += DELTATIME;
	if (GetEndTimer())
	{
		oneEndTimer.Broadcast();
		timerStarted = false;
	}
}
void ALocalMovement::DrawMovement()
{
	if (!CanSeeAxe)
		return;
	DRAW_TEXT(GetActorLocation(), FString::Printf(TEXT("%d s /%d s "), (int)timer, (int)maxTimeDelay), FColor::White, 2);
	const FColor _lerpColor = LERP_COLOR(FColor::Red, FColor::Green, GetTimerProgress());
	DRAW_BOX(GetActorLocation() + GetActorUpVector() * 300, FVector(50) * GetTimerProgress(), _lerpColor, 2);
	DRAW_LINE(GetActorLocation(), GetActorLocation() + GetActorUpVector() * 300, FColor::White, 2);
}
void ALocalMovement::Breath(const float& _value)
{
	if (!canScale)
		return;
	const float _breathValue = FMath::Sin(WORLD->TimeSeconds* _value);
	SetActorScale3D(initScale + (initScale * FMath::Abs(_breathValue)));
}
void ALocalMovement::MoveOneDirection(const FVector& _direction, const float& _speed)
{
	AddActorLocalOffset((_direction.GetSafeNormal() * _speed) * DELTATIME);
}
#pragma endregion CUSTOM_METHODS
