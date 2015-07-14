#ifndef GAMETIME_H
#define GAMETIME_H

namespace Core
{
	class GameTime
	{
	public:
		GameTime();

		double TotalGameTime() const;
		void SetTotalGameTime(double totalGameTime);

		double ElapsedGameTime() const;
		void SetElapsedGameTime(double elapsedGameTime);

	private:
		double mTotalGameTime;
		double mElapsedGameTime;
	};
}
#endif