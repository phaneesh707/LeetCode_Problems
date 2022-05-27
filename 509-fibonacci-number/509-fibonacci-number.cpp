class Solution {
public:

    int fib(int n) {
        if(n<2)
            return n;
        else{
            vector<int> fibo;
            fibo.push_back(0);
            fibo.push_back(1);
            for(int i=2;i<=n;i++){
                fibo.push_back(fibo[i-1]+fibo[i-2]);
            }
            return fibo[n];
        }
    }
};