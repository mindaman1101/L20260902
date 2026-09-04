#include "InputDevice.h"
#include <conio.h>

FInputDevice::FInputDevice()
{
}

FInputDevice::~FInputDevice()
{
}

int FInputDevice::Input()
{
	//InputDevice는 입력이 있는지 먼저 확인하여 Game Loop가 멈추지 않게 한다.
	if (_kbhit())
	{
		KeyCode = _getch();  //입력이 있으면 실제 Key Code를 받아 저장한다.
	}
	else
	{
		KeyCode = 0;  //입력이 없으면 아무 Key도 없다는 뜻으로 0을 저장한다.
	}

	return KeyCode;
}