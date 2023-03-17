

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
	int H = -200;
	for (size_t i = 1; i <= 6; i++)
	{
		int k = -200;
		H = H+ 200;
		for (size_t j = 1; j <= 6; j++)
		{
			k = k +200;
			DRAW_BOX(FVector(j*100 +k, i*100 + H ,50), FVector(50), FColor::Red, 5)
		}
	}
	
}
void UGridComponent::CheckMovement()
{

}

