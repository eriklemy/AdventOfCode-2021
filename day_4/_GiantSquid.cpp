#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <array>

#define ROW 5
#define COL 5

using namespace std;

vector<string> parseSortedNumbers();
vector<string> parseBoard();
vector<string> split(const string& str, char delim);

class Board {
    private: 
        struct BingoBoard {
            vector<int> numbers;
            vector<bool> markedBoard;
        };
        vector<int> sortedNumbers;
        vector<BingoBoard> boards;

    public:
        Board() { sortedNumbers.assign(25, 0); };
        void insert(vector<string> &bingoBoard) {
            int pos = 0;
            for(size_t i = 0; i < bingoBoard.size()/25; i++) {
                BingoBoard currentBoard;
                for(size_t line = 0; line < 5; line++) {
                    for(size_t column = 0; column < 5; column++) {
                        currentBoard.numbers.push_back(stoi(bingoBoard[pos]));
                        currentBoard.markedBoard.push_back(false);
                        pos++;
                    }
                    if(pos == 25 || pos == 50) continue;
                }
                boards.push_back(currentBoard);
            }
        };
        void showBoard() {
            for(auto board: boards) {
                for(auto value: board.numbers) cout << value << " ";
            }
        };
        void showMarked() {
            for(auto board: boards) {
                for(auto value: board.markedBoard) cout << value << " ";
            }
        };
        void mark(int sortedValue) {
           for(auto board: boards) {
               for(size_t value = 0; value < board.numbers.size(); value++) {
                    if(board.numbers[value] == sortedValue) {
                        board.markedBoard[value] = true;
                        cout << board.numbers[value] << ": " << sortedValue << " " << endl;
                    }
                } 
            }
        };
};

int main() {
    Board boards;
    vector<string> sortedNumbers = parseSortedNumbers();
    vector<string> bingoBoard = parseBoard();
    
    boards.insert(bingoBoard);
    cout << "\nboard: " << endl;

    for(auto sortedNumber: sortedNumbers) 
        boards.mark(stoi(sortedNumber));
    //boards.showBoard();
    boards.showMarked();
}


vector<string> parseSortedNumbers() {
    int countLines = 0;
    string line;
    vector<string> file;
    ifstream myfile("input.txt");
    while(getline(myfile, line)) {  
        if(countLines == 0)
            file = (split(line, ','));
        else break;
        countLines++;
    }
    myfile.close();
    return file;
}

vector<string> parseBoard() {
    int countLines = 0;
    string line, item;
    vector<string> board;

    ifstream myfile("input.txt");
    while(getline(myfile, line)) {
        if(countLines > 1 && line != "\n") {
            istringstream iss(line); 
            for(string line; iss >> line; ) 
            board.push_back(line);
        } 
        countLines++;
    }
    myfile.close();
    return board;
}

vector<string> split(const string &str, char delim) {
    vector<string> result;
    stringstream ss(str);
    string item;
    while(getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}