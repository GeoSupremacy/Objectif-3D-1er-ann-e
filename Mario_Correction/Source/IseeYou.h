// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IseeYou.generated.h"

UCLASS()
class MARIO_CORRECTION_API AIseeYou : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
public:
	AIseeYou();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
