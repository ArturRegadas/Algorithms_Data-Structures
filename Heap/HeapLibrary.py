import heapq as hp

data = [4, 10, 3, 5, 2] 
hp.heapify(data) #transforma em uma heap, complexidade O(n)
hp.heappush(data, 1) #adiciona a heap, complexidade O(log n)
minElement = hp.heappop(data) #retorna o menor elemento e tira ele da heap, complexidade O(log n)
print(f"menor elemento é {minElement}")
minElement = hp.heappushpop(data, 1) #adiciona primeiro e dps retorna o menor numero, complexidade O(log n)
print(f"menor elemento é {minElement}")
minElement = hp.heapreplace(data, 1) #adiciona primeiro e dps retorna o menor numero, complexidade O(log n)
print(f"menor elemento é {minElement}")#remove primeiro e dps adiciona o menor numero, complecidade O(log n)
k = 2
maiores = hp.nlargest(k, data) #retrona os K numeros maiores e NAO tira eles do heap, complexidade O(n log k)
menores = hp.nsmallest(k, data)#retrona os K numeros menores e NAO tira eles do heap, complexidade O(n log k)


print(data)