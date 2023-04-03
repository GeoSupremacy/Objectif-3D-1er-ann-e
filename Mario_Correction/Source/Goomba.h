// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ennemy.h"
#include "Goomba.generated.h"

/**
 * 
 */
UCLASS()
class MARIO_CORRECTION_API AGoomba : public AEnnemy
{
	GENERATED_BODY()
protected:
	virtual void GlobalBehaviour(AMario* _mario) override;
	virtual void UpBehaviour(AMario* _mario) override;
	virtual void Die() override;
};

