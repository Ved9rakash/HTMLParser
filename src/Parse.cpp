
#include "../include/Parse.hpp"
#include <string>
#include <fstream>
#include <algorithm>
#include <tuple>
#include <iostream>


Parse::Parse() { }

Parse::Parse(std::string fileName, std::string tagName)
{
    m_fileName = fileName;
    m_tag = tagName;
}


void Parse::setFile(const std::string fileName)
{
    m_fileName = fileName;
}

void Parse::setTag(std::string tagName)
{
    m_tag = tagName;
}

void Parse::GetData()
{
    std::vector<std::pair<std::string, std::string>> data;

    m_fileName =  "../cmake-build-debug/src/" + m_fileName;
    std::ifstream file(m_fileName);
    std::string currentLine;
    if (file.is_open())
    {
        while (std::getline(file, currentLine))
        {
            int index;
            std::string first, second;
            int i = m_tag.length()+1;
            //Check if it exists
            if (currentLine.substr(0, i) == ("<" + m_tag)) {
                std::cout << "Line met";
                for (; currentLine.length(); ++i) {
                    if (currentLine[i] == '>') {
                        index = i;
                        break;
                    }
                }
                first = currentLine.substr(m_tag.length()+1, i);

                for (; currentLine.length(); ++i) {
                    if (currentLine[i] == '<') {
                        index = i;
                        break;
                    }
                }
                second = currentLine.substr(index + 1, i);
            }
            data.emplace_back(first, second);
        }
        std::string savedFile = m_tag + ".txt";
        std::ofstream savefile(savedFile);
        for (const auto& element : data)
        {
            savefile << element.first << " : " << element.second;
        }
    }
}
