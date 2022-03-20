#include "PoketMonster.h"
#include "IntroLevel.h"

PoketMonster::PoketMonster() 
{
}

PoketMonster::~PoketMonster()
{
}
void PoketMonster::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100,100 }, { 1280,720 });
	//CreateLevel<IntroLevel>("Intro");
}
void PoketMonster::GameLoop()
{

}
void PoketMonster::GameEnd()
{

}


