// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocalMovement.generated.h"

UCLASS()
class MYFIRSTPROJECT_API ALocalMovement : public AActor
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FondEndTimer);

		UPROPERTY(VisibleAnywhere)
		TObjectPtr<UStaticMeshComponent> local = nullptr; // A* raw ptr
#pragma region Moving
#pragma region Speed
	UPROPERTY(EditAnywhere, Category = Move, meta =(Umin = 0, ClampMin = 0))
		float moveSpeed = 100;
	UPROPERTY(EditAnywhere, Category = Move, meta = (Umin = 0, ClampMin = 0))
		float rotateSpeed = 100;
	UPROPERTY(EditAnywhere, Category = Move, meta = (Umin = 0, ClampMin = 0))
		float scaleSpeed = 100;
#pragma endregion Speed
#pragma region Deplacement
	UPROPERTY(EditAnywhere, Category = "Move|Scale")
		float scaleForward = 0;
	UPROPERTY(EditAnywhere, Category = "Move|Scale")
		float scaleRight = 0;
	UPROPERTY(EditAnywhere, Category = "Move|Scale")
		float scaleUp = 0;

	UPROPERTY(EditAnywhere, Category = "Move|Rotation")
		float rotateForward = 0;
	UPROPERTY(EditAnywhere, Category = "Move|Rotation")
		float rotateRight = 0;
	UPROPERTY(EditAnywhere, Category = "Move|Rotation")
		float rotateUp = 0;

	UPROPERTY(EditAnywhere, Category = "Move|Movement")
		float distanceForward = 0;
	UPROPERTY(EditAnywhere, Category = "Move|Movement")
		float distanceRight = 0;
	UPROPERTY(EditAnywhere, Category = "Move|Movement")
		float distanceUp = 0;
#pragma endregion Deplacement
#pragma region CanAction
	UPROPERTY(EditAnywhere, Category = "Move|Can")
		bool canMove = true;
	UPROPERTY(EditAnywhere, Category = "Move|Can")
		bool canRotate = true;
	UPROPERTY(EditAnywhere, Category = "Move|Can")
		bool canScale = true;
#pragma endregion CanAction
#pragma endregion Moving

	UPROPERTY(EditAnywhere, Category = Axe)
		bool CanSeeAxe = false;

	UPROPERTY(EditAnywhere, Category = Time,meta = (UImin = 0, ClampMin = 0))
		float maxTimeDelay = 10;
	UPROPERTY()
		bool timerStarted = true;
	FondEndTimer oneEndTimer;
	float timer = 0;

	FVector initScale;
#pragma region Constructor
public:
	ALocalMovement();
#pragma endregion Constructor
#pragma region Ascenseur
public:
	FORCEINLINE float GetDistanceForward() { return  distanceForward; }
	FORCEINLINE float GetDistanceRight() { return  distanceRight; }
	FORCEINLINE float GetDistanceUp() { return  distanceUp; }

	FORCEINLINE float GetRotateForward() { return  rotateForward; }
	FORCEINLINE float GetRotateRight() { return  rotateRight; }
	FORCEINLINE float GetRotateUp() { return  rotateUp; }

	FORCEINLINE float GetScaleForward() { return  scaleForward; }
	FORCEINLINE float GetScaleRight() { return  scaleRight; }
	FORCEINLINE float GetScaleUp() { return  scaleUp; }

	FORCEINLINE bool GetEndTimer() const { return timer > maxTimeDelay; }
	FORCEINLINE float GetTimerProgress() const { return timer/maxTimeDelay; }

	FORCEINLINE void SetCanMove(const bool& _value) {canMove = _value;}
	FORCEINLINE void SetCanRotate(const bool& _value) { canRotate = _value; }
	FORCEINLINE void SetCanScaling(const bool& _value) { canScale = _value; }
	FORCEINLINE float SetDistanceForward(const float& _distance) { return distanceForward = _distance; }
	FORCEINLINE float SetDistanceRight(const float& _distance) { return distanceRight = _distance; }
	FORCEINLINE float SetDistanceUp(const float& _distance) { return distanceUp = _distance; }
#pragma endregion Ascenseur
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	void InitObject();
	void DrawDebugAxis();
	void Move();
	FORCEINLINE void MoveOneDirection(const FVector& _direction, const float& _speed);
	UFUNCTION() void StopRotation();
	UFUNCTION() void StopMovement();
	UFUNCTION() void StopScaling();
	FORCEINLINE void Rotate(const FRotator& _rotation, const float _speed);
	FORCEINLINE void Scale(const FScale2D& _scaling, const float _speed);
	void Rotation();
	void Scaling();
	void UpdateTimer(float& _timer);
	void DrawMovement();
	void Breath(const float& _value);
};
