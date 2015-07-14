#include "GameClock.h"
#include "ZAssert.h"
using namespace Core;

GameClock::GameClock() : mStartTime(), mCurrentTime(), mLastTime(), mFrequency()
{
	mFrequency = GetFrequency();
	Reset();
}

#if defined WINDOWS
const LARGE_INTEGER& GameClock::StartTime() const
{
	return mStartTime;
}

const LARGE_INTEGER& GameClock::CurrentTime() const
{
	return mCurrentTime;
}

const LARGE_INTEGER& GameClock::LastTime() const
{
	return mLastTime;
}

double GameClock::GetFrequency() const
{
	LARGE_INTEGER frequency;
	ZEPHYR_ASSERT(QueryPerformanceFrequency(&frequency), "The high perfromance frequency counter failed to get the frequency.");
	return (double)frequency.QuadPart;
}

void GameClock::GetTime(LARGE_INTEGER& time) const
{
	QueryPerformanceCounter(&time);
}

void GameClock::UpdateGameTime(GameTime& gameTime)
{
	GetTime(mCurrentTime);
	gameTime.SetTotalGameTime((mCurrentTime.QuadPart - mStartTime.QuadPart) / mFrequency);
	gameTime.SetElapsedGameTime((mCurrentTime.QuadPart - mLastTime.QuadPart) / mFrequency);
	mLastTime = mCurrentTime;
}
#endif

void GameClock::Reset()
{
	GetTime(mStartTime);
	mCurrentTime = mStartTime;
	mLastTime = mCurrentTime;
}