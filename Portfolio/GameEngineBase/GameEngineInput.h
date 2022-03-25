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
		int Key_;//�� Ű�� ���ȴٸ�
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

