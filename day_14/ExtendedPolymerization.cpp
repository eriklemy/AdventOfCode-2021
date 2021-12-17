#include <iostream>
#include <vector>
#include <vector> 
#include <queue>
#include <fstream>
#include <sstream>

std::vector<std::string> parseArrowSeparedFile() {
    std::string line;
    std::vector<std::string> file;
    std::ifstream myfile("input.txt");
    while(getline(myfile, line)) {
        std::stringstream ss(line);
        for(std::string value; ss >> value; ) {
            file.push_back(value);
            if(ss.peek() == '->') ss.ignore();
        }
    }
    myfile.close();
    return file;
}

int main() {
	std::vector<std::string> data = parseArrowSeparedFile();
	for (auto value: data)
		std::cout << value << " \n";
}
