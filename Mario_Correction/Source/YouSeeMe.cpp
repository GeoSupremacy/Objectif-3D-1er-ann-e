// Fill out your copyright notice in the Description page of Project Settings.


#include "YouSeeMe.h"
#include "Utils.h"

AYouSeeMe::AYouSeeMe()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	mesh = CREATE(UStaticMeshComponent, "Mesh");
}
void AYouSeeMe::BeginPlay()
{
	Super::BeginPlay();
	
}
void AYouSeeMe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DRAW_LINE(GetActorLocation(), GetActorLocation() + GetActorForwardVector().GetSafeNormal() * 200, FColor::Red, 5);
}
void AYouSeeMe::NotifyActorBeginOverlap(AActor* _other)
{
	AIseeYou* _char = Cast<AIseeYou>(_other);
	if (!_char)
		return;
	HeSeeMe(_char);
}
void AYouSeeMe::NotifyActorEndOverlap(AActor* _other)
{
	
}


void AYouSeeMe::HeSeeMe(AIseeYou* _you)
{
	if (FVector::Distance(_you->GetActorLocation(), GetActorLocation() + GetActorForwardVector().GetSafeNormal()))
		LOG_W(LogTemp, "SEE YOU");
		
}



