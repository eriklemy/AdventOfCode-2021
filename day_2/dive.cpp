#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <array>
using namespace std;

void divePartOne(vector<string> &commands, vector<int> &movements);
void divePartTwo(vector<string> &commands, vector<int> &movements);

int main() {
    string line;
    vector<string> commands;
    vector<int> movements;
    string command;
    int movement;

    ifstream myfile("input.txt");
    while(getline(myfile, line)) {
        stringstream ss(line);
        getline(ss, command, ' ');
        ss >> movement;
        // cout << command << ": " << movement << endl;
        commands.push_back(command);
        movements.push_back(movement);
    }
    divePartOne(commands, movements);
    divePartTwo(commands, movements);
}

void divePartOne(vector<string> &commands, vector<int> &movements) {
    int horizontal, vertical;
    horizontal = vertical = 0;
    for(size_t i = 0; i < commands.size(); i++) {
        if(commands[i] == "forward") {
            horizontal += movements[i];
        }
        else if(commands[i] == "down") {
            vertical += movements[i];
        }
        else {
            vertical -= movements[i];
        }
    }
    cout << horizontal * vertical << endl;
}

void divePartTwo(vector<string> &commands, vector<int> &movements) {
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
        else {
            aim -= movements[i];
        }
    }
    cout << horizontal * depth << endl;
}