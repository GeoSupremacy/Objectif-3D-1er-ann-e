// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusBlock.h"

void ABonusBlock::DownBehaviour(AMario* _Mario)
{
	GetWorld()->SpawnActor<AActor>(bonusBlockVisualGraphics, GetActorLocation(), GetActorRotation());
	GetWorld()->SpawnActor<ACollectible>(bonusItem, GetActorLocation()+ offsetSpawn, GetActorRotation());
	SetLifeSpan(0.1f);
}
