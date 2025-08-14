class UnionFind:
    def __init__(self, arr: list['int'] ):
        self.parents = {i : i for i in arr}#cada chave aponta para seu pai
        self.size = {arr[i] : 1 for i in arr}
    
    #retorna o pai
    def find(self, target: int) -> int:
        if(target == self.parents[target]):
            return target
        return self.find(self.parents[target])

    # retorna True se ocorreu a juncao
    def union(self, value1:int, value2:int) -> bool:
        parent_a = self.find(value1)
        parent_b = self.find(value2)

        if(parent_a == parent_b):
            return False # ja estao na maesma arvore
        
        if(self.size[parent_a] < self.size[parent_b]):
            self.parents[parent_a] = parent_b
            self.size[parent_b] += self.size[parent_a] # agora parent_b é pai de parent_a por conta da linha a cima
            return True
        
        self.parents[parent_b] = parent_a
        self.size[parent_a] += self.size[parent_b]
        return True