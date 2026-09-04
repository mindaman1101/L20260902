#pragma once
#include "Actor.h"

//AWall은 AActor이면서 Map의 벽을 표현한다.
class AWall : public AActor
{
public:
	AWall();

	virtual ~AWall();
};

