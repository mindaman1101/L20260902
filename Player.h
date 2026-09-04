#pragma once
#include "Actor.h"

//AActor -> 모든지 그린다? X 안그려도 되는 엑터도 있음

//해결책1: AACtor만이 아니라 ARenderActor도 만들어 //무조건 정답이 아님 다양한 경우의 수 존재

//해결책2: 구성요소(Component) -> 그 기능을 구성요소가 담당하도록 한다.
//Actor 실질적으로 하는일은 자기의 의미가 있는일, Entity

//옛날 스타일 -> 상속 구현
//요즘 스타일 -> 구성요소 구현


//APlayer는 AActor이면서 사용자의 입력에 따라 움직이는 Player이다.
class APlayer : public AActor
{
public:
	APlayer();

	virtual ~APlayer();

	virtual void Tick() override;
};