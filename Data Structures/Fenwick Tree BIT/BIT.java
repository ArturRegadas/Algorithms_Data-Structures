import java.util.*;

public class BIT{
    private int size;
    private List<Long> tree;

    public BIT(List<Long> arr){
        this.size = arr.size();
        this.tree = new ArrayList<>(arr);

        for(int i = 1; i<= size; i++){
            int j = i + lsb(i);//pai de i
            if(j <= size)
                tree.set(j, tree.get(j)+tree.get(i));
            
        }
    }

    private int lsb(int n){
        return n & -n;
    }

    private Long querry(int idx){
        Long ans = 0;
        while(idx>0){
            ans+= tree.get(idx);
            idx-=lsb(idx);
        }
        return ans;
    }

    // delta = arr[idx] - value
    public incrementUpdate(int idx, Long delta){
        while(idx <= size){
            tree.set(idx, tree.get(idx) + delta);
            idx += lsb(idx);
        }
    }

    public Long querryRange(int init, int end){
        return querry(end) - querry(init-1);
    }

}