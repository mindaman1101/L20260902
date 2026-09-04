#include "Goal.h"

AGoal::AGoal()
{
	Shape = 'G';  //Goal은 화면에서 G로 보인다.
	Layer = 20;  //Goal은 Floor와 Wall 위, Player 아래에 그려진다.
}

AGoal::~AGoal()
{
}