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
		bool Free_;//안누르고 있을때
		int Key_;//이 키가 눌렸다면
		bool KeyCheck()
		{
			return 0 != GetAsyncKeyState(Key_);
		}

	public:
		void Update();
		void Reset()
		{
			Down_ = false;
			Press_ = false;
			Up_ = false;
			Free_ = true;
		}
	};
private:
	static GameEngineInput* Inst_;
public:
	void GameEngineInputUpdate()
	{
		//GameEngineInput::GameEngineKey::Update();
	}
public:
	void Update();
	void CreateKey(const std::string& _Name, int _Key);

	bool IsKey(const std::string& _Name);
	bool IsDown(const std::string& _Name);
	bool IsUp(const std::string& _Name);
	bool IsFree(const std::string& _Name);
	bool IsPress(const std::string& _Name);

protected:

private:
	std::map<std::string, GameEngineKey>AllInputKey_;
	// constrcuter destructer
	GameEngineInput();
	~GameEngineInput();

	// delete Function
	/*GameEngineInput(const GameEngineInput& _Other) = delete;
	GameEngineInput(GameEngineInput&& _Other) noexcept = delete;
	GameEngineInput& operator=(const GameEngineInput& _Other) = delete;
	GameEngineInput& operator=(GameEngineInput&& _Other) noexcept = delete;*/
};

