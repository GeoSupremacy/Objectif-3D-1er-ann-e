// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYFIRSTPROJECT_API UTimerComponent : public UActorComponent
{
#pragma region F/P
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerEnd);
	FOnTimerEnd onTimerEnd;

	UPROPERTY(EditAnywhere, Category = Timer, meta = (Umin = 0, ClampMin = 0))
		float maxTimer = 5;

	bool isStarted = false;
	float timer;
#pragma endregion F/P
#pragma region Constructor
public:
	UTimerComponent();
#pragma endregion Constructor
#pragma region CUSTOM_METHODS
public:
	FORCEINLINE FOnTimerEnd& OnTimerEnd() { return onTimerEnd; }
	FORCEINLINE void StartTimer() { isStarted = true; }
	FORCEINLINE void StopTimer() { isStarted = false; }
	UFUNCTION() void ResetTimer();
private:
	void UpdateTimer(float& _timer, const float& _max);
#pragma endregion CUSTOM_METHODS
#pragma region UE_METHODS
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
#pragma endregion UE_METHODS
};
