#pragma once
#include "Object.h"
#include "Vector2D.h"

//AActor는 UObject이면서 World 안에서 갱신되고 그려질 수 있는 대상이다.
class AActor : public UObject
{
public:
	AActor();
	virtual ~AActor();

	//inline FVector2D GetActorLocation() const
	//{
	//	return Location;
	//}
	//
	//inline void SetActorLocation(const FVector2D InValue)
	//{
	//	//Location.SetX(InValue.GetX());
	//	//Location.SetY(InValue.GetY());
	//
	//	Location = InValue;
	//}

	virtual void Tick();  //Actor는 매 Frame 자신의 상태를 갱신할 수 있다.
	virtual void Render();  //Actor는 매 Frame 자신의 모습을 그릴 수 있다.

	virtual UWorld* GetWorld() const override final;  //// Actor는 자신이 속한 World의 주소를 돌려준다.

//protected:
	FVector2D Location;  //Actor는 2D 좌표 위치를 가지고 있다.
	char Shape;  //Actor는 화면에 표시할 모양을 가지고 있다.
	int Layer = 0;  //Actor는 자신이 그려질 순서를 나타내는 Layer를 가지고 있다.
};