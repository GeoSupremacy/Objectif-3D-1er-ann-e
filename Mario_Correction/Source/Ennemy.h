// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include"EnnemyMovingComponent.h"
#include"Components/BoxComponent.h"
#include "Mario.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ennemy.generated.h"

UCLASS()
class MARIO_CORRECTION_API AEnnemy : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = InitE)
		TObjectPtr<USceneComponent> root = nullptr;
	UPROPERTY(EditAnywhere, Category = InitE)
		TObjectPtr<UBoxComponent> globalTrigger = nullptr;
	UPROPERTY(EditAnywhere, Category = InitE)
		TObjectPtr<UBoxComponent> upTigger = nullptr;
	UPROPERTY(EditAnywhere, Category = InitE)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
protected:
	UPROPERTY(EditAnywhere, Category = InitE)
		TObjectPtr<UEnnemyMovingComponent> moveComponent = nullptr;

	bool isDead = false;
public:	
	AEnnemy();

private:
	UFUNCTION() void OnGlobalTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION() void OnUpTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void GlobalBehaviour(AMario* _mario);
	virtual void UpBehaviour(AMario* _mario);
	void Init();
	virtual void Die();
};
