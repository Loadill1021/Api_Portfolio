#pragma once
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <map>
#include <string>
// ���� :
class GameEngineImage;
class GameEngineLevel;
class GameEngine
{
public:
	// constrcuter destructer
	GameEngine();
	~GameEngine();

	// delete Function
	GameEngine(const GameEngine& _Other) = delete;
	GameEngine(GameEngine&& _Other) noexcept = delete;
	GameEngine& operator=(const GameEngine& _Other) = delete;
	GameEngine& operator=(GameEngine&& _Other) noexcept = delete;

	virtual void GameInit() = 0;
	virtual void GameLoop() = 0;
	virtual void GameEnd() = 0;
	static HDC BackBufferDC();
	static inline GameEngineImage* BackBufferImage()
	{
		return BackBufferImage_;
	}

	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();
		GameType UserGame;
		UserContents_ = &UserGame;
		WindowCreate();
		EngineEnd();
	}
	void ChangeLevel(const std::string& _Name);

	static GameEngine& GlobalEngine()
	{
		if (nullptr == UserContents_)
		{
			MsgBoxAssert("GEngine ERROR Engine Is Not Start");
		}
		return *UserContents_;
	}
protected:
	template<typename LevelType>
	void CreateLevel(const std::string _Name)
	{
		
		LevelType* NewLevel = new LevelType();

		NewLevel->SetName(_Name);
		GameEngineLevel* Level=NewLevel;
		Level->Loading();
		AllLevel_.insert(std::make_pair(_Name,NewLevel));
	}
	
private:
	static std::map<std::string, GameEngineLevel*>AllLevel_;
	static GameEngineLevel* CurrentLevel_;
	static GameEngineLevel* NextLevel_;
	static GameEngine* UserContents_;
	static GameEngineImage* WindowMainImage_; // �׷����� ȭ�鿡 ��¥ ������ �Ǵ� �̹���
	static GameEngineImage* BackBufferImage_; // �������� �ذ��Ϸ��� ���۷� ����ϴ� �̹���
	static void WindowCreate();
	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();
};

