class Solution {
public:
    int countPrimes(int n) {
        vector<int>isPrime(n+1, true);
        for(int p=2;p*p<=n;p++)
        {
            if(isPrime[p]==true)
            {
                for(int i=2*p;i<=n;i+=p)
                {
                    isPrime[i]=false;
                }
            }
        }
int count=0;
        for(int p=2;p<n;p++)
        {
            if(isPrime[p]==true)
            count++;
        }
        return count;
    }
};

//tc=O(NLogLogN)
