#include "Monster.h"

AMonster::AMonster()
{
	Shape = 'M';  //Monster는 화면에서 M으로 보인다.
	Layer = 120;  //Monster는 Player보다 나중에 그려져 Player 위에 보인다.
	bIsCollisionEnable = false;
}

AMonster::~AMonster()
{
}