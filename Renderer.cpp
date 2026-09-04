#include "Renderer.h"
#include "Actor.h"
#include <windows.h> 
#include <iostream>

FRenderer::FRenderer()
{

}

FRenderer::~FRenderer()
{
}

void FRenderer::Render(AActor* DrawActor) const
{
	//Renderer는 Actor의 2D 위치를 Console Cursor 위치로 바꾼다.
	COORD Position = { (SHORT)DrawActor->Location.X, (SHORT)DrawActor->Location.Y };
	//Renderer는 운영체제에게 Console Cursor를 Actor 위치로 옮겨달라고 요청한다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);

	std::cout << DrawActor->Shape;  //Renderer는 옮겨진 위치에 Actor의 모양을 출력한다.
}