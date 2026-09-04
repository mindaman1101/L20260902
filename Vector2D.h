#pragma once

//FVector2D는 2D 공간의 X, Y 좌표를 하나의 값으로 표현한다.
struct FVector2D
{
//public:
	//FVector2D();
	// 
	//생성자 오버로딩
	FVector2D(int InX = 0, int InY = 0);  //아무것도 안쓰면 0, 0 채워줌
	FVector2D(const FVector2D& RHS);

	//A(Left Hand Side) = B(Right Hand Side)

	virtual ~FVector2D();

	////encapsulation
	//inline void SetX(int NewValue)
	//{
	//	X = NewValue;
	//}
	//inline int GetX() const
	//{
	//	return X;
	//}	
	//
	//inline void SetY(int NewValue)
	//{
	//	Y = NewValue;
	//}
	//inline int GetY() const
	//{
	//	return Y;
	//}
	//
	////__forceinline / FORCEINLINE
	//inline void SetVector2D(int NewValueX, int NewValueY)
	//{
	//	X = NewValueX;
	//	Y = NewValueY;
	//}
	//inline FVector2D GetVector2D() const
	//{
	//	//FVector2D Value;
	//	//Value.SetVector2D(this->X, this->Y);
	//
	//	return *this;
	//}

	//연산자 오버로딩	
	FVector2D operator+(const FVector2D& RHS) const;  //2D 좌표는 다른 2D 좌표와 더해질 수 있다.
	bool operator==(const FVector2D& RHS) const;

//protected:
	int X;  //2D 좌표는 가로 위치를 가지고 있다.
	int Y;  //2D 좌표는 세로 위치를 가지고 있다.
};