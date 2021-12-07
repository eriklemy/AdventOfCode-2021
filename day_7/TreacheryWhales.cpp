#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

uint32_t solverPartOneTwo(std::vector<int>& data, bool cst);
std::vector<int> parseCommaSeparedFileNumbers();

int main() {
    std::vector<int> data = parseCommaSeparedFileNumbers();
    
    std::cout << "Result <PartOne>: " << solverPartOneTwo(data, true) << std::endl;
    std::cout << "Result <PartTwo>: " << solverPartOneTwo(data, false) << std::endl;
}

uint32_t solverPartOneTwo(std::vector<int>& data, bool cst) {
    auto minFuel = 1e9;
    auto max = *std::max_element(data.begin(), data.end());
    for(auto num = 0; num < max; num++) {
        auto fuel = 0;
        for(auto value:data) {
            auto dist = abs(num - value);
            fuel += cst ? dist:((dist * (dist + 1)) * 0.5); // [n * (n - 1)] / 2
            // if(cst) fuel += dist;
            // else fuel += ((dist * (dist + 1)) * 0.5);
        }
        if(fuel < minFuel) 
            minFuel = fuel;
    }
    return minFuel;
}

std::vector<int> parseCommaSeparedFileNumbers() {
    std::string line;
    std::vector<int> file;
    std::ifstream myfile("input.txt");
    while(getline(myfile, line)) {
        std::stringstream ss(line);
        for (int value; ss >> value; ) {
            file.push_back(value);
            if(ss.peek() == ',') ss.ignore();
        }
    }
    myfile.close();
    return file;
}