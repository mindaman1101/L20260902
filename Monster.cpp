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

void AMonster::Tick()
{
	std::vector<AActor*> CollideActors;

	int MoveDirection = rand() % 4;

	if (MoveDirection == 0)
	{
		Location.X++;

		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.X--;
		}
	}
	else if (MoveDirection == 1)
	{
		Location.X--;

		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.X++;
		}
	}
	else if (MoveDirection == 2)
	{
		Location.Y++;

		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.Y--;
		}
	}
	else if (MoveDirection == 3)
	{
		Location.Y--;

		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.Y++;
		}
	}
}