#pragma once
#include "Actor.h"

//AGoal은 AActor이면서 Player가 도착해야 할 목적지를 표현한다.
class AGoal : public AActor
{
public:
	AGoal();

	virtual ~AGoal();
};