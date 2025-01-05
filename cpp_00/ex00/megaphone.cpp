#include <iostream>
#include <cctype>

void megaphone(char *str) {
    while (*str) {
        std::cout << (char)std::toupper(*str);
        str++;
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; ++i) {
            megaphone(argv[i]);
            if (i < argc - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
