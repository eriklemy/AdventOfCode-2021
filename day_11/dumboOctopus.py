def Neighbors(row: int, col: int, data: list) -> tuple:
    adjacents = []
    for i in range(row - 1, row + 2):
        for j in range(col - 1, col + 2):    
            if i == row and j == col or i < 0 or i >= len(data) or j < 0 or j >= len(data[0]):
                continue
            adjacents.append((i, j))
    return adjacents

def flash(i: int, j: int, flashed: dict, data: list):
    flashed[(i, j)] = True
    neighbors = Neighbors(i, j, data)
    for x, y in neighbors:
        data[x][y] += 1
    for x, y in neighbors:
        if data[x][y] > 9 and (x,y) not in flashed:
            flashed[(x,y)] = True
            flash(x, y, flashed, data)
        
def partOneTwo(data: list, partOne: bool) -> int:
    numFlashes = step =  0
    while True:
        flashed = {}
        for row in range(len(data)):
            for col in range(len(data[0])):
                data[row][col] += 1
                if data[row][col] > 9 and (row, col) not in flashed:
                    flash(row, col, flashed, data)

        for row in range(len(data)):
            for col in range(len(data[0])):
                if data[row][col] > 9:
                    data[row][col] = 0
    
        step += 1
        numFlashes += len(flashed)

        if step == 100 and partOne:
            return numFlashes

        if len(data) * len(data[0]) == len(flashed):
            break
    return step

def main() -> None:
    with open("day_11/input.txt") as file:
        data = [[int(value) for value in list(line)] for line in file.read().strip().split('\n')]

    print(f'Result <PartOne>: {partOneTwo(data, True)}')
    # print(f'Result <PartTwo>: {partOneTwo(data, False)}')

if __name__ == '__main__':
    main()