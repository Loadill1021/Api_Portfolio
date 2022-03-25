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
	//�� ���� ���� ���ҽ��� �ٸ��ٰ��ؼ� �������� ���ҽ��� �и��ؼ� �ε������ʴ´�.
	//�̹����� �׸��ٴ� ���� ���� �۾�?
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


