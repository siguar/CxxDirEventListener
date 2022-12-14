#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}


int main(){
	std::cout << "start";
	bool keepgoing = true;

	std::cout << exec("ls /home/hraqe-pro/Documents/file");

//while(keepgoing){

//	std::system("ls /home/hraqe-pro/Documents/file");


//}
	


	return 0;
}