#pragma once
#include "Vector2D.h"

class AActor
{
public:
	AActor();

	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	FVector2D Position;
};