// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnnemyMovingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MARIO_CORRECTION_API UEnnemyMovingComponent : public UActorComponent
{
    GENERATED_BODY()
        UPROPERTY(EditAnywhere, Category = MoveEnemy)
        float sizeMovement = 400;
    UPROPERTY(EditAnywhere, Category = MoveEnemy)
        float speed = 100;
    FVector initLocation, targetLocation, currentLocation;
    bool canMove = true,
        toTarget = true;

public:
    UEnnemyMovingComponent();
    void Stop();
private:
    void Init();
    FORCEINLINE void SetOwnerLocation(const FVector& _location) { GetOwner()->SetActorLocation(_location); }
    FORCEINLINE FVector GetOwnerLocation() const { return GetOwner()->GetActorLocation(); }
    FORCEINLINE void SetOwnerRotation(const FRotator& _rotation) { GetOwner()->SetActorRotation(_rotation); }
    FORCEINLINE FRotator GetOwnerRotation() const { return GetOwner()->GetActorRotation(); }

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    void Move();
    bool IsAtLocation() const;
};
