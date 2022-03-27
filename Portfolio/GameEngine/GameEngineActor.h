#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineNameObject.h>
#include "GameEngineEnum.h"
#include <list>
// ���� :
class GameEngineRenderer;
class GameEngineLevel;
class GameEngineActor:public GameEngineNameObject
{
/////ActorBase
public:
	friend GameEngineLevel;
	// constrcuter destructer
	GameEngineActor();
	virtual ~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	inline GameEngineLevel* GetLevel()
	{
		return Level_;
	}

	inline float4 GetPosition()
	{
		return Position_;
	}
	inline float4 GetScale()
	{
		return Scale_;
	}
	inline void SetPosition(const float4 _Value)
	{
		Position_ = _Value;
	}
	inline void SetScale(const float4 _Value)
	{
		Scale_ = _Value;
	}
	inline void SetMove(float4 _Value)
	{
		Position_ += _Value;
	}

protected:
	// �����Ҷ� ������ �ϰ� ������ �����ڿ����� ����� ���� �κе��� ó���Ѵ�.
	virtual void Start() = 0;
	// ���������� ������ ����ɶ� ȣ��ȴ�.
	virtual void Update() {};
	// ���������� ������ ����ɶ� ȣ��ȴ�.
	virtual void Render() {};
	// �׽�Ʈ�� �׸�׸���
	void DebugRectRender();
private:
	// ���� ������� ������ �˾ƾ��Ѵ�. Actor�� ������ ����
	GameEngineLevel* Level_;
	// ��ġ
	float4 Position_;
	// ũ��
	float4 Scale_;

	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}
	///////////////////////////////////////Render
	//GameEngineRenderer vs GameEngineRenderer*
	//���� �̵��� ���°� ������ ��
	//���� ������.
public:

	GameEngineRenderer* CreateRendererToScale(
		const std::string& _Image, 
		const float4& _Scale, 
		RenderPivot _PivotType = RenderPivot::CENTER, 
		const float4& _PivotPos = { 0,0 });
public:

	GameEngineRenderer* CreateRenderer(const std::string& _Image,
		RenderPivot _PivotType,/*=RenderPivot::CENTER �׸�ĭ ���� ���� ��*/
		const float4& _PivotPos/*={0,0}*/
	);
private:
	//���ͷ�����
	std::list<GameEngineRenderer*>::iterator StartRenderIter;
	std::list<GameEngineRenderer*>::iterator EndRenderIter;

	//�׸��ٴ� ����� Ŭ������ 
	std::list<GameEngineRenderer*>RenderList_;
};

