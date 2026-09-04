#pragma once
#include "Actor.h"

class UWorld;

//APawn은 AActor이면서 스스로 움직일 수 있는 대상의 부모이다.
class APawn : public AActor
{
public:
	APawn();
	virtual ~APawn();

	virtual void Tick() override;  //Player는 입력에 따라 움직이도록 Actor의 Tick()을 재정의한다. // Pawn은 Actor의 갱신 동작을 자신의 방식으로 재정의한다.

	virtual void Render() override;  //Pawn은 Actor의 그리기 동작을 자신의 방식으로 재정의한다.

	//virtual UWorld* GetWorld() const override;
};