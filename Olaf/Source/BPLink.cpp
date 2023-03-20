// Fill out your copyright notice in the Description page of Project Settings.


#include "BPLink.h"
#include "Utils.h"


// Sets default values
ABPLink::ABPLink()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void ABPLink::BeginPlay()
{
	Super::BeginPlay();
	//onTest.Broadcast();
}
void ABPLink::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABPLink::Test()
{
	LOG_W(LogTemp, "value");
}
void ABPLink::TestParam(float _value)
{
	LOG_W(LogTemp, "value %f", _value);
}

