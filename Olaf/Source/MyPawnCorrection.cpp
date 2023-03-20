// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawnCorrection.h"
#include "Utils.h"
#include "InputUtils.h"


AMyPawnCorrection::AMyPawnCorrection()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CREATE_TO(UStaticMeshComponent, "Mesh");
	arm = CREATE_TO(USpringArmComponent, "ARM");
	camera = CREATE_TO(UCameraComponent, "Camera");
	RootComponent = mesh;
	//mesh->SETSTATIC_CUBE;
	ATTACH_TO(arm, RootComponent);
	ATTACH_TO(camera, arm);
	movement = CREATE_TO(UFloatingPawnMovement, "Movement");
	AddOwnedComponent(movement);
}
void AMyPawnCorrection::BeginPlay()
{
	Super::BeginPlay();
	//FPC->SetViewTarget(this);
}
void AMyPawnCorrection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	DRAW_SPHERE((GetActorLocation() + GetVelocity().GetClampedToMaxSize(100)), 5, FColor::Yellow, 2);
	DRAW_LINE(GetActorLocation(), (GetActorLocation() + GetVelocity().GetClampedToMaxSize(100)), FColor::Yellow, 2);
}
void AMyPawnCorrection::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	BIND_AXIS_WITH_INPUT(VERTICAL, this, &AMyPawnCorrection::MoveForward);
	BIND_AXIS_WITH_INPUT(HORIZONTAL, this, &AMyPawnCorrection::RollMovement);
	BIND_AXIS_WITH_INPUT(HORIZONTAL, this, &AMyPawnCorrection::YawMovement);

	
}

void AMyPawnCorrection::MoveForward(float _axis)
{
	if (_axis < 0)
		return;
	settings.forwardAxis = FMath::Lerp(settings.forwardAxis, _axis, DELTATIME * (1 / settings.forwardWeight));
	AddMovementInput(GetActorForwardVector(), settings.forwardAxis);
}
void AMyPawnCorrection::RollMovement(float _axis)
{
	settings.rollAxis = FMath::Lerp(settings.rollAxis, _axis, DELTATIME * (1 / settings.rollWeight));
	SetActorRotation(FRotator(0, 0, settings.maxAngle * settings.rollAxis));
}
void AMyPawnCorrection::YawMovement(float _axis)
{
	settings.yawAxis = FMath::Lerp(settings.yawAxis, _axis, DELTATIME * (1 / settings.yawdWeight));
	AddControllerYawInput(settings.yawAxis);
}

