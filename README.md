# FILETOOLKIT
## paramdict 
### TODO::为了方便调参,不用重新编译,可以程序一边跑一边更改参数.
### TODO::我用的是ROS2的时基回调,每隔1s检测检测文件是否被修改,运用互斥锁来防止同时读写this->paramDict的情况,如果只是单线程,随便放在循环某个会跑到的位置就好了.
### TODO::缺点,对文本进行修改操作,不够优雅,没有web,不会,不想学,懒.
### bool filetoolkit::FILETOOLKIT::isFileModifiedByTime(const std::string& path_)简单用文件修改时间来判断是否被修改.
### void filetoolkit::FILETOOLKIT::updateFile(const std::string& path_)读取文件中的参数并保存在this->paramDict里面.
### 参数格式参照paramdict/param.txt.
