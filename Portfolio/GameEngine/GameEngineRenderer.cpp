#include "GameEngineRenderer.h"
#include "GameEngineImageManager.h"
#include "GameEngineBase/GameEngineDebug.h"
#include "GameEngine.h"

#pragma comment(lib,"msimg32.lib")
GameEngineRenderer::GameEngineRenderer()
	:Image_(nullptr)
	,PivotType_(RenderPivot::CENTER)
	,ScaleMode_(RenderScaleMode::Image)
	,TransColor_(RGB(255,0,255))//����Ÿ
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
		MsgBoxAssertString(_Name + "�������� �ʴ� �̹����� �������� �����Ϸ��� �߽��ϴ�.");
		return;
	}
	Image_ = FindImage;

}

void GameEngineRenderer::Render()
{
	if (nullptr == Image_)
	{
		MsgBoxAssert("�������� �̹����� ���õǾ� ���� ������ �������� �ȵ˴ϴ�.");
		return;
	}
	//������ ��ġ+�׸��� ���
	float4 RenderPos = GetActor()->GetPosition() + RenderPivot_;
	//�������� ������ �ִ� ������ ��ġ
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
		MsgBoxAssert("�̹����� �κ������� ����Ҽ� �ְ� �߷������� ���� �̹��� �Դϴ�.");
	}
	RenderImagePivot_ = Image_->GetCutPivot(_Index);
	RenderScale_ = Image_->GetCutScale(_Index);
	RenderImageScale_ = Image_->GetCutScale(_Index);
}