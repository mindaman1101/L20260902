#include "Actor.h"
#include <iostream>

using namespace std;

AActor::AActor()
{
	cout << "AActor 持失切" << endl;
}

AActor::~AActor()
{
	cout << "AActor 社瑚切" << endl;
}

void AActor::Tick()
{
}

void AActor::Render()
{
}
