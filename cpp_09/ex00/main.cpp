#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	BitcoinExchange btc;

	try {
		btc.exchange(argc, argv);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}
