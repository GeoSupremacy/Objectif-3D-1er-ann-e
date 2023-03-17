#pragma once
#include "Kismet/KismetMathLibrary.h"

#define VERTICAL "Verticale"
#define HORIZONTAL "Horizontale"
#define ROTATE "Rotate"
#define RESET "Reset"
#define MOVE_GRID_VERTICAL "MoveGridVertical"
#define MOVE_GRID_HORIZONTAL "MoveGridHorizontal"

#define PLAYER GetWorld()->GetFirstPlayerController()->InputComponent
#define BIND_AXIS(name, owner, method) GetWorld()->GetFirstPlayerController()->InputComponent->BindAxis(name, owner, method);
#define BIND_ACTION(name, eventType, owner, method) GetWorld()->GetFirstPlayerController()->InputComponent->BindAction(name, eventType, owner, method);
#define BIND_ACTION_PARAMS(del, name, eventType, owner, method, ...)GetWorld()->GetFirstPlayerController()->InputComponent->BindAction<del>(name, eventType, owner, method, __VA_ARGS__);

#define BIND_AXIS_WITH_INPUT(name, owner, method) PlayerInputComponent->BindAxis(name,owner,method);
#define BIND_ACTION_WITH_INPUT(name, eventType, owner, method) PlayerInputComponent->BindAction(name, eventType, owner, method);

