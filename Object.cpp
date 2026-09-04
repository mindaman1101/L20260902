#include "Object.h"
#include "World.h"

//UObject는 처음 생성될 때 아직 속한 World가 없다.
UObject::UObject() : World(nullptr)
{
}

UObject::~UObject()
{
}

UWorld* UObject::GetWorld() const
{
	return World;  //현재 Object가 알고 있는 World의 주소를 돌려준다.
}

void UObject::SetWorld(UWorld* NewWorld)
{
	World = NewWorld;
}