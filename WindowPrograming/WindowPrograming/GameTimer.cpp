#include "GameTimer.h"
#include <Windows.h>
GameTimer::GameTimer()
{
	//deltaTime = timeGetTime() * 0.001f;
	//CPU �ʴ� Ƥ���� �����´�. �ſ� ���� �����̹Ƿ� __int64 �� �����´�.
	__int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	secondPerCount = 1.0f / (float)countsPerSec;

	//���ȭ�� �����ذ�(�����̿ܿ��� �ʿ��� ��찡 ���� �� �ֱ� ������
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