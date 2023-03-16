// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planete.generated.h"

UCLASS()
class MYFIRSTPROJECT_API APlanete : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> planetMesh = nullptr; //
	UPROPERTY(EditAnywhere, Category = Planet)
		bool useRandomScale = true;//
	FVector initScale;//
	float initDistance = 1000;//
public:	
	APlanete();
	FORCEINLINE float GetCurrentDistanceTo(const FVector& _from){ return FVector::Distance(_from, GetActorLocation()); }//
	FORCEINLINE float GetMaxDistance() const {return initDistance;}//
	FORCEINLINE void SetInitDistance(const FVector& _shipLocation) {initDistance = GetCurrentDistanceTo(_shipLocation);}//
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void InitObject();//
	void ShapeApproch();
public:
	void UpdateSize(const FVector& _location);//
};
