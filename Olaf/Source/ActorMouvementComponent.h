// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Utils.h"
#include "InputUtils.h"
#include "ActorMouvementComponent.generated.h"

USTRUCT()
struct FMovementCorrectionSettings
{

	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere)
		float forwardAxis;
	UPROPERTY(VisibleAnywhere)
		float horizontaleAxis; 
	UPROPERTY(VisibleAnywhere)
		float rotatedAxis;
	UPROPERTY(VisibleAnywhere)
		float forwardWeight =1;
	UPROPERTY(VisibleAnywhere)
		float horizontalWeight =1;
	UPROPERTY(VisibleAnywhere)
		float rotateWeight = 1;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float timeToReset = 10;
public:
	FVector initLocation;
	FVector currentLocation = initLocation;
	float currentTimer;
	
	FORCEINLINE float GetResetRatio() const {return currentTimer / timeToReset;}
	FORCEINLINE bool UpdateTimer(const UWorld* _world)
	{
		currentTimer += _world->DeltaTimeSeconds;
		if (currentTimer > timeToReset)
		{
			currentTimer = 0;
			return true;
		}
		return false;
	}
	FORCEINLINE void ResetValues()
	{
		forwardAxis =0;
		horizontaleAxis =0;
		rotatedAxis = 0;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OLAF_API UActorMouvementComponent : public UActorComponent
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_DELEGATE_OneParam(FonResetMovement, float, _ratio);
	UPROPERTY(EditAnywhere)
		FMovementCorrectionSettings settings;

	bool isInResetStatues = false;
	FonResetMovement onResetMovement;

public:
	UActorMouvementComponent();
	FORCEINLINE FonResetMovement& OnResetMovement() {return onResetMovement;}
	FORCEINLINE FVector GetVelocity() const {
		return GetOwner()->GetActorForwardVector() * settings.forwardAxis + GetOwner()->GetActorRightVector() * settings.horizontaleAxis; }
	FORCEINLINE FRotator GetRotationVelocity() const { 
		return FRotator(0, settings.rotatedAxis,0); }
	FORCEINLINE void UpdateRotateWeight(const float& _value) { settings.rotateWeight = _value;}
	FORCEINLINE void UpdateHorizontaleWeight( const float& _value) { settings.horizontalWeight = _value; }
	FORCEINLINE void UpdateForwardWeight(const float& _value) { settings.forwardWeight = _value; }
	void MoveRight(float _axis);
	void MoveForward(float _axis);
	void Rotate(float _axis);
	void CallReset();
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	void UpdateMouvement();
	void UpdateRotate();
	void ResetBehaviour();
	void OnEndReset();
};
