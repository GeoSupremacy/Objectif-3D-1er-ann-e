// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/BoxComponent.h"
#include "Mario.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectible.generated.h"

UCLASS()
class MARIO_CORRECTION_API ACollectible : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<UBoxComponent> trigger = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> meshCollector = nullptr;
public:	
	ACollectible();

private:
	virtual void BeginPlay() override;
	void NotifyActorBeginOverlap(AActor* _other);
protected:
	virtual void CollectibleBehaviour(AMario* _mario);
};
