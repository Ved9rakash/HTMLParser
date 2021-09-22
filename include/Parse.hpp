
#pragma once

#include "PageGrabber.hpp"
#include <string>


class Parse
{
public:
    explicit Parse();
    Parse(std::string fileName, std::string tagName);

    void setFile(std::string fileName);
    void setTag(std::string tagName);

    void GetData();

private:
    std::string m_fileName{};
    std::string m_tag{};
};
