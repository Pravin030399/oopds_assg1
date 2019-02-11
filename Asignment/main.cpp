#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
int main()
{
    std::string filePath="D:/Pravin Assigment/Data/text/1.txt ";
    std::ifstream inputFile (filePath);

    std::stringstream buffer;
    std::string temp;
    buffer << inputFile.rdbuf();

    std::map<std::string,std::string> textDataMap;

    int lineNum(0);
    while(std::getline(buffer,temp,'\n')){ //access line by line
            std::string wordBuff="";
            for(int i=0;i<temp.length();i++) //access character by character
               {
                   if(temp[i] != ' ')
                   {
                       wordBuff += temp[i];
                   }
                    else{
                        if(wordBuff.length() != 0)
                            std::cout << wordBuff<<std::endl;
                         wordBuff="";
                    }
                  //
               }
       // std::cout << std::endl;
      lineNum++;
    }
    //std::cout << buffer.str() << std::endl;
    std::cout<<lineNum<<std::endl;

    return 0;
}
