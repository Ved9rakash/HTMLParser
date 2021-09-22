
#include "../include/Parse.hpp"
#include <string>
#include <fstream>
#include <algorithm>


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
    m_fileName =  "../cmake-build-debug/src/" + m_fileName;
    std::pair<std::string, std::string> data;
    std::ifstream file(m_fileName);
    std::string savedFile = m_tag + ".txt";
    std::string currentLine;
    if (file.is_open())
    {
        while (std::getline(file, currentLine))
        {

            //Check if it exists
            if (currentLine.substr(0, m_tag.length() + 1) == ("<" + m_tag)) {

            }
        }
    }
}