// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include"Collectible.h"
#include "CoreMinimal.h"
#include "Block.h"
#include "BonusBlock.generated.h"

/**
 * 
 */
UCLASS()
class MARIO_CORRECTION_API ABonusBlock : public ABlock
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = Bonus)
		TSubclassOf<ACollectible> bonusItem = nullptr;
	UPROPERTY(EditAnywhere, Category = Bonus)
		TSubclassOf<AActor> bonusBlockVisualGraphics = nullptr;
	UPROPERTY(EditAnywhere, Category = Bonus)
	FVector offsetSpawn = FVector(0, 0, 150);
protected:
	virtual void DownBehaviour(AMario* _Mario) override;
};