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
//
//자료구조 - 프로그램 만들때 자주? 어쩌다 쓸까?
//진영이한테 만들라고 시킬까? 매번? 저놈을 어떻게 믿고?
//Library -> 도서관, 프로그램 도서관
//Standard Template Library -> STL
//[][][][][][][][] -> 상수시간에 접근(랜덤억세스)
//크기 변경 -> 자주 하지 않음.
//vector
//Container, vector, list, queue, stack, tree, deqeue, map, set ...

int main()
{
	////FVector2D T;
	////FVector2D T(1);
	//FVector2D T(1, 1);
	////T.SetVector2D(1, 2);
	//FVector2D T2 = T;  //복사 생성자, 깊은 복사, 얕은 복사
	//
	////FVector2D T3 = T2.operator+(T);
	//FVector2D T3 = T2 + T;
	//
	//T.X;
	////T.SetX(1);
	//T.X = 1;
	//
	////cout << T3;
	//
	////A a;
	////int D = a.GetD();
	//
	////D++;
	//
	////UTexture T("1.png");
	////UTexture T1("2.png");
	////UTexture T2 = T;
	//
	//std::vector<int> Data;
	//
	//Data.push_back(3);
	//Data.push_back(7);
	//Data.push_back(4);
	//Data.push_back(1);
	//Data.push_back(3);
	//Data.push_back(2);
	//Data.push_back(5);
	//Data.push_back(6);
	//
	//std::cout << Data.size() << std::endl;
	//
	//Data.erase(std::find(Data.begin(), Data.end(), 3));
	//Data.insert(std::find(Data.begin(), Data.end(), 4), 20);
	//std::sort(Data.begin(), Data.end());
	//
	////for (auto Iter = Data.rbegin(); Iter != Data.rend(); ++Iter)
	////{
	////	std::cout << *Iter << std::endl;
	////}
	//
	//
	//for (auto Value : Data)
	//{
	//	std::cout << Value << std::endl;
	//}
	//std::cout << Data.size() << std::endl;
	//
	//std::list<int> List;
	//
	//List.push_back(7);
	//List.push_back(4);
	//List.push_back(1);
	//List.push_back(3);
	//List.push_back(2);
	//List.push_back(5);
	//List.push_back(6);
	//
	//List.erase(std::find(List.begin(), List.end(), 3));
	//List.insert(std::find(List.begin(), List.end(), 4), 20);
	////for (auto Iter = List.rbegin(); Iter != List.rend(); ++Iter)
	////{
	////	std::cout << *Iter << std::endl;
	////}
	//
	//for (auto Value : List)
	//{
	//	std::cout << Value << std::endl;
	//}
	//

	UEngine* MyEngine = new UEngine();
	
	MyEngine->Init();
	

	return 0;
}