// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Utils.h"
#include "Mario.h"
#include "Components/BoxComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class MARIO_CORRECTION_API ABlock : public AActor
{
    GENERATED_BODY()
protected:
    UPROPERTY(EditAnywhere)
        TObjectPtr<UStaticMeshComponent> meshBlock = nullptr;
    UPROPERTY(EditAnywhere)
        TObjectPtr<UBoxComponent> downTrigger = nullptr;

public:
    ABlock();
private:
    virtual void BeginPlay() override;
    void Init();
    UFUNCTION() void OnDownTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);
protected:
    virtual void DownBehaviour(AMario* _Mario);
};
