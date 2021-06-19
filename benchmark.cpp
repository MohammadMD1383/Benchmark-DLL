#include <chrono>
#include <map>
#include "benchmark.h"

#undef DEFAULT_ARG
#define DEFAULT_ARG

using namespace std;

typedef chrono::high_resolution_clock    hrClock;
typedef chrono::steady_clock::time_point tPoint;

typedef chrono::seconds      seconds;
typedef chrono::milliseconds milliseconds;
typedef chrono::microseconds microseconds;
typedef chrono::nanoseconds  nanoseconds;

using chrono::duration_cast;

static auto timers = map<MAP_KEY, pair<tPoint, tPoint>>();

START_TIMER {
	ARG_REPLACE
	
	if (!timers.contains(n))
		timers[n].first = hrClock::now();
	
	RETURN_VOID;
}

STOP_TIMER {
	tPoint now = hrClock::now();
	
	ARG_REPLACE
	
	if (timers.contains(n))
		timers[n].second = now;
	
	RETURN_VOID;
}

GET_TIMER_SECONDS {
	ARG_REPLACE
	
	if (timers.contains(n))
		RETURN_TIME(duration_cast<seconds>(timers[n].second - timers[n].first).count());
	
	RETURN_ZERO;
}

GET_TIMER_MILLI_SECONDS {
	ARG_REPLACE
	
	if (timers.contains(n))
		RETURN_TIME(duration_cast<milliseconds>(timers[n].second - timers[n].first).count());
	
	RETURN_ZERO;
}

GET_TIMER_MICRO_SECONDS {
	ARG_REPLACE
	
	if (timers.contains(n))
		RETURN_TIME(duration_cast<microseconds>(timers[n].second - timers[n].first).count());
	
	RETURN_ZERO;
}

GET_TIMER_NANO_SECONDS {
	ARG_REPLACE
	
	if (timers.contains(n))
		RETURN_TIME(duration_cast<nanoseconds>(timers[n].second - timers[n].first).count());
	
	RETURN_ZERO;
}

DESTROY_TIMER {
	ARG_REPLACE
	
	if (timers.contains(n))
		timers.erase(n);
	
	RETURN_VOID;
}
