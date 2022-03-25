#include "IntroLevel.h"
#include "IntroBackground.h"
IntroLevel::IntroLevel() 
{
}

IntroLevel::~IntroLevel() 
{
}

void IntroLevel::Loading()
{
	this->CreateActor<IntroBackground>("IntroBacground",0);
}
void IntroLevel::Update()
{

}