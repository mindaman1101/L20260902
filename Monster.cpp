#include "Monster.h"
#include <stdlib.h>
#include <vector>
#include "SystemLibrary.h"

AMonster::AMonster()
{
	Shape = 'M';  //Monster는 화면에서 M으로 보인다.
	Layer = 120;  //Monster는 Player보다 나중에 그려져 Player 위에 보인다.
	bIsCollisionEnable = false;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()  // 1초에 60번 이동하게 되므로 시간으로 이용 -> SDL 사용
{
	char VirtualKeyCode[4] = { 'w', 'a', 's', 'd' };
	std::vector<AActor*> CollideActors;
	int KeyCode = VirtualKeyCode[rand() % 4];
	if (KeyCode == 'w')
	{
		Location.Y--;

		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.Y++;
		}
	}
	if (KeyCode == 's')
	{
		Location.Y++;

		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.Y--;
		}
	}
	if (KeyCode == 'a')
	{
		Location.X--;

		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.X++;
		}
	}
	if (KeyCode == 'd')
	{
		Location.X++;

		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.X--;
		}
	}
}