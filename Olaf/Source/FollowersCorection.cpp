// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowersCorection.h"
#include "Utils.h"


UFollowersCorection::UFollowersCorection()
{
	
	PrimaryComponentTick.bCanEverTick = true;

	
}
void UFollowersCorection::BeginPlay()
{
	Super::BeginPlay();
	SetTarget(FPC->GetPawn());
	
}
void UFollowersCorection::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DRAW_SPHERE(GetTargetLocation(), 50, FColor::Green, 2);
	DRAW_LINE(GetTargetLocation(), GetActorLocation(),FColor::Green, 2);

	DRAW_BOX(GetFinalLocation(), FVector(10), FColor::Red, 2);
	DRAW_LINE(GetFinalLocation(), GetActorLocation(), FColor::Red, 2);

	FollowTarget();
	ReplicationRollAngle();
	LookTarget();
}

FVector UFollowersCorection::GetFinalLocation()
{
	if (!target)
		return GetTargetLocation();
	FVector _offset;
	switch (settings.axis)
	{
	case X:
		_offset = target->GetActorForwardVector();
		break;
	case InvertX:
		_offset = -target->GetActorForwardVector();
		break;
	case Y:
		_offset = target->GetActorRightVector();
		break;
	case InvertY:
		_offset = target->GetActorForwardVector();
		break;
	}
	return (GetTargetLocation() +_offset * settings.distance) + FVector(0 ,0 ,settings.height);
}
void UFollowersCorection::FollowTarget()
{
	GetOwner()->SetActorLocation(FMath::Lerp(GetActorLocation(), GetFinalLocation(), DELTATIME * settings.speed));
}
void UFollowersCorection::ReplicationRollAngle()
{
	if (!settings.replicationRoll || !target)
		return;
	FRotator _rot = GetOwner()->GetActorRotation();
	_rot.Roll = target->GetActorRotation().Roll;
	GetOwner()->SetActorRotation(_rot);
}
void UFollowersCorection::LookTarget()
{
	if (!settings.useLookAt)
		return;
}

