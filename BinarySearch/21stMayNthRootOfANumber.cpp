class Solution {
    public:
     int NthRoot(int N, int M) {
         int s = 0, e = M;
         while (s <= e) {
             int mid = s + (e - s) / 2;
             if (pow(mid, N) == M) {
                 return mid;
             } else if (pow(mid, N) < M) {
                 s = mid + 1;
             } else {
                 e = mid - 1;
             }
         }
         return -1;
     }
 };
 