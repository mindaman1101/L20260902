#pragma once
#include "Object.h"
#include <vector>
#include "Actor.h"

using namespace std;

class UWorld : public UObject
{
public:
	UWorld();

	virtual ~UWorld();

	virtual UWorld* GetWorld() const;

private:
	vector<AActor*> Actors;
};