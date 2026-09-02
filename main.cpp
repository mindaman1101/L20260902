#include <iostream>
#include "Vector2D.h"
#include "Engine.h"

using namespace std;

//class A
//{
//public:
//	const int& GetD(const int& A) const
//	{
//		//K++;
//		//A++;
//		return D;
//	}
//
//	int& GetD()
//	{
//		return D;
//	}
//
//private:
//	int D;
//	int K;
//};
//
//class UTexture
//{
//public:
//	//기본 생성자 있어?
//	//복사 생성자 있어?
//	//없으면 자동 기본 복사 생성자(내가 아는 형태만 한다)
//
//	UTexture(string Texturename)
//	{
//		Data = new char[1024];
//		//텍스처를 로딩
//	}
//
//	//deep copy
//	UTexture(const UTexture& RHS)
//	{
//		Data = new char[1024];
//		memcpy(Data, RHS.Data, 1024);  //memcpy는 자세히 설명 안함 나중에 한대
//	}
//
//	~UTexture()
//	{
//		delete Data;
//	}
//
//	char* Data;
//};

int main()
{
	////FVector2D T;
	////FVector2D T(1);
	//FVector2D T(1, 1);
	////T.SetVector2D(1, 2);
	//FVector2D T2 = T;  //복사 생성자, 깊은 복사, 얕은 복사

	////FVector2D T3 = T2.operator+(T);
	//FVector2D T3 = T2 + T;

	//T.X;
	////T.SetX(1);
	//T.X = 1;

	////cout << T3;

	////A a;
	////int D = a.GetD();

	////D++;

	////UTexture T("1.png");
	////UTexture T1("2.png");
	////UTexture T2 = T;

	UEngine* MyEngine = new UEngine();

	MyEngine->Init();

	MyEngine->Run();

	MyEngine->Exit();

	delete MyEngine;

	return 0;
}