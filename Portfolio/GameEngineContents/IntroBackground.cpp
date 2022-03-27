#include "IntroBackground.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngine.h>
IntroBackground::IntroBackground() 
{
}

IntroBackground::~IntroBackground()
{
}

void IntroBackground::Start()
{
	SetPosition({ 0,0 });
	SetScale(GameEngineWindow::GetScale());
}
void IntroBackground::Render()
{
	this->DebugRectRender();
	GameEngineImage* FindImage=GameEngineImageManager::GetInst()->Find("Idle.bmp");
	if (nullptr == FindImage)
	{
		MsgBoxAssert("Fuck!!!");
	}
	////게임 엔진이 스태틱인 이유 편이성+두개이상 생길리가 없다.
	GameEngine::BackBufferImage()->BitCopy(FindImage);
}