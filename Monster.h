#pragma once
#include "Actor.h"

//AMonster는 AActor이면서 Player와 구분되는 적이다.
class AMonster : public AActor
{
public:
	AMonster();

	virtual ~AMonster();

	virtual void Tick() override;
};