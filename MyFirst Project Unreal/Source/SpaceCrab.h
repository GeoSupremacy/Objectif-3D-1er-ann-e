// Fill out your copyright notice in the Description page of Project Settings.
//Move le vaisseau  et lors des déplacements des planètes qui sont des sphères rétrécisse/agrandisse en l'approche du vaisseau
// Comme gérer la distance entre planète
	//Move speed
	//Event (keyboard)
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceCrab.generated.h"

UCLASS()
class MYFIRSTPROJECT_API ASpaceCrab : public AActor
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FondEndTimer);
#pragma region f/p
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr; // A* raw ptr

	UPROPERTY(EditAnywhere, Category = Collector)
		TArray<AActor*> Collector = TArray<AActor*>();

	UPROPERTY(EditAnywhere, Category = Axe)
		bool canSeeAxe = false;
	
	FVector initScale;
	FVector initLocation;
#pragma endregion 
#pragma region Moving
#pragma region Speed
	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float horizontaleSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float verticaleSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float rotateSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float scaleSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float altitudeSpeed = 100;
#pragma endregion Speed
#pragma region CanAction
	UPROPERTY(EditAnywhere, Category = "Movement|Action")
		bool canMove = true;
	UPROPERTY(EditAnywhere, Category = "Movement|Action")
		bool canRotate = true;
	UPROPERTY(EditAnywhere, Category = "Movement|Action")
		bool canScale = true;
#pragma endregion CanAction
#pragma endregion Moving
#pragma region Timer
	UPROPERTY(EditAnywhere, Category = Time, meta = (UImin = 0, ClampMin = 0))
		float maxTimeDelay = 10;
	UPROPERTY()
		bool timerStarted = true;
	FondEndTimer oneEndTimer;
	float timer = 0;
#pragma endregion Timer
#pragma region Constructor
public:
	ASpaceCrab();
#pragma endregion Constructor
#pragma region Ascenseur
public:
	FORCEINLINE bool GetEndTimer() const { return timer > maxTimeDelay; }
	FORCEINLINE float GetTimerProgress() const { return timer / maxTimeDelay; }

	FORCEINLINE void SetCanMove(const bool& _value) { canMove = _value; }
	FORCEINLINE void SetCanRotate(const bool& _value) { canRotate = _value; }
	FORCEINLINE void SetCanScaling(const bool& _value) { canScale = _value; }

	FORCEINLINE void SetupInput();
	FORCEINLINE void SetHorizontal(float _axis);
	FORCEINLINE void SetVertical(float _axis);
	FORCEINLINE void SetRotation(float _axis);
	FORCEINLINE void SetScale(float _axis);
	FORCEINLINE void SetAltitude(float _axis);
	FORCEINLINE void Respawn() { SetActorLocation(initLocation);}
#pragma endregion Ascenseur
#pragma region UE_METHODS
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
#pragma endregion UE_METHODS
#pragma region CUSTOM_METHODS
private:
	UFUNCTION() void StopRotation();
	UFUNCTION() void StopMovement();
	UFUNCTION() void StopScaling();
	void SetDynamicScale(float _axis);//
	void DrawDebug();
	void PlaneteApproch();
#pragma endregion CUSTOM_METHODS
};
