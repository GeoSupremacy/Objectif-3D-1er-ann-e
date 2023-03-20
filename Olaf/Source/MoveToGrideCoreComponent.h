// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridActorCorr.h"
#include "Components/ActorComponent.h"
#include "MoveToGrideCoreComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OLAF_API UMoveToGrideCoreComponent : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<AGridActorCorr> grid = nullptr;
	UPROPERTY(EditAnywhere)
		float offset = 100;

	FVector targetLocation;
public:	
	UMoveToGrideCoreComponent();
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Init();
	UFUNCTION() void SetLocation(FVector _location);
	void MoveToLocation();
	void LookAtDirection();
};
