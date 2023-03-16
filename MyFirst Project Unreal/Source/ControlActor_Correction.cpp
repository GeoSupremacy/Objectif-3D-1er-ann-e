// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlActor_Correction.h"
#include "Kismet/KismetMathLibrary.h"


AControlActor_Correction::AControlActor_Correction(){
	PrimaryActorTick.bCanEverTick = true;
	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	RootComponent = icon;
	
}



void AControlActor_Correction::BeginPlay()
{
	Super::BeginPlay();
	onTimerReached.AddDynamic(this, &AControlActor_Correction::TakeControl);
	onParam.AddDynamic(this, &AControlActor_Correction::TestActionParam);
	onParam.Broadcast(true);
}
void AControlActor_Correction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
	UpdateTimer(timer, maxTime);
		
}


bool AControlActor_Correction::UpdateTimer(float& _timer, const float& _max)
{
	if (!isStarted || !useTimer)
		return false;
	_timer += DELTATIME;
	if (_timer >_max)
	{
		_timer = 0;
		
		if (!isLoopTimer)
		{
			isStarted = false;
			return true;
		}
		onTimerReached.Broadcast();
		return true;
	}
	return false;
}
void AControlActor_Correction::DrawDebug()
{
	DRAW_BOX(GetActorLocation(), FVector(50), FColor::Red, 2);
	DRAW_SPHERE(GetTargetLocation(), 50, FColor::Cyan, 2);
	DRAW_LINE(GetTargetLocation(), GetTargetLocation(), FColor::Magenta, 2);
	const FLinearColor _progressColor = UKismetMathLibrary::LinearColorLerp(FLinearColor::Red, FLinearColor::Green, GetTimerProgressNormalized());
	DRAW_BOX(GetActorLocation() + FVector(0,0,100), (FVector(25) * GetTimerProgressNormalized())+ FVector(10), _progressColor.ToFColor(true), 2);
	DRAW_TEXT(GetActorLocation(), FString::Printf(TEXT("timer %f -> progress %d p"), timer, (int)GetTimerProgress()), FColor::Red, 1.2f);
}
void AControlActor_Correction::TakeControl()
{
	if (!target)
		return;
	target->SetCanMove(true);
	//target->MoveToLocation();
	//target->MoveToLocation(FVector(200, 200, 200));
}

UFUNCTION() void AControlActor_Correction::TestActionParam(bool _param)
{
	return UFUNCTION() void();
}

