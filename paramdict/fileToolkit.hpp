#ifndef ___FILE_TOOLKIT_HPP__
#define ___FILE_TOOLKIT_HPP__
#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <chrono>
#include <ctime>
#include <map>
#include <functional>
namespace filetoolkit{
using FILEReader = std::function<void(const std::string& path_)>;
class  FILETOOLKIT{
public:
    FILETOOLKIT(const std::string& path_) : path(path_){
        this->reader = [&](const std::string& path_){
            char buffer[4096];
            std::ifstream fin(path_);
            while (!fin.eof()){
                fin.getline(buffer, sizeof(buffer));
                std::string str(buffer);
                if (str.find(" ") < str.find("=")){
                    std::string variableName = str.substr(str.find(" ") + 1, str.find("=") - (str.find(" ") + 2));
                    std::string variableValue = str.substr(str.find("= ") + 2, str.size());
                    if(this->initFile){
                        this->paramDict.insert(std::make_pair(variableName, variableValue));
                        this->initFile = false;
                    }else{
                        this->paramDict[variableName] = variableValue;
                    }
                }
            }    
        };
        this->reader(path_);
    }
    ~FILETOOLKIT() = default;
    bool isFileModifiedByTime(const std::string& path_);
    void updateFile(const std::string& path_);
    std::map<std::string, std::string> paramDict; 
private:
    std::string path;
    FILEReader reader;
    bool initFile = true;
};
};
#endif