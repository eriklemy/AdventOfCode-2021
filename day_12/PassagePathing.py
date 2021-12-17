from collections import defaultdict

class Graph:
    def __init__(self):
        self._nodes: defaultdict[str, list] = defaultdict(list)

    def addEdge(self, node: str, neighbor: str) -> None:
        self._nodes[node].append(neighbor)
        self._nodes[neighbor].append(node)

    def getNeighbors(self, node: defaultdict[str, list]) -> list[str]:
        return self._nodes[node]

    def isSmallCave(self, node: list) -> bool:
        return node.islower()

    def depthFirstCountPartOne(self,
                               current: str,
                               start: str,
                               end: str,
                               visited: set) -> int:
        if current == end:
            return 1

        return sum(self.depthFirstCountPartOne(neighbor, start, end, visited | {neighbor}) 
                   for neighbor in self.getNeighbors(current)
                   if not self.isSmallCave(neighbor) or neighbor not in visited
               )

    def depthFirstCountPartTwo(self,
                               current: str,
                               start: str,
                               end: str,
                               visited: set,
                               canVisit: bool = True) -> int:
        count = 0
        if current == end:
            return 1
        
        for neighbor in self.getNeighbors(current):
            if not self.isSmallCave(neighbor) or neighbor not in visited:
                count += self.depthFirstCountPartTwo(neighbor, start, end, visited | {neighbor}, canVisit)
            elif canVisit and neighbor not in {start, end}:
                count += self.depthFirstCountPartTwo(neighbor, start, end, visited | {neighbor}, False)
        return count

    def findPathCount(self, start: str, end: str, partOne: bool) -> int:
        if partOne:
            return self.depthFirstCountPartOne(current = start, start = start, end = end, visited = {start})
        else:
            return self.depthFirstCountPartTwo(current = start, start = start, end = end, visited = {start})

def main() -> None:
    graph = Graph()
    for line in open("day_12/input.txt"):
        left, right = line.strip().split('-')
        graph.addEdge(left, right)

    print(f'Result <PartOne>: {graph.findPathCount("start", "end",True)}')
    print(f'Result <PartTwo>: {graph.findPathCount("start", "end", False)}')

if __name__ == "__main__":
    main()
