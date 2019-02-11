#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctype.h>
#include <vector>
#include <algorithm>
int main()
{
    std::string filePath="D:/Pravin Assigment/Data/StopWords.txt ";
    std::ifstream inputFile (filePath);

    std::stringstream buffer;
    std::string temp;
    buffer << inputFile.rdbuf();

    std::map<std::string,std::string> textDataMap;
    std::vector<std::string> stopWord;

    while(std::getline(buffer,temp,'\n')){ //access line by line
           stopWord.push_back(temp);
    }

//    for(std::vector<std::string>::iterator it = stopWord.begin(); it != stopWord.end();it++)
//    {
//        std::cout<<*it<<std::endl;
//    }

    inputFile.close();
    filePath="D:/Pravin Assigment/Data/text/1.txt ";
    inputFile.open(filePath);
    int lineNum(0);
    buffer << inputFile.rdbuf();
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
                        if(wordBuff.length() != 0 && std::find(stopWord.begin(),stopWord.end(),wordBuff)==stopWord.end())
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

//  for(std::map<std::string,std::string>::iterator it = textDataMap.begin(); it != textDataMap.end(); it++)
//  {
//      std::cout << it->first << " = " << it->second <<std::endl;
//  }
    std::string userInput;
    while (userInput!="quit")
    {
        std::string wordBuff="";
        std::cout<<"Please enter Key word to search: ";
        std::getline(std::cin,userInput);

        for(int i=0;i<userInput.length();i++) //access character by character
               {
                   if(userInput[i] != ' '   && isalnum(userInput[i]))
                   {
                       wordBuff += tolower(userInput[i]);
                   }
                    else{

                        if(wordBuff.length() != 0)
                        {
                            std::stringstream ss;
                            if(textDataMap.find(wordBuff) != textDataMap.end()) // if wordbuff not exist
                            {

                                std::cout<<wordBuff << " " << textDataMap[wordBuff]<<std::endl;
                            }
                            else
                            {
                             std::cout<<wordBuff<<" Key word doesn't exist"<<std::endl;
                            }

                        }
                         wordBuff="";
                    }

                    // last keyword exception
                   if(i == (userInput.length()-1) )
                   {
                        if(wordBuff.length() != 0)
                        {
                            std::stringstream ss;
                            if(textDataMap.find(wordBuff) != textDataMap.end()) // if wordbuff not exist
                            {

                                std::cout<<wordBuff << " " <<textDataMap[wordBuff]<<std::endl;
                            }
                            else
                            {
                             std::cout<<wordBuff<<" Key word doesn't exist"<<std::endl;
                            }

                        }
                         wordBuff="";
                   }
               }
    }

    return 0;
}
