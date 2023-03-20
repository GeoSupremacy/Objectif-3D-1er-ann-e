// Fill out your copyright notice in the Description page of Project Settings.


#include "GridPawnCorr.h"
#include "Utils.h"
#include "InputUtils.h"
#include "GameModeGridCorr.h"


AGridPawnCorr::AGridPawnCorr()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CREATE_TO(UStaticMeshComponent, "Mesh");
	RootComponent = mesh;
	camera = CREATE_TO(UCameraComponent, "Camera");
	springArm = CREATE_TO(USpringArmComponent, "SpringArm");
	grid = CREATE_TO(AGridActorCorr, "grid");
	ATTACH_TO(springArm, RootComponent);
	ATTACH_TO(camera, springArm);
}
void AGridPawnCorr::BeginPlay()
{
	Super::BeginPlay();
	IniPawnCorr();
}
void AGridPawnCorr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AGridPawnCorr::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	BIND_ACTION_WITH_INPUT(UP, EInputEvent::IE_Pressed, this, &AGridPawnCorr::UpMove);
	BIND_ACTION_WITH_INPUT(DOWN, EInputEvent::IE_Pressed, this, &AGridPawnCorr::DownMove);
	BIND_ACTION_WITH_INPUT(LEFT, EInputEvent::IE_Pressed, this, &AGridPawnCorr::LeftMove);
	BIND_ACTION_WITH_INPUT(RIGHT, EInputEvent::IE_Pressed, this, &AGridPawnCorr::RightMove);
	BIND_ACTION_WITH_INPUT(SELECT, IE_Pressed, this, &AGridPawnCorr::SelectGridCell);
}

void AGridPawnCorr::UpMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(1, 0, 0));
}
void AGridPawnCorr::DownMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(-1, 0, 0));
}
void AGridPawnCorr::LeftMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(0, -1, 0));
}
void AGridPawnCorr::RightMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(0, 1, 0));
}
void AGridPawnCorr::IniPawnCorr()
{
	grid = GetGrid();
	if (!grid)
		return;
	grid->SnapToStart(this);
	SelectGridCell();
}
TObjectPtr<AGridActorCorr> AGridPawnCorr::GetGrid() const
{
	AGameModeGridCorr* _gm = GetWorld()->GetAuthGameMode<AGameModeGridCorr>();
	if (!_gm)
		return nullptr;
	return _gm->GetGrid();
}
void AGridPawnCorr::SelectGridCell()
{
	if (!grid)
		return;
	grid->PickLocation(this);
}