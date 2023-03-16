// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShip.h"
#include "InputUtils.h"
#include "Util.h"

ASpaceShip::ASpaceShip()
{

	PrimaryActorTick.bCanEverTick = true;
	shipMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = shipMesh;
	springArm = CreateDefaultSubobject<USpringArmComponent>("CameraAnchor");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);
	//
	customTimer = CreateDefaultSubobject<UTimerComponent>("Timer");
	AddOwnedComponent(customTimer); // équivalent du setupAttachment mais pour les components

}


void ASpaceShip::BeginPlay()
{
	Super::BeginPlay();
	InitShip();
}
void ASpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddFloatingBehaviour();
	DRAW_LINE(GetActorLocation() + shipVelocity * 100, GetActorLocation(), FColor::Cyan, 2);
	DRAW_SPHERE(GetActorLocation() + shipVelocity * 100, 80, FColor::Cyan, 3);
	//DRAW_SHPERE_DEF(GetActorLocation() + shipVelocity, 4, 30, FColor::Cyan, 2);
	RotateAroundCamera();
}


void ASpaceShip::InitShip()
{
	InitInput();
	GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
	if (!currentGalaxy)
		return;
	//currentGalaxy->InitGalaxy(this);
	if (customTimer)
	{
		BIND(customTimer->OnTimerEnd(), this, &ASpaceShip::PassiveModeEnable);
		customTimer->StartTimer();
	}
	if (springArm)
		initRotation = springArm->GetRelativeRotation();
	BIND(onShipMovement, this, &ASpaceShip::MovingDetection);
	BIND(onShipAxis, this, &ASpaceShip::PassiveModeDisable);
	BIND(onShipAxis, customTimer, &UTimerComponent::ResetTimer);
	springSnapshot = FPassiveArmeMemory(springArm);
}
void ASpaceShip::InitInput()
{
	BIND_AXIS(VERTICAL, this, &ASpaceShip::MoveForward);
	BIND_AXIS(HORIZONTAL, this, &ASpaceShip::RotateShip);
	BIND_AXIS(VIEW, this, &ASpaceShip::AddPitch);
}
void ASpaceShip::MoveForward(float _axis)
{;
	INVOKE(onShipMovement, _axis);
	forwardVelocity = FMath::Lerp(forwardVelocity, FMath::Abs(_axis), DELTATIME * fwdWeight);
	shipVelocity = GetActorForwardVector() * forwardVelocity;
	AddActorWorldOffset(shipVelocity);
}
void ASpaceShip::RotateShip(float _axis)
{
	INVOKE(onShipMovement, _axis);
	if (shipVelocity.Size() == 0)
		return;
	rotateAxis = FMath::Lerp(rotateAxis, _axis, DELTATIME * rotateWeight);
	AddActorLocalRotation(FRotator(0, rotateAxis * 10 * DELTATIME, 0));
	const FRotator _bank = FMath::Lerp(GetActorRotation(), FRotator(0, GetActorRotation().Yaw, bankAngle * rotateAxis), DELTATIME);
	SetActorRotation(_bank);

}
void ASpaceShip::AddFloatingBehaviour()
{
	if (shipVelocity.Size() > 0.1f)
		return;
	SetActorLocation(GetActorLocation() + FVector(0, 0, FMath::Sin(WORLD->TimeSeconds) * DELTATIME * 10));
}
void ASpaceShip::SetRandomPassiveValue()
{
	const float _h = passiveModeSetting.GetRandomArmHeight();
	springArm->TargetArmLength = passiveModeSetting.GetRandomArmHeight();
	springArm->TargetOffset += FVector(0, 0, _h);
}
void ASpaceShip::AddPitch(float _axis)
{
	INVOKE(onShipMovement, _axis);
	pitchAxis = FMath::Lerp(pitchAxis, _axis, DELTATIME * pitchWeight);
	AddActorLocalRotation(FRotator(pitchAxis, 0, 0));
}
void ASpaceShip::RotateAroundCamera()
{
	if (!springArm || !passiveModeEnable)
		return;
	springArm->AddRelativeRotation(FRotator(0, passiveModeYawSpeed * DELTATIME, 0));
}
void ASpaceShip::PassiveModeEnable()
{
	passiveModeEnable = true;
	SetRandomPassiveValue();
}
void ASpaceShip::PassiveModeDisable()
{
	passiveModeEnable = false;
	springSnapshot.ResetValues(springArm);
}
void ASpaceShip::MovingDetection(float _value)
{
	isMoving = FMath::Abs(_value) > 0;
	if (isMoving)
		INVOKE(onShipAxis);
}
void ASpaceShip::ResetCameraLocation(const FVector _maxDistance)
{
	if (!springArm || !passiveModeEnable)
		return;
	springArm->SetRelativeRotation(LERP(springArm->GetRelativeRotation(), FRotator(0), DELTATIME * passiveModeResetSpeed));
	//springArm->SetRelativeLocation(LERP(springArm->GetRelativeLocation(), ))
}
