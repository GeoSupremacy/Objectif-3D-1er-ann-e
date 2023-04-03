// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleBlock.h"

void ADestructibleBlock::DownBehaviour(AMario* _Mario)
{
	SetLifeSpan(0.1f);
}
