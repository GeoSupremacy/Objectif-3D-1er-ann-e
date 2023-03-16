// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringarmComponent.h"
#include "TimerComponent.h"
#include "Galaxy.h"
#include "SpaceShip.generated.h"

USTRUCT()
struct FPassiveArmeMemory
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere)
		float armLength =0;
	UPROPERTY(VisibleAnywhere)
		FVector initLocation;

	FPassiveArmeMemory(){
	}
	FPassiveArmeMemory(USpringArmComponent* _spring)
	{
		armLength = _spring->TargetArmLength;
		initLocation = _spring->SocketOffset;
	}
	void ResetValues(USpringArmComponent* _toWrite)
	{
		_toWrite->TargetArmLength = armLength;
		_toWrite->SocketOffset = initLocation;
	}
};
USTRUCT()
struct FPassiveModeSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Passive Settings", meta = (UImin = 100, ClampMin = 100, ClampMax = 1000, UIMax = 10000))
		float minArmLenght = 300;
	UPROPERTY(EditAnywhere, Category = "Passive Settings", meta = (UImin = 100, ClampMin = 100, ClampMax = 1000, UIMax = 10000))
		float maxArmLenght = 500;
	UPROPERTY(EditAnywhere, Category = "Passive Settings", meta = (UImin = -20000, ClampMin = 100, ClampMax = 1000, UIMax = 10000))
		float minHeight = -500;
	UPROPERTY(EditAnywhere, Category = "Passive Settings", meta = (UImin = 20000, ClampMin = 100, ClampMax = 1000, UIMax = 10000))
		float maxHeight = -500;

	FORCEINLINE float GetRandomArmLength() const
	{
		return FMath::FRandRange(minArmLenght,maxArmLenght);
	}
	FORCEINLINE float GetRandomArmHeight() const
	{
		return FMath::FRandRange(minHeight, maxHeight);
	}
};
UCLASS()
class MYFIRSTPROJECT_API ASpaceShip : public AActor
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShipMovement, float, _axis);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShipAxis);

	FOnShipMovement onShipMovement;
	FOnShipAxis onShipAxis;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> shipMesh = nullptr;
	UPROPERTY(EditAnywhere, Category = "Galaxy")
		TObjectPtr<AGalaxy> currentGalaxy = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UTimerComponent> customTimer = nullptr;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float fwdWeight = 1;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float rotateWeight = 1;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float pitchWeight = 1;
	UPROPERTY(EditAnywhere)
		float bankAngle = 45;

	UPROPERTY(EditAnywhere)
		float passiveModeYawSpeed = 1;
	UPROPERTY(EditAnywhere)
		float passiveModeResetSpeed = 1;

	UPROPERTY(EditAnywhere)
		FPassiveModeSettings passiveModeSetting;
	UPROPERTY(EditAnywhere)
		FPassiveArmeMemory springSnapshot;

	FVector shipVelocity;
	bool passiveModeEnable = false, isMoving = false;
	float forwardVelocity, rotateAxis, pitchAxis; //(0,y) 
	FRotator initRotation;
public:	
	ASpaceShip();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void InitShip();
	void InitInput();
	void MoveForward(float _axis);
	void RotateShip(float _axis);
	void AddPitch(float _axis);
	void AddFloatingBehaviour();
	void SetRandomPassiveValue();
#pragma region PassiveMode
	void RotateAroundCamera();
	void ResetCameraLocation(const FVector _maxDistance);
	UFUNCTION() void PassiveModeEnable();
	UFUNCTION() void PassiveModeDisable();
	UFUNCTION() void MovingDetection(float _value);
#pragma endregion PassiveMode
};
