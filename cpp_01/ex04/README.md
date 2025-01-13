Tests that can be run to check whether the program works properly:

1. Argument count checks:
	1. ./sed_is_for_losers 
		- Expected output: Not enough or too many arguments
	2. ./sed_is_for_losers a
		- Expected output: Not enough or too many arguments
	3. ./sed_is_for_losers a a
		- Expected output: Not enough or too many arguments
	4. ./sed_is_for_losers a a a a
		- Expected output: Not enough or too many arguments

2. File existance checks:
	1. ./sed_is_for_losers a a a
		- Expected output: Error opening file for reading

3. Checks of Replace function
	1. ./sed_is_for_losers tests/test1 lorem LLL
		- Creates a file tests/test1.replace with 10 "LLL"
	2. ./sed_is_for_losers tests/test1 ipsum AAA
		- Replaces file tests/test1.replace with 23 "AAA"
	3. ./sed_is_for_losers tests/test2 text AAA
		- Creates a file tests/test2.replace with "Some AAA"
	4. ./sed_is_for_losers tests/test2 TEXT aaa
		- Creates a file tests/test2.replace with "Some text"
	4. ./sed_is_for_losers tests/test2 o O
		- Creates a file tests/test2.replace with "SOme text"
	5. ./sed_is_for_losers tests/test3 o O
		- Creates empty file tests/test3.replace
	6. ./sed_is_for_losers tests/test4.replace o O
		- Creates a file tests/test4.replace.replace with "SOme text"
	7. ./sed_is_for_losers tests/test5.txt o O
		- Creates a file tests/test5.txt.replace with "SOme text"
 	8. ./sed_is_for_losers ./tests/aaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaaaaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaaqqqqqqqqqqqqqqaaaaaa a A
		- Error opening file for writing
