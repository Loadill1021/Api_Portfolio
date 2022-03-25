#include "PoketMonster.h"
#include "IntroLevel.h"
#include <GameEngine/GameEngineImageManager.h>
PoketMonster::PoketMonster() 
{
}

PoketMonster::~PoketMonster()
{
}
void PoketMonster::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100,100 }, { 1280,720 });
	//각 레벨 마다 리소스가 다르다고해서 레벨마다 리소스를 분리해서 로드하지않는다.
	//이미지를 그린다는 것은 무슨 작업?
	//C:\Api_Portfolio\Portfolio\Resources
	GameEngineImageManager::GetInst()->Load("C:\\Api_Portfolio\\Portfolio\\Resources\\Idle.bmp", "Idle.bmp");
	CreateLevel<IntroLevel>("Intro");
	ChangeLevel("Intro");
}
void PoketMonster::GameLoop()
{

}
void PoketMonster::GameEnd()
{

}


