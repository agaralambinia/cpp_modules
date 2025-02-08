#include "RPN.hpp"

/*
Possible test examples

Error tests
./RPN
./RPN a
./RPN +
./RPN "5 +"
./RPN "10 0 /"
./RPN "5 2 a"
./RPN "5 2 % 3"
./RPN "2147483647 1 +"
./RPN "2147483647 2147483647 +"
./RPN "-2147483648 1 -"
./RPN "11 11 *"

Simple tests
./RPN "5 2 +"        		# Expected output: 7
./RPN "10 5 -"       		# Expected output: 5
./RPN "3 4 *"        		# Expected output: 12
./RPN "10 4 /"       		# Expected output: 2
./RPN "  5   2   +  "		# Expected output: 7
./RPN "5  2   +   3   *"	# Expected output: 21
./RPN "-5 3 +"				# Expected output: -2

Complex expressions
./RPN "5 2 + 3 *"    								# Expected output: 21
./RPN "10 5 3 + 2 * -"  							# Expected output: -6
./RPN "4 2 + 3 * 1 -"   							# Expected output: 13
./RPN "1 2 3 4 5 6 7 8 9 10 + + + + + + + + *"    	# Expected output: 54
./RPN "10 5 3 + 2 * - 7 + 3 / 2 * 4 -"      		# Expected output: -4

*/

int main(int argc, char** argv) {
	RPN calculator;

	return calculator.Calculate(argc, argv);
}
