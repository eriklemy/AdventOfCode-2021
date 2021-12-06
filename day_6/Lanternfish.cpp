#include <iostream>
#include <fstream>
#include <array>
#include <sstream>
#include <vector>
#include <string>
#include <numeric>

std::vector<int> parseCommaSeparedFileNumbers();
uint64_t solvePartOneTwo(std::vector<int>& initialState, int days);

int main() {
    std::vector<int> initialState = parseCommaSeparedFileNumbers();

    std::cout << "Result <PartOne>: " << solvePartOneTwo(initialState, 80) << std::endl;
    std::cout << "Result <PartTwo>: " << solvePartOneTwo(initialState, 256) << std::endl;
}

uint64_t solvePartOneTwo(std::vector<int>& initialState, int days) {
    std::array<uint64_t, 9> lanternfish { 0 };

    for(auto i: initialState)
        ++lanternfish[i];
    
    for(size_t day = 0; day < days; day++) {
        size_t new_fish = lanternfish[0];
        lanternfish[0] = lanternfish[1];
        lanternfish[1] = lanternfish[2];
        lanternfish[2] = lanternfish[3];
        lanternfish[3] = lanternfish[4];
        lanternfish[4] = lanternfish[5];
        lanternfish[5] = lanternfish[6];
        lanternfish[6] = lanternfish[7];
        lanternfish[7] = lanternfish[8];
        lanternfish[6] += new_fish;
        lanternfish[8] = new_fish;
    }
    return std::accumulate(lanternfish.begin(), lanternfish.end(), 0ll); 
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