#include <fstream>
#include <string>
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
    else{return 17;}
}