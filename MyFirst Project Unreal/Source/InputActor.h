// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputActor.generated.h"

UCLASS()
class MYFIRSTPROJECT_API AInputActor : public AActor
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere)
			TObjectPtr<UStaticMeshComponent> mesh = nullptr; // A* raw ptr
		UPROPERTY(EditAnywhere, Category = Movement)
			float horizontaleSpeed = 1;
		UPROPERTY(EditAnywhere, Category = Movement)
			float verticaleSpeed = 1;
		UPROPERTY(EditAnywhere, Category = Movement)
			float rotateSpeed = 1;
		UPROPERTY(EditAnywhere, Category = Movement)
			float scaleSpeed = 1;

		UPROPERTY(EditAnywhere, Category = Movement)
			FVector maxScale;
		//Scale initiale
		FVector initScale;
		FVector initLocation;
public:	
	// Sets default values for this actor's properties
	AInputActor();
	#pragma region CUSTOM_METHODS
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void InitObject();
	void SetupInput();
	void SetHorizontal(float _axis);
	void SetVertical(float _axis);
	void SetRotation(float _axis);
	void SetScale(float _axis);
	void SetDynamicScale(float _axis);//
	void UpdateScale(const float &_speed);//
	void DisplayVectorObject();
	void Respawn();
	void Other(float _a, int _b, bool _c);
};
