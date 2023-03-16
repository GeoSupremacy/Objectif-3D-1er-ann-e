// Fill out your copyright notice in the Description page of Project Settings.


#include "IceCube.h"
#include "Utils.h"
#include "InputUtils.h"

#pragma region Constructor
AIceCube::AIceCube()
{
	PrimaryActorTick.bCanEverTick = true;
	meshIceCube = CREATE_TO(UStaticMeshComponent, "Mesh");
	camera = CREATE_TO(UCameraComponent, "Camera");
	RootComponent = meshIceCube;
	springArm = CREATE_TO(USpringArmComponent, "SpringArm");
	mouvement = CREATE_TO(UActorMouvementComponent, "Movement");
	meshIceCube->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
	ATTACH_TO(springArm, RootComponent);
	ATTACH_TO(camera, RootComponent);
	AddOwnedComponent(mouvement);
}
#pragma endregion Constructor	
#pragma region UE_METHODS
void AIceCube::BeginPlay()
{
	Super::BeginPlay();
	InitIceCube();
	InitInput();
}
void AIceCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	settings.UpdateScaleTimer(WORLD);
	settings.UpdateScale(this);
	ScaleBehaviour();
	DRAW_BOX(GetActorLocation(), settings.TargetSize() *50, FColor::Red, 2);
	DRAW_BOX(GetActorLocation(), settings.initSize *50, FColor::Red, 2);
}
#pragma endregion UE_METHODS	
#pragma region Custom
void AIceCube::InitIceCube()
{
	FPC->SetViewTarget(this);
	settings.initSize = GetActorScale();
	//if (mouvement)
		//mouvement->OnResetMovement().AddDynamic(this, &AIceCube::ResetIceSizeBehaviour);
}
void AIceCube::InitInput()
{
	BIND_AXIS(VERTICAL, mouvement.Get(), &UActorMouvementComponent::MoveRight);
	BIND_AXIS(HORIZONTAL, mouvement.Get(), &UActorMouvementComponent::MoveForward);
	BIND_AXIS(ROTATE, mouvement.Get(), &UActorMouvementComponent::Rotate);
	BIND_ACTION("Reset", EInputEvent::IE_Pressed, mouvement.Get(), &UActorMouvementComponent::CallReset);
	BIND_ACTION("Reset", EInputEvent::IE_Pressed, this, &AIceCube::StarResetSize);
}
void AIceCube::ScaleBehaviour()
{
	if (!mouvement)
		return;
	mouvement->UpdateForwardWeight(1 - settings.ScaleRatio() * 0.1f);
	mouvement->UpdateHorizontaleWeight(1 - settings.ScaleRatio() * 0.1f);
	mouvement->UpdateRotateWeight(1 - settings.ScaleRatio() * 0.1f);
}
void AIceCube::ResetIceSizeBehaviour(float _scale)
{
	settings.ResetScale(this, _scale);
}
void AIceCube::StarResetSize()
{
	settings.startScale = GetActorScale();
}
#pragma endregion Custom	
#pragma region comm
/*void AIceCube::SetScale()
{
	timer++;
	 float _scale = speedScale += DELTATIME;
	if (timer < 100)
		SetActorScale3D(FVector(_scale));
}*/
#pragma endregion comm	
