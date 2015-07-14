#ifndef GAMECLOCK_H
#define GAMECLOCK_H

#include "EngineState.h"
#include "GameTime.h"

#if defined WINDOWS
#include <windows.h>
#endif

namespace Core
{
	class GameClock
	{
	public:
		GameClock();

#if defined WINDOWS
		const LARGE_INTEGER& StartTime() const;
		const LARGE_INTEGER& CurrentTime() const;
		const LARGE_INTEGER& LastTime() const;

		void GetTime(LARGE_INTEGER& time) const;
#endif

		void Reset();
		double GetFrequency() const;
		void UpdateGameTime(GameTime& gameTime);

	private:
		GameClock(const GameClock& rhs);
		GameClock& operator=(const GameClock& rhs);

		double mFrequency;

#if defined WINDOWS
		LARGE_INTEGER mStartTime;
		LARGE_INTEGER mCurrentTime;
		LARGE_INTEGER mLastTime;
#endif
	};
}
#endif