#include "Engine.h"
#include <iostream>

using namespace std;

//int Data = 20;  //oop에서는 이렇게 하질라고함
//
//class StaticClass
//{
//public:
//	static int Data;  //선언  //Data 영역에 시작하자마자 만들어짐 (내가 생성하든 말든 실행하자 마자 메모리에 생김)
//	//static int Data2;
//	//static int Data3;
//	//static int Data4;
//	//static int Data5;  //다 따로 생김
//
//	static void Do()
//	{
//
//	}
//};
//
//int StaticClass::Data = 10;
////int StaticClass::Data2 = 10;
////int StaticClass::Data3 = 10;
////int StaticClass::Data4 = 10;
////int StaticClass::Data5 = 10;

//class StaticClass
//{
//public:
//	StaticClass()
//	{
//		StaticClass::Count++;
//	}
//
//	virtual ~StaticClass()
//	{
//		StaticClass::Count--;
//	}
//
////protected:랑 가장 관련있음
//	static int Count;
//};
//
//int StaticClass::Count = 0;

class Singleton
{
protected:
	Singleton()
	{
	}

public:
	static Singleton* GetInstance()
	{
		if (!Singleton::Instance)
		{
			Singleton::Instance = new Singleton();
		}

		return Singleton::Instance;
	}

protected:
	static Singleton* Instance;
};

Singleton* Singleton::Instance = nullptr;

int main()
{
	//StaticClass Data = 10;  //안됨

	//StaticClass S;
	//S.Data = 10;

	//StaticClass::Data = 20;  //선언 안해도 바로 사용 가능

	//StaticClass A;
	//StaticClass B;
	//StaticClass* A = new StaticClass();
	//delete A;
	//StaticClass* B = A;
	//cout << StaticClass::Count << endl;  //몇이 나올까?

	//Singleton A;
	//Singleton B;
	//Singleton C;

	//cout << Singleton::GetInstance() << endl;
	//cout << Singleton::GetInstance() << endl;
	//cout << Singleton::GetInstance() << endl;	
	//cout << Singleton::GetInstance() << endl;



	//UEngine* MyEngine = UEngine::GetInstance();
	
	GEngine->Init();
	
	GEngine->Run();

	GEngine->Exit();

	return 0;
}