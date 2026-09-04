#include "Player.h"
#include "Engine.h"
#include "InputDevice.h"

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
	//Player는 Engine의 InputDevice에게 현재 Key Code를 요청한다.
	int KeyCode = GEngine->GetInputDevice()->GetKeyCode();
	if (KeyCode == 'w')
	{
		Location.Y--;  //Player는 위쪽으로 한 칸 이동한다.
	}
	if (KeyCode == 's')
	{
		Location.Y++;  //Player는 아래쪽으로 한 칸 이동한다.
	}
	if (KeyCode == 'a')
	{
		Location.X--;  //Player는 왼쪽으로 한 칸 이동한다.
	}
	if (KeyCode == 'd')
	{
		Location.X++;  //Player는 오른쪽으로 한 칸 이동한다.
	}
}