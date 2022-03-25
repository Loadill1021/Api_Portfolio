#include "GameEngineActor.h"
#include "GameEngine/GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
//#include "GameEngineLevel.h"
GameEngineActor::GameEngineActor() 
	:Level_(nullptr)
{
}

GameEngineActor::~GameEngineActor() 
{
}
void GameEngineActor::DebugRectRender()
{
	GameEngineRect DebugRect(Position_, Scale_);
	Rectangle(
		GameEngine::BackBufferDC(),
		DebugRect.CenterLeft(),
		DebugRect.CenterTop(),
		DebugRect.CenterRight(),
		DebugRect.CenterBot()
	);
}
GameEngineRenderer* CreateRenderer(const std::string& _Image,
	RenderPivot _PivotType,/*=RenderPivot::CENTER �׸�ĭ ���� ���� ��*/
	const float4& _PivotPos/*={0,0}*/
)
{
	
	return;
}