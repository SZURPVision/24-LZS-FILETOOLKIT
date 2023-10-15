#include "fileToolkit.hpp"
bool filetoolkit::FILETOOLKIT::isFileModifiedByTime(const std::string& path_){
    struct stat fileStat;
    static time_t lastModifiedTime = 0;
    if(stat(path_.c_str(), &fileStat) != 0){
        std::cerr << "Error stating file stats: " << stderr << std::endl;
        return false;
    }
    std::time_t modifiedTime = fileStat.st_mtime;
    if(lastModifiedTime == 0 && lastModifiedTime != modifiedTime){
        lastModifiedTime = modifiedTime;
        return false;
    }
    bool status = (modifiedTime - lastModifiedTime != 0);
    lastModifiedTime = modifiedTime;
    return status;  // 如果时间差为0，则文件未被修改
}

void filetoolkit::FILETOOLKIT::updateFile(const std::string& path_){
    this->reader(path_);
}
