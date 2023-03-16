// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstPawn.h"
#include "Utils.h"
#include "InputUtils.h"

// Sets default values
AMyFirstPawn::AMyFirstPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CREATE_TO(UStaticMeshComponent, "Mesh");
	RootComponent = mesh;
	camera = CREATE_TO(UCameraComponent, "Camera");
	springArm = CREATE_TO(USpringArmComponent, "SpringArm");
	movement = CREATE_TO(UFloatingPawnMovement, "Movement");
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
	ATTACH_TO(springArm, RootComponent);
	ATTACH_TO(camera, RootComponent);
	AddOwnedComponent(movement);
}

void AMyFirstPawn::BeginPlay()
{
	Super::BeginPlay();
	FPC->SetViewTarget(this);
	initRotation = GetActorRotation();
	initLocation = GetActorLocation();
}
void AMyFirstPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetupPlayerInputComponent(PLAYER);
	PositionVector();
	
}
void AMyFirstPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(VERTICAL, this, &AMyFirstPawn::MoveForward);
	PlayerInputComponent->BindAxis(HORIZONTAL, this, &AMyFirstPawn::MoveHorizontale);
	PlayerInputComponent->BindAxis(ROTATE, this, &AMyFirstPawn::RotateYaw);
	PlayerInputComponent->BindAction(RESET, EInputEvent::IE_Pressed,this, &AMyFirstPawn::Respawn);
}

void AMyFirstPawn::MoveForward(float _axis)
{
	const FVector _direction = GetActorForwardVector().GetSafeNormal() * 10;
	SetActorLocation(GetActorLocation() + (_direction * _axis * DELTATIME));
	//AddMovementInput(FVector(0, 1, 0), _axis);
}
void AMyFirstPawn::MoveHorizontale(float _axis)
{
	const FVector _direction = GetActorRightVector().GetSafeNormal() * 10;
	SetActorLocation(GetActorLocation() + (_direction * _axis * DELTATIME));
	//AddMovementInput(FVector(1, 0, 0), _axis);
}
void AMyFirstPawn::RotateYaw(float _axis)
{
	
	AddActorLocalRotation(FRotator(0, 0.1 * -_axis * DELTATIME, 0));
	//AddControllerYawInput(_axis);
}

void  AMyFirstPawn::Respawn()
{
	SetActorLocation(initLocation);
	SetActorRotation(initRotation);
}
void  AMyFirstPawn::PositionVector(void)
{
	const FVector _location = GetActorLocation();
	const FVector _right = GetActorRightVector().GetSafeNormal(),
		_fwd = GetActorForwardVector().GetSafeNormal(),
		_up = GetActorUpVector().GetSafeNormal();

	//FWD
	DRAW_LINE(_location, _location + _fwd * 200, FColor::Red, 2);
	DRAW_SPHERE(_location + _fwd * 200, 20, FColor::Red, 2);

	//RIGHT
	DRAW_LINE(_location, _location + _right * 200, FColor::Green, 2);
	DRAW_SPHERE(_location + _right * 300, 20, FColor::Green, 2);

	//UP
	DRAW_LINE(_location, _location + _up * 200, FColor::Blue, 2);
	DRAW_SPHERE(_location + _up * 500, 20, FColor::Blue, 2);
}