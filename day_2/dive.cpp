#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "../benchmarkingFunction.h"

using namespace std;

void divePartOne(vector<string> &commands, vector<int> &movements);
void divePartTwo(vector<string> &commands, vector<int> &movements);

int main() {
    int movement;
    string line, command;
    vector<string> commands;
    vector<int> movements;

    ifstream myfile("input.txt");
    while(getline(myfile, line)) {
        stringstream ss(line);
        getline(ss, command, ' ');
        ss >> movement;

        commands.push_back(command);
        movements.push_back(movement);
    }
    divePartOne(commands, movements);
    divePartTwo(commands, movements);
}

void divePartOne(vector<string> &commands, vector<int> &movements) {
    // benchmarkingFunction time;

    int horizontal, vertical;
    horizontal = vertical = 0;
    for(size_t i = 0; i < commands.size(); i++) {
        if(commands[i] == "forward") {
            horizontal += movements[i];
        }
        else if(commands[i] == "down") {
            vertical += movements[i];
        }
        else vertical -= movements[i];
    }
    cout << "result <PartOne>: " << horizontal * vertical << endl;
}

void divePartTwo(vector<string> &commands, vector<int> &movements) {
    // benchmarkingFunction time;

    int horizontal, aim, depth;
    horizontal = aim = depth = 0;
    for(size_t i = 0; i < commands.size(); i++) {
        if(commands[i] == "forward") {
            horizontal += movements[i];
            depth += movements[i] * aim;
        }
        else if(commands[i] == "down") {
            aim += movements[i];
        }
        else aim -= movements[i];
    }
    cout << "result <PartTwo>: " << horizontal * depth << endl;
}