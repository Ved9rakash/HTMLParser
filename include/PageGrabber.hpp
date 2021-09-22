//
// Created by Vaibhav on 15-09-2021.
//

#pragma once

#include <curl/curl.h>
#include <memory>
#include <functional>
#include <stdexcept>
#include <exception>
#include <ios>
#include <fstream>


using EasyHandle = std::unique_ptr<CURL, std::function<void(CURL*)>>;

//By default, CURL prints output in Terminal/Shell, so we write it in file.
namespace sync
{
    namespace fileHandle
    {
        size_t writeToFile(void* contents, size_t size, size_t nmemb, void* userp);
        void saveToFile(CURL* curl, std::string fileName);
    }
    void setSSL(CURL* curl);
    EasyHandle CreateEasyHandle();
}

//Initializing curl and clearing up curl after object is destroyed.
class CurlGlobalStateGuard
{
public:
    CurlGlobalStateGuard();
    ~CurlGlobalStateGuard();
};
