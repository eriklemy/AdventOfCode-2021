#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

int Result(std::vector<std::vector<int>>& table);
int getMax(int a, int b, int c);
std::vector<std::array<int, 4ULL>> parseFileLine(std::array<int, 2>& size);

int main () {
	std::vector<std::array<int, 4>> data;
	std::array<int, 2> size = {0, 0};
	data = parseFileLine(size);

	// table of values to compute
  	std::vector<std::vector<int>> table(size[0] + 1, std::vector<int>(size[1] + 1, 0)); 

	// Horizontal and Vertical
	for(auto line: data) {
		if(line[0] == line[2]) {
			int x = line[0];
			int y = std::min(line[1], line[3]);
			int y_end = std::max(line[1], line[3]);
			for(size_t i = y; i <= y_end ; i++)  ++table[x][i];
		} 
		else if(line[1] == line[3] ) {
			int y = line[1];
			int x = std::min(line[0], line[2]);
			int x_end = std::max(line[0], line[2]);
			for(size_t i = x; i <= x_end ; i++) {
				++table[i][y];
			}
		}
	}
	std::cout << "Result <PartOne>: " << Result(table) << std::endl;

	// Diagonal
	for(auto line: data) {
		if(line[0] != line[2] && line[1] != line[3]) {
			int x = line[0];
			int y = line[1];
			int x2 = line[2];
			int y2 = line[3];

			if(y < y2 && x < x2) {
				for (size_t i = y; i <= y2 ; i++) {
					++table[x++][i];
				}
			} else if(y < y2 && x > x2) {
				for(size_t i = y; i <= y2; i++) {
					++table[x--][i];
				}
			} else if(y > y2 && x < x2) {
				for(size_t i = y; i >= y2; i--) {
					++table[x++][i];
				}
			} else {
				for(size_t i = y; i >= y2 ; i--) {
					++table[x--][i];
				}
			}
		}
	}

	std::cout << "Result <PartTwo>: " << Result(table) << std::endl;	
}

int Result(std::vector<std::vector<int>>& table) {
	int count = 0;
	for(auto line: table) {
		for(auto value : line) {
			if(value > 1) count++;
		}
	}
	return count;
}

int getMax(int a, int b, int c) {
	if(a >= b && a >= c) return a;
    if(b >= a && b >= c) return b;
    return c;
}

std::vector<std::array<int, 4ULL>> parseFileLine(std::array<int, 2>& size) {
	std::vector<std::array<int, 4>> data;
	std::ifstream input("input.txt");
	while(!input.eof()) { 
		int x1, y1, x2, y2;
		std::string line, arrow;

		// line: x1, y1 -> x2, y2
		std::getline(input, line);
		std::replace(line.begin(), line.end(), ',', ' ');
		std::istringstream linestream(line);

		while (linestream >> x1 >> y1 >> arrow >> x2 >> y2) {
			data.push_back({x1, y1, x2, y2});
			size[0] = getMax(size[0], x1, x2);
			size[1] = getMax(size[1], y1, y2);
		}
	}
	return data;
}