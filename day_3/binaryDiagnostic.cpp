#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
// #include "../benchmarkingFunction.h"

using namespace std;
string gamma(vector<int> &result, vector<string> &power);
string epsilon(vector<int> &result, vector<string> &power);
vector<int> binaryDiagnosticPartOne(vector<string> &power);
vector<string> binaryDiagnosticPartTwo(vector<string> &power, const string &type);

int main() {
    // benchmarkingFunction time;
    string line;
    vector<string> power;
    
    ifstream myfile("input.txt");
    while(getline(myfile, line))
        power.push_back(line);
    myfile.close();

    auto result = binaryDiagnosticPartOne(power);
    int O2 = stoi(binaryDiagnosticPartTwo(power, "O2")[0], 0, 2);
    int CO2 = stoi(binaryDiagnosticPartTwo(power, "CO2")[0], 0, 2);

    // stoi converte para inteiro e de decimal para binario
    cout << "result <PartOne>: " << stoi(gamma(result, power),0 ,2) * stoi(epsilon(result, power), 0, 2) << endl;
    cout << "result <PartTwo>: " << (O2 * CO2) << endl;
}

vector<string> binaryDiagnosticPartTwo(vector<string> &power, const string &type) {
    char filter; 
    int currentPos = 0;
    vector<string> currentResult = power;
    
    while(currentResult.size() != 1) {
        vector<string> nextSequenceOfBits;
        auto binaryCount = binaryDiagnosticPartOne(currentResult);
        
        if(type == "O2")
            filter = (binaryCount[currentPos] >= (currentResult.size() - binaryCount[currentPos])) ? '1' : '0';
        else filter = (binaryCount[currentPos] >= (currentResult.size() - binaryCount[currentPos])) ? '0' : '1';
        
        
        copy_if(currentResult.begin(), currentResult.end(), back_inserter(nextSequenceOfBits), 
            [currentPos, filter] (string &currentLine) { // lambda
                return currentLine[currentPos] == filter;
            }
        );
        currentResult = nextSequenceOfBits;
        currentPos++;
    }
    return currentResult;
}


string gamma(vector<int> &result, vector<string> &power) {
    string gamma;
    for(size_t value = 0; value < result.size(); value++)
        gamma += (result[value] > (power.size() - result[value])) ? "1" : "0";
    return gamma;
}

string epsilon(vector<int> &result, vector<string> &power) {
    string epsilon;
    for(size_t value = 0; value < result.size(); value++)
        epsilon += (result[value] < (power.size() - result[value])) ? "1" : "0";
    return epsilon;
}

vector<int> binaryDiagnosticPartOne(vector<string> &power) {
    vector<int> count(power[0].size(), 0);
    for(size_t line = 0; line < power.size(); line++) {
        for(size_t i = 0; i < power[0].size(); i++){
            if(power[line].at(i) == '1') 
                count[i] += 1;
        }
    }
    return count;
}