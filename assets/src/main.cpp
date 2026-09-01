#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "desktop.hpp"
constexpr int get_platform(){
    #if defined(__EMSCRIPTEN__)
        return 0;
    #elif defined(__ANDROID__)
        return 1;
    #else
        return 2;
    #endif
}
int main(){
    std::ifstream license("LICENSE");
    std::string line;
    bool licensed=false;
    while(std::getline(license, line)){
        if(line.find("Fiaguhop137")!=std::string::npos){
            licensed=true;
            break;
        }
    }
    if(licensed){
        int platform=get_platform();
        if(platform==0){std::cout<<"Web browser not yet supported. \n";}
        else if(platform==1){std::cout<<"Android not yet supported. \n";}
        else{desktop::run();}
    }else{
        std::cout<<"The license for this software is missing or has been modified. Please use the original license file to run confluxia. \n";
        return 402;
    }
}