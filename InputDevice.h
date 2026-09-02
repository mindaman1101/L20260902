#pragma once

class UInputDevice
{
public:
	UInputDevice();

	virtual ~UInputDevice();

	virtual void GetInput();

private:
	char KeyboardInput;
};