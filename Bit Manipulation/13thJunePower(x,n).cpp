class Solution {
public:
    double myPow(double x, int n) {
        long long num=n;
     double ans=1.0;
     if(num<0)
     {
        num=-1*num;
     }
     while(num>0)
     {
        if(num%2==1)
        {
            ans=ans*x;
            num--;
        }
        else
        {
            x*=x;
            num/=2;
        }
     }
     if(n<0)
     {
        ans=(double)(1.0)/(double)(ans);
     }
     return ans;
    }
};



Time Complexity:The time complexity is O(log n) due to the halving of 'num' in each iteration of the while loop.
Space Complexity:The space complexity is O(1) because the algorithm uses a constant amount of extra space.