#pragma once
#include <Windows.h>
#include <map>
#include <string>
// 설명 : 어디서나 쓸수있게 
class GameEngineInput
{
private:
	class GameEngineKey
	{
		friend GameEngineInput;
		bool Down_;//최초 키를 눌렀을때
		bool Press_;//그 이후로 지속적으로 누르고 있을때
		bool Up_;//누르다가 땠을때
		int Key_;//이 키가 눌렸다면
	public:
		void Update()
		{
			
		}
	};
private:
	static GameEngineInput* Inst_;
public:
	void GameEngineInputUpdate()
	{
		//GameEngineInput::GameEngineKey::Update();
	}
protected:

private:
	// constrcuter destructer
	GameEngineInput();
	~GameEngineInput();

	// delete Function
	GameEngineInput(const GameEngineInput& _Other) = delete;
	GameEngineInput(GameEngineInput&& _Other) noexcept = delete;
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput&& _Other) noexcept = delete;
};

