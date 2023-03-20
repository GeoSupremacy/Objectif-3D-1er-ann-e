

#include "GridComponent.h"
#include "Utils.h"


// Sets default values for this component's properties
UGridComponent::UGridComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UGridComponent::BeginPlay()
{
	Super::BeginPlay();
	GetOwner()->SetActorLocation(FVector(0, 0, 50));
	
}
void UGridComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	DrawCase();
	
}
void UGridComponent::DrawCase()
{
	int _forward = -200;
	for (size_t i = 1; i <= maxHorizontal; i++)
	{
		int _right = -200;
		_forward = _forward + 200;
		for (size_t j = 1; j <= maxVertical; j++)
		{
			_right = _right + 200;
			DRAW_BOX(FVector(j * 100 + _right, i * 100 + _forward, 50), FVector(50), FColor::Red, 5)
		}
	}
	
}
void UGridComponent::Up()
{
	if (horizontal > maxHorizontal)
		return;
	horizontal += 1;
	//const FVector _direction = GetActorForwardVector().GetSafeNormal();
	//SetActorLocation(GetActorLocation() + (_direction * 300));
}
void UGridComponent::Down()
{
	if (horizontal < 0)
		return;
	horizontal -= 1;
	//const FVector _direction = GetActorForwardVector().GetSafeNormal();
	//SetActorLocation(GetActorLocation() + (_direction * -300));
}
void UGridComponent::Left()
{
	if (vertical < 0)
		return;
	vertical -= 1;
	//const FVector _direction = GetActorRightVector().GetSafeNormal();
	//SetActorLocation(GetActorLocation() + (_direction * -300));
}
void UGridComponent::Right()
{
	if (vertical > maxVertical)
		return;
	vertical += 1;
	//const FVector _direction = GetActorRightVector().GetSafeNormal();
	//SetActorLocation(GetActorLocation() + (_direction * 300));
}

