#include "Renderer.h"
#include "Actor.h"
#include <windows.h> 
#include <iostream>

FRenderer::FRenderer()
{
	BufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);  //반환은 우리가 만든 버퍼포인터를 줌
	BufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);

	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.bVisible = false;
	CursorInfo.dwSize = 1;
	SetConsoleCursorInfo(BufferHandle[0], &CursorInfo);
	SetConsoleCursorInfo(BufferHandle[1], &CursorInfo);
}

FRenderer::~FRenderer()
{
	CloseHandle(BufferHandle[0]);
	CloseHandle(BufferHandle[1]);
}

void FRenderer::Render(AActor* DrawActor) const
{
	//Renderer는 Actor의 2D 위치를 Console Cursor 위치로 바꾼다.
	COORD Position = { (SHORT)DrawActor->Location.X, (SHORT)DrawActor->Location.Y };

	//Renderer는 운영체제에게 Console Cursor를 Actor 위치로 옮겨달라고 요청한다.
	SetConsoleCursorPosition(BufferHandle[CurrentBufferIndex], Position);

	char Buffer[2] = { 0, };  //[P] [0]
	Buffer[0] = DrawActor->Shape;
	WriteConsole(BufferHandle[CurrentBufferIndex], Buffer, 1, nullptr, nullptr);

	//std::cout << DrawActor->Shape;  //Renderer는 옮겨진 위치에 Actor의 모양을 출력한다.
}

void FRenderer::Clear()
{
	COORD Coord{ 0, 0 };
	DWORD DW;
	FillConsoleOutputCharacter(BufferHandle[CurrentBufferIndex], ' ', 80 * 25, Coord, &DW);
}

void FRenderer::Present()
{
	SetConsoleActiveScreenBuffer(BufferHandle[CurrentBufferIndex]);
	CurrentBufferIndex++;
	CurrentBufferIndex = CurrentBufferIndex % 2;
}