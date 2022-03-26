#include "GameEngineRenderer.h"
#include "GameEngineImageManager.h"
#include "GameEngineBase/GameEngineDebug.h"
#include "GameEngine.h"

#pragma comment(lib,"msimg32.lib")
GameEngineRenderer::GameEngineRenderer()
	:Image_(nullptr)
	,PivotType_(RenderPivot::CENTER)
	,ScaleMode_(RenderScaleMode::Image)
	,TransColor_(RGB(255,0,255))//마젠타
	,RenderImagePivot_({0,0})
{
	
}

GameEngineRenderer::~GameEngineRenderer() 
{
}
void SetImageScale(const std::string& _Name)
{

}
void GameEngineRenderer::SetImageScale()
{

}
void GameEngineRenderer::SetImage(const std::string& _Name)
{
	GameEngineImage* FindImage=GameEngineImageManager::GetInst()->Find("Idle.bmp");
	if (nullptr == FindImage)
	{
		MsgBoxAssertString(_Name + "존재하지 않는 이미지를 랜더러에 세팅하려고 했습니다.");
		return;
	}
	Image_ = FindImage;

}

void GameEngineRenderer::Render()
{
	if (nullptr == Image_)
	{
		MsgBoxAssert("랜더러에 이미지가 세팅되어 있지 않으면 랜더링이 안됩니다.");
		return;
	}
	//액터의 위치+그리는 방식
	float4 RenderPos = GetActor()->GetPosition() + RenderPivot_;
	//랜더러를 가지고 있는 엑터의 위치
	switch (PivotType_)
	{
	case RenderPivot::CENTER:
		GameEngine::BackBufferImage()->TransCopy(Image_, RenderPos - RenderScale_.Half(), RenderScale_, RenderImagePivot_, RenderImageScale_, TransColor_);
	case RenderPivot::BOT:
		//GameEngine::BackBufferImage()->TransCopy(Image_, RenderPos, RenderScale, TransColor_);
		break;
	default:
		break;
	}
}
void GameEngineRenderer::SetIndex(size_t _Index)
{
	if (false == Image_->IsCut())
	{
		MsgBoxAssert("이미지를 부분적으로 사용할수 있게 잘려져있지 않은 이미지 입니다.");
	}
	RenderImagePivot_ = Image_->GetCutPivot(_Index);
	RenderScale_ = Image_->GetCutScale(_Index);
	RenderImageScale_ = Image_->GetCutScale(_Index);
}