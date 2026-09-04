#pragma once

class UWorld;

//UObject는 World에 속할 수 있는 모든 Object의 공통 부모이다.
class UObject //메모리 관리, 언리얼 엔진은 모든 UObject 상속됨
{
public:
	UObject();

	virtual ~UObject();

	virtual UWorld* GetWorld() const;  //Object는 자신이 속한 World의 주소를 알려줄 수 있다.
	virtual void SetWorld(UWorld* NewWorld);

protected:
	UWorld* World;  //UObject는 자신이 속한 World의 주소를 가지고 있다.
};