def parseFile() -> tuple:
    with open("day_4/input.txt") as file:
        sortedNumbers = [int(x) for x in file.readline().strip('\n').split(',')]
        boards = []
        while file.readline():
            board = []
            for i in range(5):
                board.extend([int(x) for x in file.readline().strip('\n').split()])
            boards.append(board)
    return sortedNumbers, boards

def checkWin(board: list) -> bool:
    linePos = colPos = 0
    for i in range(5):
        lineWon = (board[linePos] == board[linePos + 1] == board[linePos + 2] == board[linePos + 3] == board[linePos + 4])
        colWon = (board[colPos] == board[colPos + 5] == board[colPos + 10] == board[colPos + 15] == board[colPos + 20])
        if lineWon or colWon:
            return True
        linePos += 5
        colPos += 1
    return False

def repeatedCode(sortedNumbers: list, boards: list) -> tuple:
    number = sortedNumbers[0]
    sortedNumbers = sortedNumbers[1:]
    for board in boards:
        for i in range(len(board)):
            if board[i] == number:
                board[i] = True
    return sortedNumbers, number

def giantSquidPartOne(sortedNumbers: list, boards: list) -> None:
    found = False
    while not found:
        sortedNumbers, number = repeatedCode(sortedNumbers, boards)
        for board in boards:
            if checkWin(board):
                total = sum([x for x in board if x != 1])
                print("result <PartOne>: ", total * number)
                found = True

def giantSquidPartTwo(sortedNumbers: list, boards: list) -> tuple:
    found = False
    while not found:
        sortedNumbers, number = repeatedCode(sortedNumbers, boards)
        count = 0
        while count < len(boards):
            if checkWin(boards[count]):
                if len(boards) > 1:
                    boards.pop(count)
                else:
                    found = True
                    break
            else:
                count += 1
    return count, number


def main() -> None:
    sortedNumbers, boards = parseFile()
    giantSquidPartOne(sortedNumbers, boards)
    count, number = giantSquidPartTwo(sortedNumbers, boards)
    total = sum([x for x in boards[count] if x != 1])
    print("result <PartTwo>: ", total * number)

if __name__ == "__main__":
    main()