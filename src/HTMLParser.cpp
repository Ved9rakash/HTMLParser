#include "../include/PageGrabber.hpp"
//#include "../include/Parse.hpp"

#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <algorithm>

int main()
{
    const std::string fileName = "Download.txt";
    //Creating handles to download network content.
    std::vector<EasyHandle> handles(1);


    //Create easy handles and Loop through the EasyHandle container.
    try{
        std::for_each(handles.begin(), handles.end(), [] (auto& handle){ handle = sync::CreateEasyHandle(); });
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        return -1;
    }

    for (auto& handle : handles)
    {
        //Setting the options and URL for handles which to be downloaded.
        curl_easy_setopt(handle.get(), CURLOPT_URL, "https://github.com/LesleyLai/cmake-cpp-boilerplate/blob/main/CMakeLists.txt");
        //switching OFF the SSL connection (Less complex)
        sync::setSSL(handle.get());
        //Saving the extracted handled data to file name 'fileName'.
        sync::fileHandle::saveToFile(handle.get(), fileName);

        //Perform the requests, requests with return code.
        auto requests = curl_easy_perform(handle.get());
        if (requests != CURLE_OK){
            std::cerr << "curl_easy_perform() failed." << curl_easy_strerror(requests) << '\n';
            return -1;
        }
    }

    //HTML Parsing
//    Parse parseData;

    return 0;
}