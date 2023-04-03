// Fill out your copyright notice in the Description page of Project Settings.


#include "Mario.h"

// Sets default values
AMario::AMario()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	arm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm->SetupAttachment(RootComponent);
	camera->SetupAttachment(arm);
	bUseControllerRotationYaw = true;

}

// Called when the game starts or when spawned
void AMario::BeginPlay()
{
	Super::BeginPlay();
	marioSnap = FSnapshot(GetTransform());
}

// Called every frame
void AMario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMario::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Horizontal", this, &AMario::MoveForward);
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AMario::Jump);
}

void AMario::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector() * _axis);
	if (FMath::Abs(_axis) == 0)
		return;
	GetMesh()->SetRelativeRotation(FRotator(0, -90 * _axis, 0));
}
void AMario::OnRespawnDelayed()
{
	marioSnap.Reload(this);
	EnableInput(GetWorld()->GetFirstPlayerController());
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	isDead = false;
}
void AMario::Die()
{
	isDead = true;
	DisableInput(GetWorld()->GetFirstPlayerController());
	GetWorldTimerManager().SetTimer(respawnDelay, this, &AMario::OnRespawnDelayed, 2, false);
}

