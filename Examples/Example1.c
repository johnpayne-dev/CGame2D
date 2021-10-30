#include <CGame2D/CGame.h>

int main(int argc, char * argv[])
{
	cgWindowFlags config =
	{
		.resizable = true,
		.highDPI = true,
	};
	cgInitialize(1280, 720, "Example1", config);
	
	while (cgWindowIsRunning())
	{
		cgEventPoll();
	}
	
	cgShutdown();
	return 0;
}
