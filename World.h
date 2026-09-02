#pragma once
#include <vector>
#include "Actor.h"

using namespace std;

class UWorld
{
public:
	UWorld();

	virtual ~UWorld();

private:
	vector<AActor*> Actors;
};