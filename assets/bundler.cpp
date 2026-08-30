#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <cctype>
namespace fs=std::filesystem;
std::string make_identifier(std::string name){
    std::string result;
    for(char c:name){
        if(std::isalnum(static_cast<unsigned char>(c))||c=='_'){
            result+=c;
        }
        else{
            result+='_';
        }
    }
    if(result.empty()){
        result="asset";
    }
    if(std::isdigit(static_cast<unsigned char>(result[0]))){
        result="_"+result;
    }
    return result;
}
std::string read_file(const fs::path& path){
    std::ifstream file(path, std::ios::binary);
    if(!file){
        throw std::runtime_error("Could not open "+path.string());
    }
    return std::string(std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>());
}
void generate_header(const fs::path& json_path,const fs::path& output_path){
    std::string name=json_path.stem().string();
    std::string identifier=make_identifier(name);
    std::string data=read_file(json_path);
    std::ofstream output(output_path);
    if(!output){
        throw std::runtime_error("Could not create "+output_path.string());
    }
    output<<"#pragma once\n\n";
    output<<"#include <string_view>\n\n";
    output<<"namespace confluxed_assets{\n\n";
    output<<"inline constexpr std::string_view "<<identifier<<"=R\"JSON(";
    output<<data;
    output<<")JSON\";\n\n";
    output<<"}\n";
}
int main(){
    const fs::path assets_dir="assets";
    const fs::path output_dir="assets";
    fs::create_directories(output_dir);
    for(const auto& entry :fs::recursive_directory_iterator(assets_dir)){
        if(!entry.is_regular_file()){
            continue;
        }
        if(entry.path().extension() !=".json"){
            continue;
        }
        std::filesystem::path relative=fs::relative(entry.path(), assets_dir);
        fs::path output_path=output_dir / relative;
        output_path.replace_extension(".hpp");
        fs::create_directories(output_path.parent_path());
        try{
            generate_header(entry.path(), output_path);
            std::cout<<"Generated "<<output_path<<'\n';
        }
        catch(const std::exception& e){
            std::cerr<<"Error processing "<<entry.path()<<": "<<e.what()<<'\n';
            return 1;
        }
    }
    std::cout<<"Done.\n";
}
