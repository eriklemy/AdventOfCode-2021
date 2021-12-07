from collections import Counter

with open("day_6/input.txt") as file:
    initialState = [int(value) for value in file.readline().split(',')]

state = []
state.append([value -1 for value in initialState])

def solvePartOneTwo(days: int) -> int:
    ''' Works for both parts and it's better '''
    lanternfish =  Counter(initialState) # can use a defaultdict and sum values from initialState
    for day in range(days):
        lanternfish[(day + 7) % 9] += lanternfish[day % 9] # idea from a guy in megathread
        # new_fish = lanternfish[0]
        # lanternfish[0] = lanternfish[1]
        # lanternfish[1] = lanternfish[2]
        # lanternfish[2] = lanternfish[3]
        # lanternfish[3] = lanternfish[4]
        # lanternfish[4] = lanternfish[5]
        # lanternfish[5] = lanternfish[6]
        # lanternfish[6] = lanternfish[7]
        # lanternfish[7] = lanternfish[8]
        # lanternfish[6] += new_fish
        # lanternfish[8] = new_fish
    return sum(lanternfish.values())
    
def main() -> None:
    # print("Result <PartOne>: ", partOneBadSolution(80))
    print("Result <PartOne>: ", solvePartOneTwo(80))
    print("Result <PartTwo>: ", solvePartOneTwo(256))

def partOneBadSolution(days: int) -> int:
    ''' 
        That shit works and it's possible to visualize the generations, but it's still SLOW {AF} 
        DO NOT USE DAYS > 100
    '''
    for _ in range(1, days):
        for line in state:
            states = []
            for value in line:
                if value == 0:
                    states.append(8)
                    states.append(6)
                else:
                    states.append(value - 1)
        state.append(states)
    return len(state[-1])

if __name__ == "__main__":
    main()
