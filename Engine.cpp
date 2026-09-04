#include <algorithm>
#include "Engine.h"
#include "World.h"
#include "Floor.h"
#include "Monster.h"
#include "Goal.h"
#include "Wall.h"
#include "Player.h"
#include "Actor.h"
#include "InputDevice.h"
#include <conio.h>

//프로그램 시작 시에는 아직 생성된 Engine이 없다.
UEngine* UEngine::Instance = nullptr;

UEngine::UEngine()
{
}

UEngine::~UEngine()
{
	if (World)
	{
		delete World;
		World = nullptr;
	}
}

UEngine* UEngine::GetInstance()
{
	//Engine이 아직 없을 때만 새 Engine을 생성한다.
	if (!Instance)
	{
		Instance = new UEngine();
	}

	return Instance;  //몇 번 요청해도 같은 Engine의 주소를 돌려준다.
}

void UEngine::Init()
{
	InputDevice = new FInputDevice();  //Engine은 입력을 담당할 장치를 생성한다.

	//map loading
	World = new UWorld();  //Engine은 Actor들이 존재할 World를 생성한다.

	OpenLevel("1.umap");  //Engine은 Map을 열어 World를 구성한다.
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		Input();  //Engine은 InputDevice에게 현재 입력을 확인시킨다.
		World->Tick();  //Engine은 World에게 모든 Actor를 갱신시킨다.
		//system("cls");
		World->Render();  //Engine은 World에게 모든 Actor를 그리게 한다.
	}
}

void UEngine::Exit()
{

}

void UEngine::OpenLevel(std::string MapName)
{
	//OpenLevel
	//Engine은 숫자 Map Data로 각 칸에 배치할 Object 종류를 표현한다.
	char Map[10][10] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 1},  //2 = Player
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 3, 0, 1},  //3 = Monster
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 4, 1},  //4 = 목적지
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	//Engine은 Map의 모든 Y행과 X열을 한 칸씩 확인한다.
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (Map[Y][X] == 1)
			{
				AActor* NewActor = World->SpawnActor<AWall>();
				NewActor->Location = FVector2D(X, Y);
			}
			else if (Map[Y][X] == 2)
			{
				AActor* NewActor = World->SpawnActor<APlayer>();
				NewActor->Location = FVector2D(X, Y);
			}
			else if (Map[Y][X] == 3)
			{
				AActor* NewActor = World->SpawnActor<AMonster>();
				NewActor->Location = FVector2D(X, Y);
			}
			else if (Map[Y][X] == 4)
			{
				AActor* NewActor = World->SpawnActor<AGoal>();
				NewActor->Location = FVector2D(X, Y);
			}

			//Object 종류와 관계없이 모든 Map 칸에는 Floor를 하나 생성한다.
			AActor* NewActor = World->SpawnActor<AFloor>();
			NewActor->Location = FVector2D(X, Y);
		}
	}

	//bubble sort, selection sort, quick sort, merge sort...
	//
	//5, 3, 1, 2, 4
	//3, 5, 1, 2, 4
	//1, 5, 3, 2, 4
	//1, 3, 5, 2, 4
	//1, 2, 5, 3, 4
	//1, 2, 3, 5, 4
	//1, 2, 3, 4, 5
	//
	//for (int i = 0; i < GetWorld()->GetActors().size(); ++i)
	//{
	//	for (int j = i + 1; j < GetWorld()->GetActors().size(); j++)
	//	{
	//		if (GetWorld()->GetActors()[i]->Layer > GetWorld()->GetActors()[j]->Layer)
	//		{
	//			AActor* Temp = GetWorld()->GetActors()[i];
	//			GetWorld()->GetActors()[i] = GetWorld()->GetActors()[j];
	//			GetWorld()->GetActors()[j] = Temp;
	//		}
	//	}
	//}
	//
	//std::sort(GetWorld()->GetActors().begin(), GetWorld()->GetActors().end(), UEngine::Compare);
	//
	//무명 함수
	//람다 함수
	//
	//람다 함수 사용 예시: AsyncLoadTexture([]() { };) 비동기 함수에 많이 씀. 콜백 함수

	//Engine은 Actor가 낮은 Layer부터 높은 Layer 순서로 그려지도록 목록을 정렬한다.
	std::sort(GetWorld()->GetActors().begin(), GetWorld()->GetActors().end(),
		[&](AActor* A, AActor* B) {
			return (A->Layer < B->Layer);  //A의 Layer가 더 작으면 A를 B보다 앞에 둔다.
		}
	);
}

//bool UEngine::Compare(AActor* A, AActor* B)
//{
//	if (A->Layer < B->Layer)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

UWorld* UEngine::GetWorld() const
{
	return World;
}

const FRenderer* UEngine::GetRenderer()
{
	return Renderer;
}

void UEngine::Input()
{
	InputDevice->Input();  //Engine은 InputDevice에게 현재 Key 입력을 확인하라고 요청한다.
}