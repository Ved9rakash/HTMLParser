//
// Created by Vaibhav on 15-09-2021.
//
#include "../include/PageGrabber.hpp"

#include <curl/curl.h>
#include <memory>
#include <functional>
#include <stdexcept>
#include <exception>
#include <ios>

using EasyHandle = std::unique_ptr<CURL, std::function<void(CURL*)>>;

namespace sync
{
    namespace fileHandle
    {
        size_t writeToFile(void* contents, size_t size, size_t nmemb, void* userp)
        {
            long realsize = static_cast<long>(size * nmemb);
            auto file = reinterpret_cast<std::ofstream*>(userp);
            file->write(reinterpret_cast<const char*>(contents), realsize);
            return realsize;
        }

        void saveToFile(CURL* curl, const std::string fileName)
        {
            static std::ofstream file(fileName, std::ios::binary);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, sync::fileHandle::writeToFile);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, reinterpret_cast<void*>(&file));
        }
    }

    void setSSL(CURL* curl)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    }

    EasyHandle CreateEasyHandle()
    {
        auto curl = EasyHandle(curl_easy_init(), curl_easy_cleanup);
        if (!curl)
        {
            throw std::runtime_error("Failed creating CURL easy object.");
        }
        return curl;
    }
}