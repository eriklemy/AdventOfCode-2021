#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> parseSortedNumbers();
vector<string> parseBoard();
vector<string> split(const string& str, char delim);
bool checkWin(vector<string> sortedNumbers, int board[5][5]);
void showBoard(int board[5][5]);

int main() {
    vector<string> sortedNumbers = parseSortedNumbers();
    vector<string> bingoBoard = parseBoard();
    
    cout << "\nboard: " << endl;

    int pos = 0;
    for(size_t i = 0; i < bingoBoard.size()/25; i++) {
        int board[5][5];
        for(size_t line = 0; line < 5; line++) {
            for(size_t column = 0; column < 5; column++) {
                board[line][column] = stoi(bingoBoard[pos]);
                pos++;
            }
        }  
        if(checkWin(sortedNumbers, board)) break;
        else cout << "nenhum vencedor!!" << endl;
    }
    for(auto i: sortedNumbers) cout << i << " ";
}

void showBoard(int board[5][5]) {
    for(size_t line = 0; line < 5; line++) {
        for(size_t column = 0; column < 5; column++)
            cout << board[line][column] << " ";
        cout << endl;
    } 
}

bool checkWin(vector<string> sortedNumbers, int board[5][5]) {
    int countLine, countColumn;
    bool ok = false;
    for(size_t i = 0; i < 5; i++) {
        countLine = 0; countColumn = 0;
        for(size_t j = 0; j < 5; j++) {
            for(auto number: sortedNumbers) {
                if(board[i][j] == stoi(number)) {
                    cout << board[i][j] << ": " << stoi(number) << " " << endl;
                    countLine++;
                }
                if(board[j][i] == stoi(number)) {
                    countColumn++;  
                }
            }
        }
        cout << endl;
        cout << countLine << ": " << countColumn << endl;
        if(countLine == 5 || countColumn == 5) {
            showBoard(board);
            cout << "vencedor encontrado" << endl;
            return true;
        }
    }
    return false;
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