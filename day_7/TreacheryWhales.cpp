#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

uint64_t solverPartOneTwo(std::vector<int>& data, bool cst);
std::vector<int> parseCommaSeparedFileNumbers();

int main() {
    std::vector<int> data = parseCommaSeparedFileNumbers();
    
    std::cout << "Result <PartOne>: " << solverPartOneTwo(data, true) << std::endl;
    std::cout << "Result <PartTwo>: " << solverPartOneTwo(data, false) << std::endl;
}

uint64_t solverPartOneTwo(std::vector<int>& data, bool cst) {
    uint64_t minFuel = 1e9;
    size_t max = *std::max_element(data.begin(), data.end());
    std::cout << max << "\n";
    for(size_t num = 0; num < max; num++) {
        size_t fuel = 0;
        for(auto value:data) {
            size_t dist = abs(num - value);
            if(cst) fuel += dist;
            else fuel += ((dist * (dist + 1)) * 0.5);
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