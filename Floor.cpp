#include "Floor.h"

AFloor::AFloor()
{
	Shape = ' ';  //Floor는 빈 문자로 보인다.
	Layer = 0;  //Floor는 가장 먼저 그려지는 바탕이다.
}

AFloor::~AFloor()
{
}
