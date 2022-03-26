#pragma once
#include "GameEngineActorSubObject.h"
//#include "GameEngineImage.h" 확실한 상하관계가 아니면 그냥 지운다.
//엑터는 나오는 그 상황을 말하는거고
//랜더러는 그린다라는 개념
//엑터는 머리
//팔다리는 GameEngineRenderer
//계열이 다르다하면 헤더쪽에 넣는것은 위험하다.
#include "GameEngineEnum.h"
// 설명 :
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
	GameEngineImage* Image_;//이미지
	RenderPivot PivotType_;//센터 봇
	RenderScaleMode ScaleMode_;

	float4 RenderPivot_; 

	float4 RenderScale_;
	float4 RenderImageScale_;
	float4 RenderImagePivot_;

	unsigned int TransColor_;

};

