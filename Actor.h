#pragma once
#include "Object.h"
#include "Vector2D.h"

class AActor : public UObject
{
public:
	AActor();

	virtual ~AActor();

	inline FVector2D GetActorLocation() const
	{
		return Location;  //this-> »ý·«
	}

	inline void SetActorLocation(const FVector2D InValue)
	{
		//Location.SetX(InValue.GetX());
		//Location.SetY(InValue.GetY());

		Location = InValue;
	}

	virtual void Tick();
	virtual void Render();

protected:
	FVector2D Location;
};