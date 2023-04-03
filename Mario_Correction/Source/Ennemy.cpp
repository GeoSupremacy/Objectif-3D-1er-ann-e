// Fill out your copyright notice in the Description page of Project Settings.


#include "Ennemy.h"
#include "Utils.h"

// Sets default values
AEnnemy::AEnnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CREATE(UStaticMeshComponent, "Mesh");
	root = CREATE(USceneComponent, "Root");
	RootComponent = root;
	globalTrigger = CREATE(UBoxComponent, "G_Trigger");
	upTigger = CREATE(UBoxComponent, "U_Trigger");
	moveComponent = CREATE(UEnnemyMovingComponent, "MoveComponent");

	ATTACH_TO(mesh, RootComponent);
	ATTACH_TO(globalTrigger, RootComponent);
	ATTACH_TO(upTigger, RootComponent);

	AddOwnedComponent(moveComponent);
}
void AEnnemy::BeginPlay()
{
	Super::BeginPlay();
	Init();
}
void AEnnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AEnnemy::Init()
{
	if (!globalTrigger || !upTigger)
		return;
	globalTrigger->OnComponentBeginOverlap.AddDynamic(this, &AEnnemy::OnGlobalTrigger);
	upTigger->OnComponentBeginOverlap.AddDynamic(this, &AEnnemy::OnUpTrigger);
}
UFUNCTION() void AEnnemy::OnGlobalTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMario* _mario = Cast<AMario>(OtherActor);
	if (!_mario)
		return;
	GlobalBehaviour(_mario);
}
UFUNCTION() void AEnnemy::OnUpTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMario* _mario = Cast<AMario>(OtherActor);
	if (!_mario)
		return;
	UpBehaviour(_mario);
}
void AEnnemy::GlobalBehaviour(AMario* _mario)
{
}
void AEnnemy::UpBehaviour(AMario* _mario)
{
}
void AEnnemy::Die()
{
	
	if (moveComponent)
		moveComponent->Stop();
}
