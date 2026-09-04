#pragma once
#include "Actor.h"

//AFloor는 AActor이면서 모든 Map 칸의 바닥을 표현한다.
class AFloor : public AActor
{
public:
	AFloor();

	virtual ~AFloor();
};

