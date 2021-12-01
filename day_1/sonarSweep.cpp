#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
int sonarSweepPartOne(vector<int> &depth);
int sonarSweepPartTwo(vector<int> &depth);

int main() {
    string line;
    vector<int> depth;
    
    ifstream myfile("input.txt");
    while(getline(myfile, line))
        depth.push_back(stoi(line));
    myfile.close();

    cout << "result <PartOne>: " << sonarSweepPartOne(depth) << endl;
    cout << "result <PartTwo>: " << sonarSweepPartTwo(depth) << endl;
}

int sonarSweepPartOne(vector<int> &depth) {
    size_t count = 0;
    for(size_t i = 0; i < depth.size() - 1; i++) {
        if(depth[i+1] > depth[i]) {
            count++;
        }
    }
    return count;
}

int sonarSweepPartTwo(vector<int> &depth) {
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
    return count;
}