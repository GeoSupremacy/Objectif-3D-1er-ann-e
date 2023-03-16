// Fill out your copyright notice in the Description page of Project Settings.


#include "InputActor.h"
#include "Util.h"
#include "InputUtils.h"


#pragma region Constructor
AInputActor::AInputActor()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	InitObject();
}
#pragma endregion Constructor
#pragma region UE_METHODS
void AInputActor::BeginPlay()
{
	Super::BeginPlay();
	initScale = GetActorScale();//
	initLocation = GetActorLocation();
	SetupInput();
}
void AInputActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateScale(scaleSpeed);
	DisplayVectorObject();
}
#pragma endregion UE_METHODS
#pragma region CUSTOM_METHODS
void AInputActor::InitObject()
{
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
	mesh->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("Material'/Engine/EditorMaterials/Cloth/CameraLitDoubleSided.CameraLitDoubleSided'")));
}
void AInputActor::SetupInput()
{
	BIND_AXIS(HORIZONTAL, this, &AInputActor::SetHorizontal);
	BIND_AXIS(VERTICAL, this, &AInputActor::SetVertical);
	BIND_AXIS(ROTATE, this, &AInputActor::SetRotation);
	//BIND_AXIS(SCALE, this, &AInputActor::SetScale);
	BIND_AXIS(SCALE, this, &AInputActor::SetDynamicScale);//
	//GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("???", EInputEvent::IE_Pressed, this, &///);
	BIND_ACTION(RESPAWN, EInputEvent::IE_Pressed, this, &AInputActor::Respawn);

	DECLARE_DELEGATE_ThreeParams(FInputDelegateCustom, float, int, bool);
	BIND_ACTION_PARAMS(FInputDelegateCustom,RESPAWN, EInputEvent::IE_Pressed, this, &AInputActor::Other, 2.0f, 5, true);
}
void AInputActor::SetHorizontal(float _axis)
{
	const FVector _direction = GetActorUpVector().GetSafeNormal() * horizontaleSpeed;
	SetActorLocation( GetActorLocation() +(_direction *_axis));

}
void AInputActor::SetVertical(float _axis)
{
	const FVector _direction = GetActorRightVector().GetSafeNormal() * verticaleSpeed;
	SetActorLocation(GetActorLocation() + (_direction * _axis));
}
void AInputActor::SetRotation(float _axis)
{
	AddActorLocalRotation(FRotator(0, rotateSpeed * -_axis * DELTATIME,0));
}
void AInputActor::SetScale(float _axis)
{
	
	SetActorScale3D(initScale + (initScale * FMath::Abs(-_axis)));
}
void AInputActor::UpdateScale(const float& _speed)
{
	const FVector _scale = FMath::Lerp(GetActorScale(), maxScale, DELTATIME * _speed);
	SetActorScale3D(_scale);
}
void AInputActor::SetDynamicScale(float _axis)
{
	if(_axis ==0)
		maxScale = initScale;
	else if (_axis >0)
		maxScale = initScale *2;
	else if(_axis <0)
		maxScale = initScale / 2;
}
void AInputActor::DisplayVectorObject()
{
	DRAW_SPHERE(GetActorLocation() + GetActorRightVector().GetSafeNormal() * 150, 20, FColor::Red, 5);
	DRAW_LINE(GetActorLocation() + GetActorRightVector().GetSafeNormal() * 250, GetActorLocation(), FColor::Red, 2);

	DRAW_SPHERE(GetActorLocation() + GetActorUpVector().GetSafeNormal() * 150, 20, FColor::Green, 5);
	DRAW_LINE(GetActorLocation() + GetActorUpVector().GetSafeNormal() * 250, GetActorLocation(), FColor::Green, 2);

	DRAW_SPHERE(GetActorLocation() + GetActorForwardVector().GetSafeNormal() * 150, 20, FColor::Blue, 5);
	DRAW_LINE(GetActorLocation() + GetActorForwardVector().GetSafeNormal() * 250, GetActorLocation(), FColor::Blue, 2);

	DRAW_SPHERE(initLocation, 50, FColor::Cyan, 2);
	DRAW_LINE(initLocation, GetActorLocation(), FColor::Cyan, 2);
}
void AInputActor::Respawn()
{
	SetActorLocation(initLocation);
}
void AInputActor::Other(float _a, int _b, bool _c)
{
}
#pragma endregion CUSTOM_METHODS
