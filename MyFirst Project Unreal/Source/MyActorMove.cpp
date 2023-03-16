// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorMove.h"
#include "Util.h"


// Sets default values
AMyActorMove::AMyActorMove()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>("Lerp");

}

void AMyActorMove::MoveToTarget()
{
	/*tProgress += DELTATIME;// *speed;
	tProgress = FMath::Clamp(tProgress, 0, 1); // tProgress > 1 ? 1 : tProgress;*/
	const FVector _result = FMath::VInterpConstantTo(GetActorLocation(), GetTargetPoint(), DELTATIME, speed);
	SetActorLocation(_result);
}

// Called when the game starts or when spawned
void AMyActorMove::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorMove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToTarget();
	DRAW_SPHERE(GetActorLocation(), 50, FColor::Green, 2);
	DRAW_BOX(GetOriginPoint(), FVector(50), FColor::Red, 2);
	DRAW_BOX(GetTargetPoint(), FVector(50), FColor::Red, 2);
	DRAW_LINE(GetTargetPoint(), GetOriginPoint(), FColor::Red, 2);
}

