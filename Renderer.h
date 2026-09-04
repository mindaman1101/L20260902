#pragma once
#include <windows.h>

class AActor;

//FRenderer는 Actor의 위치와 모양을 받아 Console 화면에 출력한다.
class FRenderer
{
public:
	FRenderer();

	virtual ~FRenderer();

	void Render(AActor* DrawActor) const;  //Renderer는 전달받은 Actor를 그리며 자기 상태는 바꾸지 않는다.
	void Clear();  //화면 지우기
	void Present();

	HANDLE BufferHandle[2];

	int CurrentBufferIndex = 0;
};