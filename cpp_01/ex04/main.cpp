#include "sedIsForLosers.hpp"

int main(int argc, char **argv)
{
	std::string inputFileNm;
	std::string outputFileNm;
	std::ifstream inputFile;
	std::ofstream outputFile;

	if (argc != 4)
	{
		printError(ARGCNT);
		return (1);
	}
	inputFileNm = argv[1];
	outputFileNm = outputFileNm + argv[1] + ".replace";
	if (openFiles(inputFileNm, outputFileNm, &inputFile, &outputFile))
		return (1);
	replace(argv, &inputFile, &outputFile);
	inputFile.close();
	outputFile.close();
	return (0);
}
