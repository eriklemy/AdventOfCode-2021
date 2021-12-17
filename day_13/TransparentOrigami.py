def parseValues() -> tuple:
    folds, points =  list(), list()
    with open("day_13/input.txt") as file:
        data = file.read().strip().split('\n')
        for line in data:
            if line.startswith('fold'):
                s, i = line[11:].split('=')
                folds.append((s, int(i)))
            elif line != '':
                x, y = line.split(',')
                points.append((int(x), int(y)))
    return folds, points

def showBoard(points: list) -> None:
    row = max([x[0] for x in points]) + 1
    col = max([y[1] for y in points]) + 1
    for y in range(col):
        for x in range(row):
            if (x, y) in points:
                print('#', end = '')
            else:
                print(' ', end = '')
        print()

def foldPaper(points: int, folds: str) -> list:
    for i in range(len(points)):
        if (folds[0] == 'y') and (points[i][1] > folds[1]):
            # points[i] = (points[i][0], points[i][1] - 2 * (points[i][1] - folds[1]))
            points[i] = (points[i][0], 2 * folds[1] - points[i][1])
        elif (folds[0] == 'x') and (points[i][0] > folds[1]):
            points[i] = (2 * folds[1] - points[i][0], points[i][1])
    return list(set(points))

def main() -> None:
    folds, points = parseValues()
    for i in range(len(folds)):
        if i == 1:
            print(f'Result <PartOne>: {len(points)}')
        points = foldPaper(points, folds[i])

    print('Result <PartTwo>: ')
    showBoard(points)

if __name__ == '__main__':
    main()

