class Solution {
    public:
     long long floorSqrt(long long n) {
         long long s = 0, e = n;
         if (n == 1) return 1;
         long long ans = 0;
         while (s < e) {
             long long mid = s + (e - s) / 2;
 
             if (mid * mid <= n) {
                 ans = mid;
                 s = mid + 1;
             } else {
                 e = mid;
             }
         }
         return ans;
     }
 };