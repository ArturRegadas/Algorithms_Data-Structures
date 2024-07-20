data= input("[quantidade de vertices] [quantidade de arestas] [inicio] [fim]").split(' ')
graph={}
def dijktra(graph, start, end):
    queue=[start]
    processed=[]
    steps={}
    price={start:0}
    passed=[]
    while queue != []:
        
        neighbors={}
        neigh=0
        current=queue[0]
        for i in graph[current]:
            if not i in processed:
                queue.append(i)
            try:
                if price[current]+graph[current][i]<price[i]:
                    price[i]=price[current]+graph[current][i]

            except:
                price[i]=price[current]+graph[current][i]
            neigh+=1
        neighbors[current]=neigh
        if not current in steps:
            steps[current]=0
        steps[current]+=1
        print(queue)
        
        choice=True
        for i in graph[end]:
            if not i in processed:
                choice=False
        if choice:
            return price[end]
            
        if len(graph[current]) == steps[current]:
            processed.append(current)
        queue.pop(0)
        print(price)
        passed.append(current)

    return price

for i in range(int(data[1])):
    edge=input().split(' ')
    if not edge[0] in graph:
        graph[edge[0]]={}

    graph[edge[0]][edge[1]]=int(edge[2])
    if not edge[1] in graph:
        graph[edge[1]]={}
    graph[edge[1]][edge[0]]=int(edge[2])
print(dijktra(graph, data[2], data[3]))
