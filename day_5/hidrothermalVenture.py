from typing import Any
from collections import defaultdict

overlap_1 = defaultdict(int)
overlap_2 = defaultdict(int)

def solvePartOneTwo(x1: int, y1: int, dx: int, dy: int) -> None:
    for i in range(1 + max(abs(dx), abs(dy))):
        x = x1 + (1 if dx > 0 else (-1 if dx < 0 else 0)) * i
        y = y1 + (1 if dy > 0 else (-1 if dy < 0 else 0)) * i
        if dx == 0 or dy == 0:
            overlap_1[(x, y)] += 1
        overlap_2[(x, y)] += 1

def parseFileLine(line: Any) -> None:
    x1, y1, _, x2, y2 = line.replace(',', ' ').split()
    x1, x2 = int(x1), int(x2)
    y1, y2 = int(y1), int(y2)

    dx, dy = x2 - x1, y2 - y1
    solvePartOneTwo(x1, y1, dx, dy)

def partOne() -> int:
    print("Result <PartOne>: ", len([i for i in overlap_1 if overlap_1[i] > 1]))

def partTwo() -> int:
    print("Result <PartTwo>: ", len([i for i in overlap_2 if overlap_2[i] > 1]))

def main() -> None:
    for line in open("day_5/input.txt"):
        parseFileLine(line)
    partOne()
    partTwo()

if __name__ == "__main__":
    main()