#include "GameEngineActor.h"
#include "GameEngine/GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngineRenderer.h"
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
GameEngineRenderer* GameEngineActor::CreateRenderer(const std::string& _Image,
	RenderPivot _PivotType,/*=RenderPivot::CENTER 네모칸 기준 센터 위*/
	const float4& _PivotPos/*={0,0}*/
)
{
	GameEngineRenderer* NewRenderer= new GameEngineRenderer();
	RenderList_.push_back(NewRenderer);
	return NewRenderer;
}
GameEngineRenderer* CreateRendererToScale(const std::string& _Image, const float4& _Scale, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 })
{
	GameEngineRenderer* NewRenderer = new GameEngineRenderer();
	NewRenderer->SetActor(this);
	NewRenderer->SetImage(_Image);
	NewRenderer->SetScale(_Scale);
	NewRenderer->SetPivot(_PivotPos);
	NewRenderer->SetType(_PivotType);
}