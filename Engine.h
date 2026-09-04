#pragma once
#include "Object.h"
#include <string>

class UWorld;
class FInputDevice;
class FRenderer;
class AActor;

//UEngine은 UObject이면서 World, InputDevice, Renderer를 관리하고 Game Loop를 실행한다.
class UEngine : public UObject
{
protected:
	UEngine();

	static UEngine* Instance;  //Engine Class는 유일한 Engine 객체의 주소를 공유한다.
public:
	virtual ~UEngine();

	static UEngine* GetInstance();  //어디서든 하나뿐인 Engine의 주소를 요청할 수 있다.

	void Init();  //Engine은 실행에 필요한 장치와 World를 준비한다.
	void Run();  //Engine은 입력, 갱신, 그리기를 반복한다.
	void Exit();  //Engine은 실행을 끝내고 정리한다.

	void OpenLevel(std::string MapName);  //Engine은 Map Data를 읽어 World에 Actor를 배치한다.

	static bool Compare(AActor* A, AActor* B);  //Engine은 두 Actor의 그리기 순서를 비교할 수 있다.

	virtual UWorld* GetWorld() const override;  //Engine은 자신이 관리하는 World의 주소를 돌려준다.
	const FRenderer* GetRenderer();  //Engine은 자신이 관리하는 Renderer의 주소를 돌려준다.

	FInputDevice* GetInputDevice()
	{
		return InputDevice;  //Engine은 자신이 관리하는 InputDevice의 주소를 돌려준다.
	}

protected:
	void Input();
	bool bIsRunning = true;  //Engine은 Game Loop를 계속 실행할지를 상태로 가지고 있다.
	FInputDevice* InputDevice = nullptr;  //Engine은 입력을 담당할 InputDevice의 주소를 가지고 있다.
	FRenderer* Renderer = nullptr;  //Engine은 출력을 담당할 Renderer의 주소를 가지고 있다.
};


#define GEngine		UEngine::GetInstance()