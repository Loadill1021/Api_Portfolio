#pragma once
#include <GameEngine/GameEngineActor.h>
// Ό³Έν :
class IntroBackground:public GameEngineActor
{
public:
	// constrcuter destructer
	IntroBackground();
	~IntroBackground();

	// delete Function
	IntroBackground(const IntroBackground& _Other) = delete;
	IntroBackground(IntroBackground&& _Other) noexcept = delete;
	IntroBackground& operator=(const IntroBackground& _Other) = delete;
	IntroBackground& operator=(IntroBackground&& _Other) noexcept = delete;

	void Start()override;
	void Update() {};
	void Render();

protected:

private:

};

