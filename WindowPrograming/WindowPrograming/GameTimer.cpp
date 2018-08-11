#include "GameTimer.h"
#include <Windows.h>
GameTimer::GameTimer()
{
	//deltaTime = timeGetTime() * 0.001f;
	//CPU 초당 튄값을 가져온다. 매우 낮은 단위이므로 __int64 를 가져온다.
	__int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	secondPerCount = 1.0f / (float)countsPerSec;

	//모듈화를 시켜준것(생성이외에도 필요한 경우가 생길 수 있기 때문에
	Init();
}

GameTimer::~GameTimer()
{
}

void GameTimer::Init()
{
	__int64 currentTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	deltaTime = 0.0f;
	prevTime = currentTime;
}

void GameTimer::Update()
{
	//deltaTime = timeGetTime() * 0.001f - deltaTime;
	__int64 currentTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

	deltaTime = (currentTime - prevTime) * secondPerCount;
	prevTime = currentTime;
}

float GameTimer::getDeltaTime()
{
	return deltaTime;
}