// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FollowersCorection.generated.h"


UENUM()
enum EFollwAxis
{
	X,
	InvertX,
	Y,
	InvertY,
};


USTRUCT()
struct FFollowSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TEnumAsByte<EFollwAxis> axis;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float speed = 0.5f;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float height = 20;
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
		float distance = 150;
	UPROPERTY(EditAnywhere)
		bool replicationRoll = true;
	UPROPERTY(EditAnywhere)
		bool useLookAt = true;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OLAF_API UFollowersCorection : public UActorComponent
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> target = nullptr;
	FFollowSettings settings;
public:
	UFollowersCorection();
	FORCEINLINE void SetTarget(TObjectPtr<AActor> _target) { target = _target; };
	FORCEINLINE FVector GetTargetLocation() const { return  target ? target->GetActorLocation() : FVector(0); }
	FORCEINLINE FVector GetActorLocation() const {return GetOwner()->GetActorLocation(); }
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
	FVector GetFinalLocation();
	void FollowTarget();
	void ReplicationRollAngle();
	void LookTarget();
};
