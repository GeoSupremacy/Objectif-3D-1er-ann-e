// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mario.generated.h"

USTRUCT()
struct FSnapshot
{
public:
	GENERATED_BODY()
	FVector location;
	FRotator rotation;
	FSnapshot()
	{

	}
	FSnapshot(FTransform _transform)
	{
		location = _transform.GetLocation();
		rotation = _transform.GetRotation().Rotator();
	}
	void Reload(AActor* _actor)
	{
		_actor->SetActorLocationAndRotation(location, rotation);
	}
};

UCLASS()
class MARIO_CORRECTION_API AMario : public ACharacter
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FonMoveForward, float, _axis);

	UPROPERTY(EditAnywhere, Category = Camera)
		TObjectPtr<USpringArmComponent> arm = nullptr;
	UPROPERTY(EditAnywhere, Category = Camera)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivaAccess))
		FonMoveForward onMoveForward;


	bool isDead = false;
	FSnapshot marioSnap;
	FTimerHandle respawnDelay;
public:
	FORCEINLINE bool IsDead() const { return isDead; }
	void Die();
	AMario();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void OnRespawnDelayed();
	
};
