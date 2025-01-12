#include "sedIsForLosers.hpp"

void	printError(ErrorCode code)
{
	switch (code) {
		case ARGCNT:
			std::cerr << "Not enough or too many arguments" << std::endl;
			break;
		case OPENWRERR:
			std::cerr << "Error opening file for writing" << std::endl;
			break;
		case OPENREADERR:
			std::cerr << "Error opening file for reading" << std::endl;
			break;
		default:
			std::cerr << "Error" << std::endl;
			break;
	}
}
