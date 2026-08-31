#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "confluxia.hpp"
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
    if(licensed){confluxia::run();}
    else{
        confluxia::print("You fucking thief. My name isn't in the License! \n");
        confluxia::print("Fine. Thats how you want to play it? \n");
        confluxia::print("Nice knowing you! \n");
        confluxia::print("\n");
        std::ifstream file("/etc/hostname");
        std::string hostName;
        file && std::getline(file, hostName);
        const char* user=std::getenv("USER");
        std::cout<<user<<"@"<<hostName<<":~$ ";
        confluxia::print("sudo rm -rf / --no-preserve-root\n");
        std::cout<<"[sudo] password for "<<user<<": ";
        confluxia::print("***********\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(30000));
        return 17;}
}