// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridActorCorr.generated.h"

USTRUCT()
struct FGridSettingsCorr
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (UIMin = 2, ClampMin = 2))
		int size = 4;
	UPROPERTY(EditAnywhere, meta = (UIMin = 2, ClampMin = 2))
		int gap = 100;

	TArray<FVector> gridPoints;
	float minX, minY, maxX, maxY;
};

UCLASS()
class OLAF_API AGridActorCorr : public AActor
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGridGenerated, AGridActorCorr*, _grid);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGridLocation, FVector, _location);
	UPROPERTY(EditAnywhere)
		FGridSettingsCorr settings;

	FOnGridGenerated onGridGenerated;
	FOnGridLocation onGridLocation;
public:	
	FORCEINLINE FOnGridGenerated& OnGridGenerated() {return onGridGenerated;}
	FORCEINLINE FOnGridLocation& OnGridLocation() { return onGridLocation; }
	AGridActorCorr();
	void SnapToStart(AActor* _toSnap);
	void MoveToCellDirection(AActor* _toMove, const FVector& _direction);
	void PickLocation(AActor* _target);
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Generate();
	void DrawGrid();
};
