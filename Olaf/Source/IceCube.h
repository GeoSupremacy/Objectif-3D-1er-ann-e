// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ActorMouvementComponent.h"
#include "IceCube.generated.h"

USTRUCT()
struct FIceCubeCorrSettings
{
#pragma region f/p
	GENERATED_BODY()

	FVector initSize = FVector(1);
	FVector startScale;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 0))
		float divideSizeBy = 3;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float meltingTime = 30;
private:
	float currentTime = 0;
#pragma endregion f/p	
#pragma region Methods
public:
	FORCEINLINE float ScaleRatio() const { return currentTime / meltingTime; }
	FORCEINLINE FVector TargetSize() const { return initSize / divideSizeBy; }
	FORCEINLINE void UpdateScaleTimer(const UWorld* _world)
	{
		currentTime += _world->DeltaTimeSeconds;
		if (currentTime > meltingTime)
		{
			currentTime = meltingTime;
			return;
		}
	}
	FORCEINLINE void UpdateScale(AActor* _target)
	{
		_target->SetActorScale3D(FMath::Lerp(initSize, TargetSize(), ScaleRatio()));
	}
	FORCEINLINE void ResetScale(AActor* _target, float _factor)
	{
		currentTime = 0;
		_target->SetActorScale3D(FMath::LERP(startScale, initSize, _factor));
	}
#pragma endregion fMethods
};

UCLASS()
class OLAF_API AIceCube : public AActor
{
#pragma region f/p
	GENERATED_BODY()

		UPROPERTY(EditanyWhere)
		TObjectPtr<UStaticMeshComponent> meshIceCube = nullptr;
	UPROPERTY(EditanyWhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditanyWhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditanyWhere)
		TObjectPtr<UActorMouvementComponent> mouvement = nullptr;
	UPROPERTY(EditanyWhere)
		FIceCubeCorrSettings settings;
#pragma endregion f/p	
#pragma region Constructor
public:	
	AIceCube();
#pragma endregion Constructor
#pragma region UE_METHODS
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
#pragma endregion UE_METHODS
#pragma region Custom
private:
	void InitIceCube();
	void InitInput();
	void ScaleBehaviour();
	void ResetIceSizeBehaviour(float _scale);
	void StarResetSize();
#pragma endregion Custom
};

#pragma region comm
/*
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShipAxis);
FOnShipAxis onShipAxis;
*/
/*	UPROPERTY(EditanyWhere, Category = Speed)
		float speedMove = 100;
	UPROPERTY(EditanyWhere, Category = Speed)
		float speedRotate = 100;

	float speedScale;

	float timer, maxTimer =10;*/
#pragma endregion comm