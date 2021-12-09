from itertools import permutations  

# 1 : size -> 2
# 4 : size -> 4
# 7 : size -> 3
# 8 : size -> 7
def partOne(data: list[str]) -> int:
    sizeNumbers = [2, 4, 3, 7]
    count = 0
    for line in data:
        for value in line:
            if len(value) in sizeNumbers:
                count += 1
    return count

def perm(value: str) -> int:
    aux = []
    for i in permutations(value, len(value)):
        aux.append(''.join(sorted(i)))
    print(aux)
    #5             6       2      5        5       4        5        6        3        6         5
    numbers = ['abcdeg', 'cf', 'acdfg', 'abcdf', 'bcdf', 'bcdef', 'bcdefg', 'acf', 'abcdefg', 'abcdef']
    for i in range(len(numbers)):
        if value in numbers[i]:
            if 'acf' and not 'g' in numbers[i]:
                print(3)
                return 3
            if 'cfg' in numbers[i]:
                print(6)
                return 6
            if 'acfg' in numbers[i]:
                print(2)
                return 2
            else:
                return 9
    return -1

def main() -> None:
    with open("day_8/input.txt") as file:
        initial_data = file.read().strip().split('\n')
        data = [line[line.index("|") + 2:].split(" ") for line in initial_data]
    
    segments = []
    for line in data:
        segment = []
        for value in line:
            segment.append(''.join(sorted(value)))
        segments.append(segment)

    lines = []
    for line in segments:
        count = []
        print(line)
        for value in line:
            if len(value) == 2:              
                count.append(1)
            elif len(value) == 4:              
                count.append(4)
            elif len(value) == 3:              
                count.append(7)
            elif len(value) == 7:            
                count.append(8)
            elif(perm(value)) != -1:
                count.append(perm(value))
        lines.append(count)
    print(lines)

    # print(f'Result <PartOne>: {partOne(data)}')


if __name__ == '__main__':
    main()


