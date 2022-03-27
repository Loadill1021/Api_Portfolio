#include "GameEngineInput.h"
#include "GameEngineString.h"
GameEngineInput* GameEngineInput::Inst_ = new GameEngineInput();
void GameEngineInput::GameEngineKey::Update()
{
	//키가 눌렸다면
	if (true == KeyCheck())
	{
		//누르다가 땠을때
		if (true == Free_)
		{
			Down_ = true;
			Press_ = true;
			Up_ = false;
			Free_ = false;
		}
		//
		else if (true == Press_)
		{
			Down_ = false;
			Press_ = true;
			Up_ = false;
			Free_ = false;
		}
	}
	//키가 눌리지 않았다면
	else
	{
		if (true == Press_)
		{
			Down_ = false;
			Press_ = false;
			Up_ = false;
			Free_ = true;
		}
	}
}
GameEngineInput::GameEngineInput() 
{
}

GameEngineInput::~GameEngineInput() 
{
}
bool GameEngineInput::IsKey(const std::string& _Name)
{
	std::string UpperKey = GameEngineString::ToUpperReturn(_Name);
}
