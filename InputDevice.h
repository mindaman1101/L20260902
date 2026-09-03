#pragma once

class FInputDevice
{
public:
	FInputDevice();

	virtual ~FInputDevice();

	int Input();

	inline int GetKeyCode()
	{
		return KeyCode;
	}

protected:
	int KeyCode = 0;
};