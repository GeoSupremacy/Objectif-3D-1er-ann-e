// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"
#include "MyFirstPawn.generated.h"

UCLASS()
class OLAF_API AMyFirstPawn : public APawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = ObjectPtr)
		TObjectPtr<UStaticMeshComponent> mesh= nullptr;
	UPROPERTY(EditanyWhere, Category = ObjectPtr)
	TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditanyWhere, Category = ObjectPtr)
	TObjectPtr<UFloatingPawnMovement> movement = nullptr;
	UPROPERTY(EditanyWhere, Category = ObjectPtr)
		TObjectPtr<USpringArmComponent> springArm = nullptr;

	FRotator initRotation;
	FVector initLocation;
public:
	AMyFirstPawn();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void MoveForward(float _axis);
	void MoveHorizontale(float _axis);
	void RotateYaw(float _axis);
	void Respawn();
	void PositionVector(void);
};
