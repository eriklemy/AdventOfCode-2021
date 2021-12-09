ADJACENTS = [(0, 1), (0, -1), (-1, 0), (1, 0)]

def available(r:int, c:int, data:list) -> bool:
    # return 0 <= r and r < len(data) and 0 <= c and c < len(data[0])
    return (0 <= r < len(data)) and (0 <= c < len(data[0]))

def partOne(data: list) -> tuple:   
    count = 0
    lowestCoords = []
    for row in range(len(data)):
        for col in range(len(data[0])):
            low = True
            for adj in ADJACENTS:
                r = row + adj[0]
                c = col + adj[1]

                if not available(r, c, data):
                    continue

                if data[r][c] <= data[row][col]:
                    low = False
                    break
            if low:
                lowestCoords.append((row, col))
                count += data[row][col] + 1

    return count, lowestCoords

def partTwo(data: list) -> int:
    size = []
    _, lowPoints = partOne(data)
    # depth first 
    for row, col in lowPoints: 
        sizeBasin = 0
        basin = [(row, col)]
        visited = set()
        while len(basin) > 0:
            row, col = basin.pop()
            if (row, col) in visited:
                continue
            visited.add((row, col))
            sizeBasin += 1
            for adj in ADJACENTS:
                r = row + adj[0]
                c = col + adj[1]

                if not available(r, c, data) or data[r][c] == 9:
                    continue

                basin.append((r, c))
        size.append(sizeBasin)
    sortedSizes = sorted(size, reverse=True)
    return sortedSizes[0] * sortedSizes[1] * sortedSizes[2] 

def main() -> None:
    with open("day_9/input.txt") as file:
        data = [[int(value) for value in list(line)] for line in file.read().strip().split('\n')]
    result, _ = partOne(data)

    print(f'Result <PartOne>: {result}')
    print(f'Result <PartTwo>: {partTwo(data)}')

if __name__ == '__main__':
    main()