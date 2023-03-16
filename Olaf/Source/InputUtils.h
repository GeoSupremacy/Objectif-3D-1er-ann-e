#pragma once
#include "Kismet/KismetMathLibrary.h"

#define VERTICAL "Verticale"
#define HORIZONTAL "Horizontale"
#define ROTATE "Rotate"
#define RESET "Reset"

#define PLAYER  GetWorld()->GetFirstPlayerController()->InputComponent
#define BIND_AXIS(name, owner, method) GetWorld()->GetFirstPlayerController()->InputComponent->BindAxis(name, owner, method);
#define BIND_ACTION(name, eventType, owner, method) GetWorld()->GetFirstPlayerController()->InputComponent->BindAction(name, eventType, owner, method);
#define BIND_ACTION_PARAMS(del, name, eventType, owner, method, ...)GetWorld()->GetFirstPlayerController()->InputComponent->BindAction<del>(name, eventType, owner, method, __VA_ARGS__);