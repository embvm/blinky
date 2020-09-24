#include <platform.hpp>

volatile bool abort_program_ = false;

int main()
{
	auto& platform = VirtualPlatform::inst();

	platform.startBlink();

	while(!abort_program_)
	{
		// spin
		// embvm::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

	return 0;
}
