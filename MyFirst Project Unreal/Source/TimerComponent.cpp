// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerComponent.h"
#include "Util.h"

#pragma region Constructor
UTimerComponent::UTimerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}
#pragma endregion Constructor
#pragma region UE_METHODS
void UTimerComponent::BeginPlay()
{
	Super::BeginPlay();

}
void UTimerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateTimer(timer, maxTimer);
}
#pragma endregion UE_METHODS
#pragma region CUSTOM_METHODS
void UTimerComponent::UpdateTimer(float& _timer, const float& _max)
{
	if (!isStarted)
		return;
	_timer += DELTATIME;
	if (_timer > _max)
	{
		onTimerEnd.Broadcast();
		_timer = 0;
		isStarted = false;
	}
}
void UTimerComponent::ResetTimer()
{
	timer = 0;
}
#pragma endregion CUSTOM_METHODS
