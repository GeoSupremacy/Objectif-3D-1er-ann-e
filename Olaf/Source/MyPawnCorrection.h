// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"
#include "MyPawnCorrection.generated.h"

USTRUCT()
struct FShipControlsSettings
{
	GENERATED_BODY()
		UPROPERTY(EditanyWhere, meta = (UIMin =0, ClampMin = 0))
		float forwardWeight = 1;
	UPROPERTY(EditanyWhere, meta = (UIMin = 0, ClampMin = 0))
		float rightWeight = 1;
		UPROPERTY(EditanyWhere, meta = (UIMin =0, ClampMin = 0))
		float rollWeight =1;
		UPROPERTY(EditanyWhere, meta = (UIMin =0, ClampMin = 0))
		float yawdWeight =1;
		UPROPERTY(EditanyWhere, meta = (UIMin =-65, ClampMin = -65, UIMax = -65, ClampMax = -65))
		float maxAngle = 60;

		float forwardAxis,rightAxis ,rollAxis, yawAxis ;
};
UCLASS()
class OLAF_API AMyPawnCorrection : public APawn
{
	GENERATED_BODY()
	UPROPERTY()
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditanyWhere, Category = ObjectPtr)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditanyWhere, Category = ObjectPtr)
		TObjectPtr<UFloatingPawnMovement> movement = nullptr;
	UPROPERTY(EditanyWhere, Category = ObjectPtr)
		TObjectPtr<USpringArmComponent> arm = nullptr;
	UPROPERTY(EditanyWhere, Category = ObjectPtr)
		FShipControlsSettings settings;


	 
public:
	AMyPawnCorrection();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void RollMovement(float _axis);
	void YawMovement(float _axis);
};
