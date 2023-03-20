// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BPLink.generated.h"


UCLASS()
class OLAF_API ABPLink : public AActor
{
	GENERATED_BODY()
	/*DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTest);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTestParam, float, _axis);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta =(AllowPrivateAccess))
		float life = 0;
	UPROPERTY( BlueprintCallable, meta = (AllowPrivateAccess))
		FOntest onTest;
	UPROPERTY( BlueprintCallable, meta = (AllowPrivateAccess))
		FOnTestParam onTestParam;
*/
public:	
	ABPLink();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable) void Test();
	//Impossible la surchage en BluePrint
	UFUNCTION(BlueprintCallable) void TestParam(float _value);
};
