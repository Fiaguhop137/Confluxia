#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <filesystem>
//#include "desktop.hpp"
std::uint64_t hash_file(const std::string& filename) {
    std::uint64_t hash=0xcbf29ce484222325;
    constexpr std::uint64_t prime=0x100000001b3;
    std::ifstream file(filename,std::ios::binary);
    if(file.is_open()&&std::filesystem::file_size(filename)<1280){
        std::vector<char> bytes(std::filesystem::file_size(filename));
        file.read(bytes.data(),bytes.size());
        for (char ch:bytes){
            hash^=static_cast<std::uint8_t>(ch);
            hash*=prime;
        }
    }
    return hash;
}
int main(){
    if(hash_file("LICENSE")==0xcbf29ce484222325){
        //desktop::run();
        std::cout<<"License verified. You can now run confluxia. \n";
    }else{
        std::cout<<"The license for this software is missing or has been modified. Please use the original license file to run confluxia. \n";
        std::cout<<std::to_string(hash_file("LICENSE"))<<" vs "<<std::to_string(0xc3f09ce3a24fbeab)<<"\n";
        return 402;
    }
}