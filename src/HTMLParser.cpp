#include "../include/PageGrabber.hpp"

#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<EasyHandle> handles(1);
    try
    {
        std::for_each(
                handles.begin(), handles.end(), [] (auto& handle){ handle = sync::CreateEasyHandle(); }
                );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    for (auto& handle : handles)
    {
        curl_easy_setopt(handle.get(), CURLOPT_URL, "https://github.com/LesleyLai/cmake-cpp-boilerplate/blob/main/CMakeLists.txt");
        sync::setSSL(handle.get());
        sync::fileHandle::saveToFile(handle.get(), "Downloaded.txt");

        auto res = curl_easy_perform(handle.get());
        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed." << curl_easy_strerror(res) << '\n';
            return -1;
        }
    }
    return 0;
}