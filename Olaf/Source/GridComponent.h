// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GridComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OLAF_API UGridComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditanyWhere, Category = maxSize)
		int maxHorizontal;
	UPROPERTY(EditanyWhere, Category = maxSize)
		int maxVertical;
	UPROPERTY()
		int horizontal = 0, vertical = 0;

public:	
	UGridComponent();

private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;	
	void DrawCase();
	void Up();
	void Down();
	void Left();
	void Right();
};
