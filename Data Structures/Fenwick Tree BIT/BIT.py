class BIT:
    def __init__(self, size: int) -> None:
        self.size = size
        self.tree = [0] * (size+1)
    
    def _lsb(n: int) -> int:
        return n&(-n)

    #indexado em 1
    def incrementUpdate(self, idx: int, delta: int) -> None:
        while(idx <= self.size):
            self.tree[idx]+=delta
            idx += self.lsb(idx)
        
    def querrys(self, idx: int) -> int:
        ans = 0
        while(idx > 0):
            ans += self.tree[idx]
            idx -= self._lsb(idx)
        return ans