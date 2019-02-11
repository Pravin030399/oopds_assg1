#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctype.h>
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
            int Pos = 0;
            for(int i=0;i<temp.length();i++) //access character by character
               {
                   if(temp[i] != ' ' && isalnum(temp[i]))
                   {
                       wordBuff += tolower(temp[i]);
                   }
                    else{
                        if(wordBuff.length() != 0)
                        {
                            std::stringstream ss;
                            if(textDataMap.find(wordBuff) == textDataMap.end()) // if wordbuff not exist
                            {
                                ss << "line:"  << lineNum << ",Pos:"<< Pos;
                                textDataMap[wordBuff] = ss.str();
                            }
                            else{
                                ss << "|line:" << lineNum << ",Pos:" << Pos;
                                textDataMap[wordBuff] += ss.str();
                            }
                        }
                         wordBuff="";
                         Pos=i;
                    }
                  //
               }
       // std::cout << std::endl;
      lineNum++;
    }
    //std::cout << buffer.str() << std::endl;
  //  std::cout<<lineNum<<std::endl;

  for(std::map<std::string,std::string>::iterator it = textDataMap.begin(); it != textDataMap.end(); it++)
  {
      std::cout << it->first << " = " << it->second <<std::endl;
  }
    return 0;
}
