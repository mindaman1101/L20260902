#include "World.h"
#include "Actor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();  //World는 각 Actor에게 자신의 상태를 갱신하라고 요청한다.
	}

}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();  //World는 각 Actor에게 자신을 그리라고 요청한다.
	}

}