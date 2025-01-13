def getMin(queue:list, processed:dict, prices:dict) -> int:
    minus = float('inf')
    index = -1
    for i in queue:
        if prices[i]<minus and not processed[i]:
            minus = prices[i]
            index = i
    return index

def getPath(parents:dict, init:str, current:str) -> list:
    path = []
    while current != init:
        path.append(current)
        current = parents[current]
    path.append(init)
    return reversed(path)


def dijkstra(graph:dict, init:str, end:str) -> list:
    prices = {str(i):float('inf') for i in graph}
    processed = {str(i):False for i in graph}
    
    prices[init] = 0
    parents = {}

    queue = [init]
    for g in range(len(graph)):
        current = getMin(queue, processed, prices)
        if current == -1:
            break
        if current == end:
            return getPath(parents, init, end)
        processed[current] = True

        for i in graph[current]:
            queue.append(i)
            if prices[current]+graph[current][i] < prices[i]:
                prices[i] = prices[current]+graph[current][i]
                parents[i] = current

    return ['-1']


            

    
def main() -> None:
    vertices, edges = list(map(int, input().split()))
    graph = {str(i):{} for i in range(1, vertices+1)}
    for i in range(edges):
        edg1, edg2, wgh = input().split()
        wgh = int(wgh)
        graph[edg1][edg2] = wgh
        graph[edg2][edg1] = wgh
    path=dijkstra(graph, '1', str(vertices))
    print(' '.join(path))

if "__main__" == __name__:
    main()