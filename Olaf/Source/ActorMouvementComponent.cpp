// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorMouvementComponent.h"
#include "Utils.h"
#include "InputUtils.h"



UActorMouvementComponent::UActorMouvementComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}
void UActorMouvementComponent::BeginPlay()
{
	Super::BeginPlay();
	settings.initLocation = OWNER->GetActorLocation();
	
}
void UActorMouvementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateMouvement();
	UpdateRotate();
	ResetBehaviour();
	CallReset();
	DRAW_SPHERE_DEF(GetOwner()->GetActorLocation() +(GetVelocity() * 200), 10, 5, FColor::Green, 2);
	DRAW_LINE(GetOwner()->GetActorLocation() + (GetVelocity() * 200), GetOwner()->GetActorLocation(), FColor::Green, 2);
}
void UActorMouvementComponent::UpdateMouvement()
{
	OWNER->AddActorWorldOffset(GetVelocity());
}
void UActorMouvementComponent::UpdateRotate()
{
	OWNER->AddActorLocalRotation(GetRotationVelocity());
}

void UActorMouvementComponent::ResetBehaviour()
{
	if (!isInResetStatues)
		return;
	if (settings.UpdateTimer(GetWorld()))
	{
		isInResetStatues = false;
		return;
	}
	GetOwner()->SetActorLocation(LERP(settings.currentLocation, settings.initLocation, settings.GetResetRatio()));
	//GetOwner()->
}
void UActorMouvementComponent::OnEndReset()
{
	isInResetStatues = false;
}
void UActorMouvementComponent::CallReset()
{
	if (isInResetStatues)
		return;
	settings.currentLocation = OWNER->GetActorLocation();
	settings.ResetValues();
	isInResetStatues = true;
}
void UActorMouvementComponent::MoveRight(float _axis)
{
	settings.forwardAxis = LERP(settings.forwardAxis, _axis, DELTATIME * settings.forwardWeight);
}
void UActorMouvementComponent::MoveForward(float _axis)
{
	settings.horizontaleAxis = LERP(settings.horizontaleAxis, _axis, DELTATIME * settings.horizontalWeight);
}
void UActorMouvementComponent::Rotate(float _axis)
{
	settings.rotatedAxis = LERP(settings.rotatedAxis, -_axis, DELTATIME * settings.rotateWeight);
}





