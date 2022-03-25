#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineNameObject.h>
// ���� :
class GameEngineLevel;
class GameEngineActor:public GameEngineNameObject
{
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

	inline float4 GetPosition()
	{
		return Position_;
	}
	inline void SetPosition(const float4 _Value)
	{
		Position_ = _Value;
	}
	inline void SetScale(const float4 _Value)
	{
		Scale_ = _Value;
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
};

