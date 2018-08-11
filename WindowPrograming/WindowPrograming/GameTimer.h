#pragma once

class GameTimer
{
private:
	float deltaTime;
	float prevTime;
	float secondPerCount;

public:
	GameTimer();
	~GameTimer();
	void Update();
	void Init();
	float getDeltaTime();
};

