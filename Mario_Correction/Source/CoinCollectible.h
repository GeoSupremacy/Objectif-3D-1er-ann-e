// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectible.h"
#include "CoinCollectible.generated.h"

/**
 * 
 */
UCLASS()
class MARIO_CORRECTION_API ACoinCollectible : public ACollectible
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		float rotateSpeed = 2;
private:
	void RotateCoin();
protected:
	virtual void Tick(float _delta);
	virtual void CollectibleBehaviour(AMario* _mario)override;
};
