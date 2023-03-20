// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveToGrideCoreComponent.h"
#include "Kismet/KismetMathLibrary.h"

UMoveToGrideCoreComponent::UMoveToGrideCoreComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UMoveToGrideCoreComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
	
}
void UMoveToGrideCoreComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToLocation();
	LookAtDirection();
}
void UMoveToGrideCoreComponent::Init()
{
	if (!grid)
		return;
	grid->OnGridLocation().AddDynamic(this, &UMoveToGrideCoreComponent::SetLocation);
}

UFUNCTION() void UMoveToGrideCoreComponent::SetLocation(FVector _location)
{
	targetLocation = _location + offset;
}
void UMoveToGrideCoreComponent::MoveToLocation()
{
	const FVector _lerpMovement = FMath::Lerp(GetOwner()->GetActorLocation(), targetLocation, GetWorld()->DeltaTimeSeconds * 5);
	GetOwner()->SetActorLocation(_lerpMovement);
}
void UMoveToGrideCoreComponent::LookAtDirection()
{
	const FRotator _rot = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), targetLocation);
	const FRotator _lerp = FMath::Lerp(GetOwner()->GetActorRotation(), _rot, GetWorld()->DeltaTimeSeconds * 5);
	GetOwner()->SetActorRotation(_lerp);
}

