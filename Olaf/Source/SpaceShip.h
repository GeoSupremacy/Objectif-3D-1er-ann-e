// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstPawn.h"
#include "SpaceShip.generated.h"

UCLASS()
class OLAF_API ASpaceShip : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = ObjectPtr)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere, Category = ObjectPtr)
		TObjectPtr<AMyFirstPawn> pawn = nullptr;
	UPROPERTY(EditAnywhere, Category = ObjectPtr)
		TObjectPtr<UInputComponent> movement = nullptr;


public:	
	ASpaceShip();
private:
	virtual void BeginPlay() override;	
	virtual void Tick(float DeltaTime) override;

};
