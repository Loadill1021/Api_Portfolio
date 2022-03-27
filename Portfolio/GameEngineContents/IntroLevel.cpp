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
	CreateActor<IntroBackground>(0);
}
void IntroLevel::Update()
{

}