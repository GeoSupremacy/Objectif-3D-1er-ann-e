#pragma once
#include "Kismet/KismetMathLibrary.h"

#define LOG(catg, msg, ...) UE_LOG(catg, Display, TEXT(msg), __VA_ARGS__)
#define LOG_W(catg, msg, ...) UE_LOG(catg, Warning, TEXT(msg), __VA_ARGS__)
#define LOG_E(catg, msg, ...) UE_LOG(catg, Error, TEXT(msg), __VA_ARGS__)

#define LOG_SCREEN(time, color, msg, ...) GEngine->AddOnScreenDebugMessage(-1, time, \
											color, FString::Printf(TEXT(msg), __VA_ARGS__))
/*
#define Color(C) FColor::C
#define DECLARE_LOG_CATEGORY_EXTERN(a, b, c)
#define DEFINE_LOG_CATEGORY(d)

DECLARE_LOG_CATEGORY_EXTERN(P1, Log, All)
DEFINE_LOG_CATEGORY(P1)

DECLARE_LOG_CATEGORY_EXTERN(CCC, Log, All)
DEFINE_LOG_CATEGORY(CCC)

DECLARE_LOG_CATEGORY_EXTERN(Yoni, Log, All)
DEFINE_LOG_CATEGORY(Yoni)
*/
#define WORLD GetWorld()
#define DELTATIME WORLD->DeltaTimeSeconds

#define USE_DEBUG 1

//exemple preposses activation
/*
#define EX 1
#if EX
#define A 100
#else 
#define A 1000
#endif
*/

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

#define LERP_COLOR(from, to, t) UKismetMathLibrary::LinearColorLerp(from.ReinterpretAsLinear(), to.ReinterpretAsLinear(), t).ToFColor(true);

#define TO_CHAR(string) *string
#define TO_STRING(notString) notString.ToString()
#define TO_CHAR_STR(text) TO_CHAR(TO_STRING(text))

#define BIND(eventName, owner, name) eventName.AddDynamic(owner, name)
#define INVOKE(eventName, ...) eventName.Broadcast( __VA_ARGS__);

#define LERP(A, B, T) FMath::Lerp(A, B, T)
typedef FColor C;
typedef FVector Vec;