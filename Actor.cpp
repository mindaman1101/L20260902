#include "Actor.h"
#include "Engine.h"
#include "Renderer.h"

//Actor는 처음 생성될 때 (0, 0)에 있고 빈 모양을 가진다.
AActor::AActor() : Location(0, 0), Shape(' ')
{
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}


void AActor::Render()
{
	//Actor는 Engine의 Renderer에게 자기 자신을 그려달라고 요청한다.
	GEngine->GetRenderer()->Render(this);
}

UWorld* AActor::GetWorld() const
{
	return World;
}