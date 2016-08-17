
#include <atomic>
#include <thread>
#include <chrono>

namespace
{
	std::atomic_int64_t timestamp = 0;
	std::atomic_bool join = false;
	std::thread thread;

	void watchdog()
	{
		int64_t prev = 1;
		while (!join.load())
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));

			auto current = timestamp.load();

			if (current == prev && !join.load())
				std::terminate();

			prev = current;
		}
	}
}

void tick()
{
	timestamp.store(std::chrono::high_resolution_clock::now().time_since_epoch().count());
}


void launch_watchdog()
{
	join.store(false);
	tick();

	thread = std::thread(watchdog);
}
void terminate_watchdog()
{
	tick();
	join.store(true);

	thread.join();
}

