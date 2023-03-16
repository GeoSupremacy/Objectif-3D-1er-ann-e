// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define BIND_AXIS(name, owner, method) GetWorld()->GetFirstPlayerController()->InputComponent->BindAxis(name, owner, method);
#define BIND_ACTION(name, eventType, owner, method) GetWorld()->GetFirstPlayerController()->InputComponent->BindAction(name, eventType, owner, method);
#define BIND_ACTION_PARAMS(del, name, eventType, owner, method, ...)GetWorld()->GetFirstPlayerController()->InputComponent->BindAction<del>(name, eventType, owner, method, __VA_ARGS__);



#define HORIZONTAL "Horizontal"
#define VERTICAL "Verticale"
#define ROTATE "Rotate"
#define SCALE "Scale"
#define RESPAWN "Respawn"
#define ALTITUDE "Altitude"
#define VIEW "View"

#define ACTIVE isActive =true;