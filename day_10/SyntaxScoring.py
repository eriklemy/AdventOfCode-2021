SYNTAXCHECK = {'(': ')', '[': ']', '{': '}', '<': '>'}
SYNTAXOPEN = {'(': 1, '[': 2, '{': 3, '<': 4} # autocomplete {')': 1, ']': 2, '}': 3, '>': 4}
SYNTAXCLOSE = {')': 3, ']': 57, '}': 1197, '>': 25137}

def points(value: str) -> int:
    return SYNTAXCLOSE[value]
    
def checkSyntaxPartOneTwo(data: list) -> tuple:
    errorScore = 0
    autocomplete = []
    for line in data:
        stack, corrupted = [], False
        for value in line:
            if value in SYNTAXCHECK:
                stack.append(value)
            else:
                if value not in SYNTAXCHECK:
                    top = stack.pop() # top = stack[-1] also works
                    if SYNTAXCHECK[top] != value:
                        errorScore += points(value)
                        corrupted = True
                        break
        if not corrupted:  
            errorsScore = 0
            while stack:
                errorsScore *= 5
                errorsScore += SYNTAXOPEN[stack.pop()]
            autocomplete.append(errorsScore)

    autocomplete.sort()
    middleScore = autocomplete[len(autocomplete)//2]
    return errorScore, middleScore

def main() -> None:
    with open("day_10/input.txt") as file:
        data = [[value for value in list(line)] for line in file.read().strip().split('\n')]

    part_1, part_2 = checkSyntaxPartOneTwo(data)
    print(f'Result <PartOne>: {part_1}')
    print(f'Result <PartTwo>: {part_2}')

if __name__ == '__main__' :
    main()