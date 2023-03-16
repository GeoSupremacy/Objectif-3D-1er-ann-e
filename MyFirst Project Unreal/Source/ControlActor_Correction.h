#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstActor.h"
#include "Util.h"
#include "Components/BillboardComponent.h"
#include "ControlActor_Correction.generated.h"

UCLASS()
class MYFIRSTPROJECT_API AControlActor_Correction : public AActor
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerReached);
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionParam, bool, _param);

		UPROPERTY(EditAnywhere)
		TObjectPtr<UBillboardComponent> icon = nullptr;

		UPROPERTY(EditAnywhere, Category = Control)
		TObjectPtr<AMyFirstActor> target = nullptr;
	UPROPERTY(EditAnywhere, Category = Timer)
		bool useTimer = true;
	UPROPERTY(EditAnywhere, Category = Timer, meta =(EdiCondition = "userTimer", UIMin =0, ClampMin =0))
		float maxTime = 5;
	UPROPERTY(EditAnywhere, Category = Timer, meta = (EdiCondition = "userTimer"))
		bool isLoopTimer = false;
	UPROPERTY(EditAnywhere, Category = Timer, meta = (EdiCondition = "userTimer"))
		bool isStarted = true;

	FOnTimerReached onTimerReached;
	FActionParam onParam;
	float timer = 0;
public:	
	AControlActor_Correction();
	FORCEINLINE float GetTimerProgress() const { return (timer / maxTime) * 100.f; }
	FORCEINLINE float GetTimerProgressNormalized() const { return (timer / maxTime); }
	FORCEINLINE FVector GetTargetLocation() const { return target ? target->
		GetActorLocation() : GetActorLocation(); }
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	bool UpdateTimer(float& _timer, const float& _max);
	void DrawDebug();
	UFUNCTION() void TakeControl();
	UFUNCTION() void TestActionParam(bool _param);
};
