#include <fstream>
#include <string>
#include <iostream>
#include "desktop.hpp"
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
        desktop::run();
    }else{
        std::cout<<"The license for this software is missing or has been modified. Please use the original license file to run confluxia. \n";
        return 402;
    }
}