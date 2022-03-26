#pragma once
#include "GameEngineActorSubObject.h"
//#include "GameEngineImage.h" Ȯ���� ���ϰ��谡 �ƴϸ� �׳� �����.
//���ʹ� ������ �� ��Ȳ�� ���ϴ°Ű�
//�������� �׸��ٶ�� ����
//���ʹ� �Ӹ�
//�ȴٸ��� GameEngineRenderer
//�迭�� �ٸ����ϸ� ����ʿ� �ִ°��� �����ϴ�.
#include "GameEngineEnum.h"
// ���� :
class GameEngineImage;
class GameEngineRenderer:public GameEngineActorSubObject
{
public:
	// constrcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	inline void SetTransColor(unsigned int _Color)
	{
		TransColor_ = _Color;
	}

	inline void SetType(const RenderPivot& _Type)
	{
		PivotType_ = _Type;
	}
	inline void SetPivot(const float4& _Pos)
	{
		RenderPivot_ = _Pos;
	}
	inline void SetType(const RenderPivot& _Type)
	{
		PivotType_ = _Type;
	}
	void SetImageScale(const std::string& _Name);
	
	inline void SetScale(const float4& _Scale)
	{
		ScaleMode_ = RenderScaleMode::User;
		RenderScale_ = _Scale;
	}
	void SetImage(const std::string& _Name);
	void SetIndex(size_t _Index);

protected:
	void Render();
private:
	GameEngineImage* Image_;//�̹���
	RenderPivot PivotType_;//���� ��
	RenderScaleMode ScaleMode_;

	float4 RenderPivot_; 

	float4 RenderScale_;
	float4 RenderImageScale_;
	float4 RenderImagePivot_;

	unsigned int TransColor_;

};
