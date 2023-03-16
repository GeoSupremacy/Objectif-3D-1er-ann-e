// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planete.h"
#include "Galaxy.generated.h"
class ASpaceCrab_Correction;
UCLASS()
class MYFIRSTPROJECT_API AGalaxy : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnyWhere)
		TArray<APlanete*> allPlanets;//
	UPROPERTY()
		TObjectPtr<class ASpaceCrab_Correction> currentShip = nullptr;//
public:	
	AGalaxy();
	void InitGalaxy(ASpaceCrab_Correction* _ship);//
#pragma region UE_METHODS
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
#pragma endregion UE_METHODS
private:
	void DrawDebugGalaxy();//
	void UpdatePlanetSize(const ASpaceCrab_Correction* _ship);//
};
