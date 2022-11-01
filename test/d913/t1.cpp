#include <iostream>
#include<filesystem>
#include<regex>
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::filesystem::path pa("/home/jhc/桌面");
    pa/="Learn";
    //pa.remove_filename();
    std::filesystem::directory_iterator it(pa);
    std::regex re1(".*\\.md");
    for(;it !=std::filesystem::end(it);it++){
        if(std::regex_match(it->path().string(),re1)){
            std::cout<<it->path()<<std::endl;
        }
    }
    return 0;
}