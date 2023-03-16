// Fill out your copyright notice in the Description page of Project Settings.
//Quand le J ne touche à rien pendant un temps indeterminer, mouve la caméra autour
//Comment le moteur sait si le joeurs est passif ou non
//Moteur->Edit CanPassif Maxtemp
//Bool qui check si on ne touche rien
//si touche rien timer active
//Fin timer retourn camera move
//CheckActive
// UpdateTimer
//CameraMove
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Galaxy.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringarmComponent.h"
#include "TimerComponent.h"
#include "SpaceCrab_Correction.generated.h"

UCLASS()
class MYFIRSTPROJECT_API ASpaceCrab_Correction : public AActor
{
	GENERATED_BODY()
#pragma region f/p
	/*DECLARE_DYNAMIC_MULTICAST_DELEGATE(OnShipAxis);
	OnShipAxis onShipAxis;
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FonShipMovement, float, _axis);
	FonShipMovement onShipMovement;*/

	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> shipMesh = nullptr; // A* raw ptr
	UPROPERTY(EditAnywhere, Category = "Galaxie")
		TObjectPtr<AGalaxy> currentGalaxy = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UTimerComponent> customTimer = nullptr;
	FVector initLocation;
	FVector initScale;
	FVector shipVelocity;

	UPROPERTY(EditAnywhere)
		float passiveModeyawSpeed = 1;

	float forwardVelocity = 0, rotateAxis =0, pitchAxis; //(x,y)
	bool passiveModeEnable = false, isMoving = false;
	FRotator initRotation;
	
#pragma endregion f/p
#pragma region Moving
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (Umin = 0, ClampMin = 0))
		float bankAngle = 45;
#pragma region Weight
	UPROPERTY(EditAnywhere, Category = "Movement|Weight", meta = (Umin = 0, ClampMin = 0))
		float mase = 1;
	UPROPERTY(EditAnywhere, Category = "Movement|Weight", meta = (Umin = 0, ClampMin = 0))
		float rotateWeight = 1;

	UPROPERTY(EditAnywhere, Category = "Movement|Weight", meta = (Umin = 0, ClampMin = 0))
		float pitchWeight = 1;
#pragma endregion Weight
#pragma region Speed
	

	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float horizontaleSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float verticaleSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float altitudeSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float rotateSpeed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement|Speed", meta = (Umin = 0, ClampMin = 0))
		float scaleSpeed = 100;
#pragma endregion Speed
#pragma region CanAction
	UPROPERTY(EditAnywhere, Category = "Movement|Action")
		bool canMove = true;
	UPROPERTY(EditAnywhere, Category = "Movement|Action")
		bool canRotate = true;
	UPROPERTY(EditAnywhere, Category = "Movement|Action")
		bool canScale = true;
	UPROPERTY(EditAnywhere, Category = "Movement|Camera")
		bool canCamera = true;

	UPROPERTY(EditAnywhere, Category = Debug)
		bool canSeeAxe = false;
#pragma endregion CanAction
#pragma endregion Moving
#pragma region Ascenseur
	/*FORCEINLINE bool GetEndTimer() const { return timer > maxTimeDelay; }
	FORCEINLINE float GetTimerProgress() const { return timer / maxTimeDelay; }
	FORCEINLINE bool GetActive() const { return isActive; };*/

	FORCEINLINE void SetCanMove(const bool& _value) { canMove = _value; }
	FORCEINLINE void SetCanRotate(const bool& _value) { canRotate = _value; }
	FORCEINLINE void SetCanScaling(const bool& _value) { canScale = _value; }
	FORCEINLINE void SetCanCamera(const bool& _value) { canCamera = _value; }

	FORCEINLINE void SetupInput();
	FORCEINLINE void SetHorizontal(float _axis);
	FORCEINLINE void SetVertical(float _axis);
	FORCEINLINE void SetRotation(float _axis);
	FORCEINLINE void SetScale(float _axis);
	FORCEINLINE void SetAltitude(float _axis);
	FORCEINLINE void Respawn() { SetActorLocation(initLocation); }
#pragma endregion Ascenseur
#pragma region Constructor
public:
	ASpaceCrab_Correction();
#pragma endregion Constructor
#pragma region UE_METHODS
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
#pragma endregion UE_METHODS
#pragma region CUSTOM_METHODS
private:
	UFUNCTION() void StopRotation();
	UFUNCTION() void StopMovement();
	UFUNCTION() void StopScaling();
	UFUNCTION() void StopCamera();
	void View(float _axis);
	void InitShip();
	void SetDynamicScale(float _axis);//
	void DrawDebug();
	void AddFloatingBehaviour();
	void AddPitch(float _axis);
#pragma region PassifMod 
	void RotatorAroundCamera();
	void ResetCameraRotation();
	UFUNCTION() void PassiveModeEnable();
	UFUNCTION() void PassiveModeDisable();
	UFUNCTION() void MovingDetection(float _value);
#pragma endregion PassifMod
#pragma endregion CUSTOM_METHODS
};
#pragma region my
//void UpdateTimer();
	//void CheckActive();
#pragma region PassifMod
/*UPROPERTY(EditAnywhere, Category = PassifMod, meta = (UImin = 0, ClampMin = 0))
	float maxTimeDelay = 10;
UPROPERTY(EditAnywhere, Category = PassifMod)
	bool canPassifMode = true;
UPROPERTY()
	bool timerStarted = false;

FondEndTimer oneEndTimer;
float timer = 0;
bool isActive = true;*/
#pragma endregion PassifMod
#pragma endregion my