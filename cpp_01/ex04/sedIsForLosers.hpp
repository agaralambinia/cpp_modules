#ifndef SED_IS_FOR_LOSERS_HPP
# define SED_IS_FOR_LOSERS_HPP

#include <string>
#include <iostream>
#include <fstream>

enum ErrorCode
{
	ARGCNT,
	OPENWRERR,
	OPENREADERR
};

void	printError(ErrorCode code);
int		openFiles(std::string inputFileNm, std::string outputFileNm, std::ifstream *inputFile, std::ofstream *outputFile);
void	replace(char **argv, std::ifstream *inputFile, std::ofstream *outputFile);

#endif
