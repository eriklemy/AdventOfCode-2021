import statistics

def partOne(data: list) -> int:
    median = round(statistics.median(data))
    return sum(abs(value - median) for value in data)
    # fuel = []
    # for value in data:
    #     fuel.append(abs(value - median))
    # return sum(fuel)

def partTwo(data: list) -> int:
    minFuel = 1e9
    for num in range(max(data)):
        fuel = 0
        for value in data:
            dist = abs(num - value)
            fuel += dist*(dist + 1) // 2 # gauss n * (n + 1) / 2
        if(fuel < minFuel):
            minFuel = fuel
    return minFuel

def main() -> None:
    with open('day_7/input.txt') as file:
        data = [int(x) for x in file.readline().split(',')]
    print(f'Result <PartOne>: {partOne(data)}')
    print(f'Result <PartTwo>: {partTwo(data)}')

if __name__ == '__main__':
    main()   
