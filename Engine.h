#pragma once
#include "World.h"
#include "InputDevice.h"
#include "Renderer.h"

class UEngine
{
public:
	UEngine();

	virtual ~UEngine();

private:
	UWorld* World;
	UInputDevice* InputDevice;
	URenderer* Renderer;
};