// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ControllerActor.generated.h"

UCLASS()
class MYFIRSTPROJECT_API AControllerActor : public AActor
{
	GENERATED_BODY()
	
	//UPROPERTY(VisibleAnywhere)
		//TObjectPtr<UStaticMeshComponent> controller = nullptr;

	FVector fromLocation = FVector(0);
public:	
	AControllerActor();
private:

	FVector GetFromPoint() const;
	void InitObject();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
