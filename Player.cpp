#include "Player.h"
#include "Engine.h"
#include "InputDevice.h"
#include "World.h"
#include <vector>

APlayer::APlayer()
{
	Shape = 'P';  //Player는 화면에서 P로 보인다.
	Layer = 100;  //Player는 Floor, Wall, Goal보다 나중에 그려진다.
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	FVector2D NextLocation = Location;

	int KeyCode = GEngine->GetInputDevice()->GetKeyCode();
	if (KeyCode == 'w')
	{
		NextLocation.Y--;  //위쪽으로 한 칸 이동
	}
	if (KeyCode == 's')
	{
		NextLocation.Y++;  //아래쪽으로 한 칸 이동
	}
	if (KeyCode == 'a')
	{
		NextLocation.X--;  //왼쪽으로 한 칸 이동
	}
	if (KeyCode == 'd')
	{
		NextLocation.X++;  //오른쪽으로 한 칸 이동
	}

	std::vector<AActor*>& Actors = GetWorld()->GetActors();

	bool bCanMove = true;

	for (AActor* Actor : Actors)
	{
		if (Actor == this || Actor->bIsCollisionEnable == false)  //Actor가 나거나 collision이 막혀있지 않다면 다음 Actor 확인
		{
			continue;
		}
		else if (Actor->Location.X == NextLocation.X && Actor->Location.Y == NextLocation.Y)  //Actor가 내가 아니고 collision이 막혀있을때 위치가 나랑 같으면 움직일 수 없음
		{
			bCanMove = false;
			break;
		}
	}

	if (bCanMove)
	{
		Location = NextLocation;
	}
}