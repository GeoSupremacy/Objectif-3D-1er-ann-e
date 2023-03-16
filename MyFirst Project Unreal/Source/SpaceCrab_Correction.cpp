// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCrab_Correction.h"
#include "InputUtils.h"
#include "Util.h"

#pragma region Constructor
ASpaceCrab_Correction::ASpaceCrab_Correction() 
{
	PrimaryActorTick.bCanEverTick = true;
	shipMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = shipMesh;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);
	//
	customTimer = CreateDefaultSubobject<UTimerComponent>("Timer");
	AddOwnedComponent(customTimer);
	
}
#pragma endregion Constructor
#pragma region UE_METHODS
void ASpaceCrab_Correction::BeginPlay()
{
	Super::BeginPlay();
	InitShip();
	SetupInput();
}
void ASpaceCrab_Correction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddFloatingBehaviour();
	DrawDebug();
	RotatorAroundCamera();
	ResetCameraRotation();
	//CheckActive();
	//UpdateTimer();
	
}
#pragma endregion UE_METHODS
#pragma region Ascenseur
void ASpaceCrab_Correction::SetupInput()
{
	
	BIND_AXIS(HORIZONTAL, this, &ASpaceCrab_Correction::SetHorizontal);
	BIND_AXIS(VERTICAL, this, &ASpaceCrab_Correction::SetVertical);
	BIND_AXIS(ROTATE, this, &ASpaceCrab_Correction::SetRotation);
	BIND_AXIS(SCALE, this, &ASpaceCrab_Correction::SetDynamicScale);
	BIND_AXIS(ALTITUDE, this, &ASpaceCrab_Correction::SetAltitude);
	BIND_AXIS(VIEW, this, &ASpaceCrab_Correction::AddPitch);
	BIND_ACTION(RESPAWN, EInputEvent::IE_Pressed, this, &ASpaceCrab_Correction::Respawn);
	
}
void ASpaceCrab_Correction::SetHorizontal(float _axis)
{
	//INVOKE(onShipMovement, _axis);
	if (!canMove)
		return;
	forwardVelocity = FMath::Lerp(forwardVelocity, FMath::Abs(_axis), DELTATIME * mase);//
	shipVelocity = GetActorForwardVector() * forwardVelocity;
	AddActorWorldOffset(shipVelocity);

	//const FVector _direction = GetActorForwardVector().GetSafeNormal() * horizontaleSpeed;
	//SetActorLocation(GetActorLocation() + (_direction * _axis));
}
void ASpaceCrab_Correction::SetVertical(float _axis)
{
	//INVOKE(onShipMovement, _axis);
	if (!canMove)
		return;
	forwardVelocity = FMath::Lerp(forwardVelocity, _axis, DELTATIME * mase);//
	shipVelocity = GetActorRightVector() * forwardVelocity;
	AddActorWorldOffset(shipVelocity);

	//const FVector _direction = GetActorRightVector().GetSafeNormal() * verticaleSpeed;
	//SetActorLocation(GetActorLocation() + (_direction * _axis));
}
void ASpaceCrab_Correction::SetAltitude(float _axis)
{
	//INVOKE(onShipMovement, _axis);
	if (!canMove)
		return;
	forwardVelocity = FMath::Lerp(forwardVelocity, _axis, DELTATIME * mase);//
	shipVelocity = GetActorUpVector() * forwardVelocity;
	AddActorWorldOffset(shipVelocity);
	//const FVector _direction = GetActorUpVector().GetSafeNormal() * altitudeSpeed;
	//SetActorLocation(GetActorLocation() + (_direction * _axis));
}
void ASpaceCrab_Correction::SetRotation(float _axis)
{
	//INVOKE(onShipMovement, _axis);
	if (!canRotate)
		return;
	//if (shipVelocity.Size() == 0)
		//return;
	rotateAxis = FMath::Lerp(rotateAxis, _axis, DELTATIME * rotateWeight);
	AddActorLocalRotation(FRotator(0, rotateAxis * 10 * DELTATIME, 0));
	const FRotator _bank = FMath::Lerp(GetActorRotation(), FRotator(0, GetActorRotation().Yaw, bankAngle * rotateAxis), DELTATIME);
	SetActorRotation(_bank);
	//AddActorLocalRotation(FRotator(0, rotateSpeed * -_axis * DELTATIME, 0));
}
void ASpaceCrab_Correction::SetScale(float _axis){    }
#pragma endregion Ascenseur
#pragma region CUSTOM_METHODS
UFUNCTION() void ASpaceCrab_Correction::StopRotation()
{
	return SetCanRotate(false);
}
UFUNCTION() void ASpaceCrab_Correction::StopMovement()
{
	return SetCanMove(false);
}
UFUNCTION() void ASpaceCrab_Correction::StopScaling()
{
	return SetCanScaling(false);
}
UFUNCTION() void ASpaceCrab_Correction::StopCamera()
{
	return SetCanCamera(false);
}
void ASpaceCrab_Correction::View(float _axis) { if (!canCamera) return; }
void ASpaceCrab_Correction::InitShip()
{
	GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
	initScale = GetActorScale();//
	initLocation = GetActorLocation();
	initRotation = GetActorRotation();
	if (!currentGalaxy)
		return;
	currentGalaxy->InitGalaxy(this);
	if (customTimer)
	{
		customTimer->OnTimerEnd().AddDynamic(this,
			&ASpaceCrab_Correction::PassiveModeEnable);
		customTimer->StartTimer();
	}
	//BIND(onShipMovement, this, &ASpaceCrab_Correction::MovingDetection);
	//BIND(onShipAxis, this, &ASpaceCrab_Correction::PassiveModeDisable);
	//BIND(onShipAxis, customTimer.Get(), &UTimerComponent::ResetTimer);
	//onShipAxis.AddDynamic(customeTimer.get(), &ASpaceCrab_Correction::ResetTimer);

}
void ASpaceCrab_Correction::SetDynamicScale(float _axis){      }
void ASpaceCrab_Correction::DrawDebug()
{
	if (!canSeeAxe)
		return;
	DRAW_SPHERE(GetActorLocation(), 120, FColor::Red, 5);
	DRAW_LINE(GetActorLocation() + shipVelocity, GetActorLocation(), FColor::Cyan, 2);
	DRAW_SPHERE_DEF(GetActorLocation() + shipVelocity,50,4, FColor::Cyan, 2);
}
void ASpaceCrab_Correction::AddFloatingBehaviour()
{
	if (shipVelocity.Size() > 0.1f)
		return;
	SetActorLocation(GetActorLocation() + FVector(0, 0, FMath::Sin(WORLD->TimeSeconds) * DELTATIME * 10));
}
void ASpaceCrab_Correction::AddPitch(float _axis)
{
	//INVOKE(onShipMovement, _axis);
	pitchAxis = FMath::Lerp(pitchAxis, _axis, DELTATIME * pitchWeight);
	AddActorLocalRotation(FRotator(pitchAxis, 0, 0));
}
#pragma endregion CUSTOM_METHODS
#pragma region PassiveMode
void ASpaceCrab_Correction::RotatorAroundCamera() {
	if (!springArm || !passiveModeEnable)
		return;
	springArm->AddRelativeRotation(FRotator(0, passiveModeyawSpeed *DELTATIME, 0));
}
void ASpaceCrab_Correction::ResetCameraRotation()
{
	if (!springArm || passiveModeEnable)
		return;
	springArm->SetRelativeRotation(LERP(springArm->GetRelativeRotation(), FRotator(0), DELTATIME * 5));
}
UFUNCTION() void ASpaceCrab_Correction::PassiveModeEnable()
{
	passiveModeEnable = true;
}
void ASpaceCrab_Correction::PassiveModeDisable()
{
	passiveModeEnable = false;
}
UFUNCTION() void ASpaceCrab_Correction::MovingDetection(float _value)
{
	isMoving = FMath::Abs(_value) > 0;
	if (!isMoving)
		return;
		//INVOKE(onShipAxis);
}
#pragma endregion PassiveMode
/*
void ASpaceCrab_Correction::UpdateTimer()
{
	if (timerStarted)
	{
		timer++;
		LOG_W(LogTemp, "Timer is %f", timer);
	}
	else
		timer = 0;
	if (GetEndTimer())
	{
		timerStarted = false;
		LOG_W(LogTemp, "TimerGone");
	}
}
void ASpaceCrab_Correction::CheckActive()
{
	if (!isActive)
	{
		timerStarted = true;
		LOG_W(LogTemp, "Not Active");
	}
	else
		LOG_W(LogTemp, "Active");

}
*/

