#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for(int word=1; argv[word]; word++)
    {
        for(int letter=0; argv[word][letter]; letter++)
        {
            std::cout << (char)std::toupper(argv[word][letter]);
        }
        if (word != argc-1)
            std::cout<< ' ';
    }
    return 0;
}