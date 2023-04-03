#pragma once
#define WORLD GetWorld()
#define USE_DEBUG 1

#define LOG(catg, msg, ...) if(USE_DEBUG) UE_LOG(catg, Display, TEXT(msg), __VA_ARGS__)
#define LOG_W(catg, msg, ...) if(USE_DEBUG) UE_LOG(catg, Warning, TEXT(msg), __VA_ARGS__)
#define LOG_E(catg, msg, ...) if(USE_DEBUG) UE_LOG(catg, Error, TEXT(msg), __VA_ARGS__)

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

#define CREATE(component,name) CreateDefaultSubobject<component>(name);
#define ATTACH_TO(element, to) element->SetupAttachment(to);

