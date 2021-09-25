#include <csignal>
#include <iostream>
#include <conio.h>

/*
	Source by CPPReference
	Modified For Learn by RK
	I.D.E : VS2019
*/

namespace {
	volatile std::sig_atomic_t gSignalStatus;
}

void signal_handler(int signal) {
	gSignalStatus = signal;
}

int main() {
	// Install a signal handler
	std::signal(SIGINT, signal_handler);

	std::cout << "SignalValue: " << gSignalStatus << '\n';
	std::cout << "Sending signal " << SIGINT << '\n';
	std::raise(SIGINT);
	std::cout << "SignalValue: " << gSignalStatus << '\n';

	_getch();
	return 0;
}