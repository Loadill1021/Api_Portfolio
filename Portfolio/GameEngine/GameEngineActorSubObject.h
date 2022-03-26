#pragma once
#include <GameEngine/GameEngineActor.h>
// 엑터가 먼저인가 랜더러가 먼저인가 엑터가 먼저
// 근본 엔진급 애들이 내 컨텐츠를 알아야 할 이유가없다.
// 설명 :
class GameEngineActorSubObject
{
	friend GameEngineActor;
public:
	// constrcuter destructer
	GameEngineActorSubObject();
	virtual ~GameEngineActorSubObject();

	// delete Function
	GameEngineActorSubObject(const GameEngineActorSubObject& _Other) = delete;
	GameEngineActorSubObject(GameEngineActorSubObject&& _Other) noexcept = delete;
	GameEngineActorSubObject& operator=(const GameEngineActorSubObject& _Other) = delete;
	GameEngineActorSubObject& operator=(GameEngineActorSubObject&& _Other) noexcept = delete;

	inline GameEngineActor* GetActor()
	{
		return Actor_;
	}

protected:
	// 부모님이 바뀌는건 말이 안된다.
	// 만들어준애가 셋팅이 되어야 하고 엔진에서 관리가 되어야 하므로 protected
	inline void SetActor(GameEngineActor* _Actor)
	{
		Actor_ = _Actor;
	}

private:
	GameEngineActor* Actor_;
};

