// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "IseeYou.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YouSeeMe.generated.h"

UCLASS()
class MARIO_CORRECTION_API AYouSeeMe : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;

public:	
	AYouSeeMe();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void HeSeeMe(AIseeYou* _you);
	virtual void NotifyActorBeginOverlap(AActor* _other) override;
	virtual void NotifyActorEndOverlap(AActor* _other) override;
};
