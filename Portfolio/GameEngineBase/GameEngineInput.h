#pragma once
#include <Windows.h>
#include <map>
#include <string>
// ���� : ��𼭳� �����ְ� 
class GameEngineInput
{
private:
	class GameEngineKey
	{
		friend GameEngineInput;
		bool Down_;//���� Ű�� ��������
		bool Press_;//�� ���ķ� ���������� ������ ������
		bool Up_;//�����ٰ� ������
		bool Free_;//�ȴ����� ������
		int Key_;//�� Ű�� ���ȴٸ�
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

