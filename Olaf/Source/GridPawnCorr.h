// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GridActorCorr.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "GridPawnCorr.generated.h"

UCLASS()
class OLAF_API AGridPawnCorr : public APawn
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AGridActorCorr> grid = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
public:
	AGridPawnCorr();
private:
	void IniPawnCorr();
	TObjectPtr<AGridActorCorr> GetGrid() const;
	void SelectGridCell();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void UpMove();
	void DownMove();
	void LeftMove();
	void RightMove();
};
