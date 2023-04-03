// Fill out your copyright notice in the Description page of Project Settings.


#include "EnnemyMovingComponent.h"
#include "Utils.h"
// Sets default values for this component's properties
UEnnemyMovingComponent::UEnnemyMovingComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

}
void UEnnemyMovingComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
	
}
void UEnnemyMovingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Move();
	DRAW_BOX(initLocation, FVector(5), FColor::Red, 2);
	DRAW_BOX(targetLocation, FVector(5), FColor::Blue, 2);
	DRAW_LINE(targetLocation, initLocation, FColor::Green,2);
}


void UEnnemyMovingComponent::Move()
{
	if (!canMove)
		return;
	const FVector _next = FMath::VInterpConstantTo(GetOwnerLocation(), currentLocation,
		GetWorld()->DeltaTimeSeconds, speed);
	SetOwnerLocation(_next);
	if (IsAtLocation())
	{
		toTarget = !toTarget;
		currentLocation = toTarget ? targetLocation : initLocation;
	}
}
void UEnnemyMovingComponent::Stop()
{
	canMove = false;
}
void UEnnemyMovingComponent::Init()
{
	initLocation = GetOwnerLocation();
	targetLocation = initLocation + GetOwner()->GetActorForwardVector() * sizeMovement;
	currentLocation = targetLocation;
}
bool UEnnemyMovingComponent::IsAtLocation() const
{
	return FVector::Distance(GetOwnerLocation(), currentLocation) <10;
}


