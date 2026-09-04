#include "Engine.h"
#include "SDL.h"
#include <vector>

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

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

//class Singleton
//{
//protected:
//	Singleton()
//	{
//	}
//
//public:
//	static Singleton* GetInstance()
//	{
//		if (!Singleton::Instance)
//		{
//			Singleton::Instance = new Singleton();
//		}
//
//		return Singleton::Instance;
//	}
//
//protected:
//	static Singleton* Instance;
//};
//
//Singleton* Singleton::Instance = nullptr;

//프로그램은 하나뿐인 Engine을 준비하고 실행한 뒤 종료한다.
//int main()
//{
//	//StaticClass Data = 10;  //안됨
//	//
//	//StaticClass S;
//	//S.Data = 10;
//	//
//	//StaticClass::Data = 20;  //선언 안해도 바로 사용 가능
//	//
//	//StaticClass A;
//	//StaticClass B;
//	//StaticClass* A = new StaticClass();
//	//delete A;
//	//StaticClass* B = A;
//	//cout << StaticClass::Count << endl;  //몇이 나올까?
//	//
//	//Singleton A;
//	//Singleton B;
//	//Singleton C;
//	//
//	//cout << Singleton::GetInstance() << endl;
//	//cout << Singleton::GetInstance() << endl;
//	//cout << Singleton::GetInstance() << endl;	
//	//cout << Singleton::GetInstance() << endl;
//
//	//UEngine* MyEngine = UEngine::GetInstance();
//	
//	GEngine->Init();  //프로그램은 Engine에게 실행 준비를 요청한다.
//	
//	GEngine->Run();  //프로그램은 Engine에게 Game Loop 실행을 요청한다.
//
//	GEngine->Exit();  //프로그램은 Engine에게 실행 종료와 정리를 요청한다.
//
//	return 0;
//}

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);  //GPU, Soundcard, 입력장치 내가 다 땡겨서 쓸게
	
	SDL_Window* MyWindow = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event MyEvent;

	while (true)
	{
		SDL_PollEvent(&MyEvent);

		if (MyEvent.type == SDL_QUIT)
		{
			break;
		}
		else if (MyEvent.type == SDL_KEYDOWN)
		{
			if (MyEvent.key.keysym.sym == SDLK_ESCAPE)  //Esc 누르면 끝남
			{
				break;
			}			
		}

		SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
		SDL_RenderClear(MyRenderer);

		for (int i = 0; i < 20000; ++i)
		{
			SDL_Rect MyRect{ rand() % 800, rand() % 600, rand() % 400, rand() % 400 };

			SDL_SetRenderDrawColor(MyRenderer, rand() % 256, rand() % 256, rand() % 256, 0);

			if (rand() % 2 == 0)
			{
				SDL_RenderDrawRect(MyRenderer, &MyRect);
			}
			else
			{
				SDL_RenderFillRect(MyRenderer, &MyRect);
			}
		}
		
		SDL_RenderPresent(MyRenderer);
	}

	SDL_Quit();

	return 0;
}