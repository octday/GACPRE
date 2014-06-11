#include <Base/StopWatch.h>

namespace gbase
{
	Win32StopWatch::Win32StopWatch() :
		mStartTime(), mEndTime(),
		mDiffTime(0.0), mFreqSet(false)
	{
		if (!mFreqSet) 
		{
			// helper variable
			LARGE_INTEGER temp;

			// get the tick frequency from the OS
			QueryPerformanceFrequency((LARGE_INTEGER*)&temp);

			// convert to type in which it is needed
			mFreq = ((double)temp.QuadPart);

			// rememeber query
			mFreqSet = true;
		}
	}

	Win32StopWatch::~Win32StopWatch()
	{

	}

	void Win32StopWatch::Start()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&mStartTime);
		mRunning = true;
	}

	void Win32StopWatch::Stop()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&mEndTime);
		mDiffTime = (float)(((double)mEndTime.QuadPart - (double)mStartTime.QuadPart) / mFreq);
		mRunning = false;
	}

	void Win32StopWatch::Reset()
	{
		mDiffTime = 0;
		if (mRunning)
			QueryPerformanceCounter((LARGE_INTEGER*)&mStartTime);
	}

	const float Win32StopWatch::GetTime() const
	{
		if (mRunning) 
		{
			return GetDiffTime();
		}
		else 
		{
			// time difference in seconds
			return mDiffTime;
		}
	}

	float Win32StopWatch::GetDiffTime() const
	{
		LARGE_INTEGER temp;
		QueryPerformanceCounter((LARGE_INTEGER*)&temp);
		return (float)(((double)temp.QuadPart - (double)mStartTime.QuadPart) / mFreq);
	}


	StopWatch::StopWatch()
	{
		mRunning = false;
	}

	StopWatch::~StopWatch()
	{

	}

	bool StopWatch::IsRunning()
	{
		return mRunning;
	}

	StopWatch* StopWatch::Create()
	{
#if defined _WIN32
		return new Win32StopWatch();
#else
		return nullptr;
#endif
	}

}