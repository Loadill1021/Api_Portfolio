#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineNameObject.h>
#include "GameEngineEnum.h"
#include <list>
// 설명 :
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
	// 시작할때 뭔가를 하고 싶은데 생성자에서는 절대로 못할 부분들을 처리한다.
	virtual void Start() = 0;
	// 지속적으로 게임이 실행될때 호출된다.
	virtual void Update() {};
	// 지속적으로 게임이 실행될때 호출된다.
	virtual void Render() {};
	// 테스트용 네모그리기
	void DebugRectRender();
private:
	// 나를 만들어준 레벨을 알아야한다. Actor는 레벨이 관리
	GameEngineLevel* Level_;
	// 위치
	float4 Position_;
	// 크기
	float4 Scale_;

	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}
	///////////////////////////////////////Render
	//GameEngineRenderer vs GameEngineRenderer*
	//가장 이득을 보는건 벡터의 값
	//가장 빠르다.
public:

	GameEngineRenderer* CreateRendererToScale(
		const std::string& _Image, 
		const float4& _Scale, 
		RenderPivot _PivotType = RenderPivot::CENTER, 
		const float4& _PivotPos = { 0,0 });
public:

	GameEngineRenderer* CreateRenderer(const std::string& _Image,
		RenderPivot _PivotType,/*=RenderPivot::CENTER 네모칸 기준 센터 위*/
		const float4& _PivotPos/*={0,0}*/
	);
private:
	//이터레이터
	std::list<GameEngineRenderer*>::iterator StartRenderIter;
	std::list<GameEngineRenderer*>::iterator EndRenderIter;

	//그린다는 기능을 클래스로 
	std::list<GameEngineRenderer*>RenderList_;
};

