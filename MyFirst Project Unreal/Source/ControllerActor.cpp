// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerActor.h"

// Sets default values
AControllerActor::AControllerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//controller = CreateDefaultSubobject<UStaticMeshComponent>("Ctrcl");
	//RootComponent = controller;
	InitObject();
}

FVector AControllerActor::GetFromPoint() const
{
	return GetActorLocation();
}
void AControllerActor::InitObject()
{
	//controller->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
	//controller->GetStaticMesh()->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("'/Engine/BasicShapes/BasicShapesMaterial.BasicShapesMaterial'")));
}


void AControllerActor::BeginPlay()
{
	Super::BeginPlay();
	fromLocation = GetFromPoint();
}
void AControllerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

