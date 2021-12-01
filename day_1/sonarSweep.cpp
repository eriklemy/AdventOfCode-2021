#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../benchmarkingFunction.h"

using namespace std;
void sonarSweepPartOne(vector<int> &depth);
void sonarSweepPartTwo(vector<int> &depth);

int main() {
    string line;
    vector<int> depth;
    
    ifstream myfile("input.txt");
    while(getline(myfile, line))
        depth.push_back(stoi(line));
    myfile.close();

    sonarSweepPartOne(depth);
    sonarSweepPartTwo(depth);
}

void sonarSweepPartOne(vector<int> &depth) {
    benchmarkingFunction time;
    size_t count = 0;
    for(size_t i = 0; i < depth.size() - 1; i++) {
        if(depth[i+1] > depth[i]) {
            count++;
        }
    }
    cout << "result <PartOne>: " << count  << endl;
}

void sonarSweepPartTwo(vector<int> &depth) {
    benchmarkingFunction time;
    size_t count = 0;
    // size_t auxMax = 0;
    for(size_t i = 0; i < depth.size() - 2; i++) {
		// auxMax = depth[i] + depth[i+1] + depth[i+2];
		if((depth[i+1] + depth[i+2] + depth[i+3]) > (depth[i] + depth[i+1] + depth[i+2])) {
			// auxMax = depth[i+1] + depth[i+2] + depth[i+3];
			count++;
		}
		// cout << auxMax << endl;
	}
    cout << "result <PartTwo>: " << count << endl;
}