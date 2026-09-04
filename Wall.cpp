#include "Wall.h"

AWall::AWall()
{
	Shape = '*';  //Wall은 화면에서 *로 보인다.
	Layer = 1;  //Wall은 Floor 다음에 그려진다.
	bIsCollisionEnable = true;
}

AWall::~AWall()
{
}
