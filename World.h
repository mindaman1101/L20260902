#pragma once
#include "Object.h"
#include <vector>

class AActor;

//UWorld는 UObject이면서 현재 Level에 존재하는 모든 Actor를 관리한다.
class UWorld : public UObject
{
public:
	UWorld();

	virtual ~UWorld();

	void Tick();  //World는 자신이 가진 모든 Actor를 갱신한다.
	void Render();  //World는 자신이 가진 모든 Actor를 그린다.

	template<typename T>
	AActor* SpawnActor();  //World는 요청받은 종류의 Actor를 생성하고 주소를 돌려준다.

	std::vector<AActor*>& GetActors()
	{
		return Actors;  //World는 자신이 관리하는 Actor 목록을 참조로 내어준다.
	}

protected:
	std::vector<AActor*> Actors;  //World는 여러 종류의 Actor 주소를 하나의 목록으로 가지고 있다.
};

template<typename T>
inline AActor* UWorld::SpawnActor()
{
	AActor* NewActor = new T;  //World는 Heap에 요청받은 종류의 Actor를 하나 생성한다.
	Actors.push_back(NewActor);  //World는 생성한 Actor의 주소를 Actor 목록에 등록한다.
	NewActor->SetWorld(this);  //추가

	return NewActor;
}