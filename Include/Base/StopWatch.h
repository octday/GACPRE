#pragma once

#include <Base\Base.h>
#include <windows.h>

namespace gbase
{
	class BASE_API StopWatch
	{
	public:
		/// Constructor, default
		StopWatch();
		/// Destructor
		virtual ~StopWatch();

		static StopWatch* Create();

		/// Starts time measurement
		virtual void Start() = 0;

		/// Stop time measurement
		virtual void Stop() = 0;

		/// Reset time counters to zero
		virtual void Reset() = 0;

		/// Test whether the timer is running
		/// \return true if the timer is running (between #start() and #stop() calls) and false if not
		bool IsRunning();

		/// Get elapsed time
		/// Time in seconds after start. If the stop watch is still running (i.e. there
		/// was no call to #stop()) then the elapsed time is returned, otherwise the
		/// summed time between all #start() and #stop() calls is returned
		/// \return The elapsed time in seconds
		virtual const float GetTime() const = 0;

	protected:
		bool mRunning;
	};

	class Win32StopWatch : public StopWatch
	{
	public:
		//! Constructor, default
		Win32StopWatch();

		// Destructor
		virtual ~Win32StopWatch();

		//! Start time measurement
		void Start();

		//! Stop time measurement
		void Stop();

		//! Reset time counters to zero
		void Reset();

		const float GetTime() const;

	protected:

		// helper functions

		//! Get difference between start time and current time
		float GetDiffTime() const;

	private:

		// member variables

		//! Start of measurement
		LARGE_INTEGER  mStartTime;
		//! End of measurement
		LARGE_INTEGER  mEndTime;

		//! Time difference between the last start and stop
		float  mDiffTime;

		//! tick frequency
		double  mFreq;

		//! flag if the frequency has been set
		bool  mFreqSet;
	};

}