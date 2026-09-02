#pragma once
#include "World.h"
#include "InputDevice.h"

class UEngine
{
public:
	UEngine();

	virtual ~UEngine();

private:
	UWorld* World;
	UInputDevice* InputDevice;
};