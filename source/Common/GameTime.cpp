#include "GameTime.h"
using namespace Core;

GameTime::GameTime() : mTotalGameTime(0), mElapsedGameTime(0)
{

}

double GameTime::TotalGameTime() const
{
	return mTotalGameTime;
}

void GameTime::SetTotalGameTime(double totalGameTime)
{
	mTotalGameTime = totalGameTime;
}

double GameTime::ElapsedGameTime() const
{
	return mElapsedGameTime;
}

void GameTime::SetElapsedGameTime(double elapsedGameTime)
{
	mElapsedGameTime = elapsedGameTime;
}