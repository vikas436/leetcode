// 96. Unique Binary Search Trees
class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        long long res = 1;
        long long fact = 1;
        for(int i=1;i<=n;i++) {
            res*=(i+n);
            res = res/i;
        }
        fact = (n+1);
        res = res/fact;
        return res;
    }
};
