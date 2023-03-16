// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorMove.generated.h"

UCLASS()
class MYFIRSTPROJECT_API AMyActorMove : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> origin = nullptr;
	UPROPERTY(EditAnywhere)
		float speed = 1;
		float tProgress = 0;
		
public:	
	AMyActorMove();
	FORCEINLINE FVector GetOriginPoint() const
	{
		return origin ? origin->GetActorLocation() : GetActorLocation();
	}
	FORCEINLINE FVector GetTargetPoint() const
	{
		return target ? target->GetActorLocation() : GetActorLocation();
	}
	private:
	void MoveToTarget();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
