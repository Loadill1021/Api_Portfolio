#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <list>
#include <map>
// ���� : ;
class GameEngine;
class GameEngineActor;
class GameEngineLevel :public GameEngineNameObject
{
	friend GameEngine;
public:
	// constrcuter destructer
	GameEngineLevel();
	virtual ~GameEngineLevel();

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

	
protected:
	//��������鼭 ���ҽ��� ���͸� ���鶧
	virtual void Loading() = 0;
	//�� ������ ���� �����϶� �ؾ������� �����Ѵ�.
	virtual void Update() = 0;

	//������ �ٲ�� �Լ�
	virtual void LevelChangeStart(){}
	virtual void LevelChangeEnd(){}

	template<typename ActorType>
	ActorType* CreateActor(int _Order=0,const std::string& _Name="")
	{
		ActorType* NewActor = new ActorType();
		GameEngineActor* StartActor = NewActor;
		NewActor->SetName(_Name);
		NewActor->SetLevel(this);
		StartActor->Start();
		std::list<GameEngineActor*>& Group = AllActor_[_Order];
		Group.push_back(NewActor);
		return nullptr;
	}
private:
	std::map<int, std::list<GameEngineActor*>>AllActor_;
	void ActorUpdate();
	void ActorRender();
};

