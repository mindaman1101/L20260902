#pragma once
#include "Object.h"
#include <vector>

class AActor;

using namespace std;

class UWorld : public UObject
{
public:
	UWorld();

	virtual ~UWorld();

	virtual UWorld* GetWorld() const;
};