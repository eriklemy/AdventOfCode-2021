import string
from collections import defaultdict, Counter

insertions = {}
with open("day_14/input.txt") as file:
    data, pairs = file.read().split('\n\n')
    for line in pairs.splitlines():
        left, right = line.split(' -> ')
        insertions[left] = right

def pairInsertion(steps: int, polymer: defaultdict, total: dict) -> dict:
    for step in range(steps):
        temp = polymer.copy()
        for a in (b for (b, c) in polymer.items() if c > 0):
            t1 = a[:1] + insertions[a]
            t2 = insertions[a] + a[1:]
            temp[t1] += polymer[a]
            temp[t2] += polymer[a]
            temp[a] -= polymer[a]
            total[insertions[a]] += polymer[a]
        polymer = temp.copy()
    return total

def main() -> None:
    polymer = defaultdict(int)
    total = dict.fromkeys(string.ascii_uppercase, 0)
    total[data[-1]] += 1
    for i in range(len(data) - 1):
        total[data[i]] += 1
        polymer[data[i:i + 2]] += 1

    countPartOne = countPartTwo = Counter()
   
    countPartOne += Counter(pairInsertion(10, polymer, total))
    print(f'Result <PartOne>: {max(countPartOne.values()) - min(countPartOne.values())}')
    
    countPartTwo += Counter(pairInsertion(40, polymer, total))
    print(f'Result <PartTwo>: {max(countPartTwo.values()) - min(countPartTwo.values())}')

if __name__ == '__main__':
    main()
