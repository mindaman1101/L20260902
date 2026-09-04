#pragma once

//FInputDevice는 운영체제에서 Key 입력을 받아 Engine에 전달한다.
class FInputDevice
{
public:
	FInputDevice();

	virtual ~FInputDevice();

	int Input();  //InputDevice는 현재 입력을 확인하고 Key Code를 저장한다.

	inline int GetKeyCode()
	{
		return KeyCode;
	}

protected:
	int KeyCode = 0;  //InputDevice는 현재 입력 상태를 Key Code로 가지고 있다.
};