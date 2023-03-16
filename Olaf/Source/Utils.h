#pragma once
#include "Kismet/KismetMathLibrary.h"

#define LOG(catg, msg, ...) UE_LOG(catg, Display, TEXT(msg), __VA_ARGS__)
#define LOG_W(catg, msg, ...) UE_LOG(catg, Warning, TEXT(msg), __VA_ARGS__)
#define LOG_E(catg, msg, ...) UE_LOG(catg, Error, TEXT(msg), __VA_ARGS__)

#define LOG_SCREEN(time, color, msg, ...) GEngine->AddOnScreenDebugMessage(-1, time, \
											color, FString::Printf(TEXT(msg), __VA_ARGS__))
#define USE_DEBUG 1

#define WORLD  GetWorld()

#define DRAW_SPHERE( from, radius, color, size) \
	if (USE_DEBUG) DrawDebugSphere(WORLD, from, radius, 20, color, false, -1,0 , size);

#define DRAW_SPHERE_DEF( from, radius,def , color, size)\
	if (USE_DEBUG)\
		DrawDebugSphere(WORLD, from, radius, def, color, false, -1,0 , size);

#define DRAW_BOX( from, extents, color, size) \
	if (USE_DEBUG)\
		DrawDebugBox(WORLD, from, extents, color, false, -1,0 , size);

#define DRAW_LINE( from, to, color, size) \
	if (USE_DEBUG)\
	 	DrawDebugLine(WORLD, from, to, color, false, -1,0 , size);

#define DRAW_TEXT( from, text, color, size) \
	if (USE_DEBUG)\
		 DrawDebugString(WORLD, from, text, nullptr, color,DELTATIME , false, size);





#define DELTATIME GetWorld()->DeltaTimeSeconds

#define LERP(A, B, T) FMath::Lerp(A, B, T)

#define ATTACH_TO(owner, to) owner->SetupAttachment(to); 

#define FPC GetWorld()->GetFirstPlayerController()


#define CREATE_TO(owner,to) CreateDefaultSubobject<owner>(to);

#define OWNER GetOwner()