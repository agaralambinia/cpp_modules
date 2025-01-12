#include "sedIsForLosers.hpp"

int openFiles(std::string inputFileNm, std::string outputFileNm, std::ifstream *inputFile, std::ofstream *outputFile)
{
	(*inputFile).open(inputFileNm, std::fstream::in);
	if (!inputFile->is_open()) {
		printError(OPENREADERR);
		(*inputFile).close();
        return 1;
    }
	(*outputFile).open(outputFileNm, std::fstream::out);
	if (!outputFile->is_open()) {
		printError(OPENWRERR);
		(*inputFile).close();
		(*outputFile).close();
        return (1);
    }
	return (0);
}

void	replace(char **argv, std::ifstream *inputFile, std::ofstream *outputFile)
{
	std::string 			findStr;
	std::string 			replaceStr;
	std::string 			ln;
	std::string::size_type	found;
	size_t					foundEndPos;
	std::string				replacedLn;

	findStr = *(argv + 2);
	replaceStr = *(argv + 3);
	foundEndPos = 0;

	while(std::getline(*inputFile, ln))
	{
		replacedLn.clear();
		foundEndPos = 0;
		found = ln.find(findStr);
		if (found != std::string::npos)
		{
			while (found != std::string::npos)
			{
				replacedLn.append(ln, foundEndPos, found - foundEndPos);
				replacedLn += replaceStr;
				foundEndPos = found + findStr.length();
				found = ln.find(findStr, foundEndPos);
				if (found == std::string::npos)
					replacedLn.append(ln, foundEndPos, ln.length());
			}
		}
		else
			replacedLn = ln;
		if (!(*inputFile).eof())
			*outputFile << replacedLn << std::endl;
		else
			*outputFile << replacedLn;
	}
}
