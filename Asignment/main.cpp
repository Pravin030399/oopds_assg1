#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int main()
{
    std::string filePath="D:/Pravin Assigment/Data/text/1.txt ";
    std::ifstream inputFile (filePath);

    std::stringstream buffer;
    buffer << inputFile.rdbuf();



    std::cout << buffer.str() << std::endl;
    return 0;
}
