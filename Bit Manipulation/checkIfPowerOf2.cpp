class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A number is a power of two if:
        // 1. It is positive.
        // 2. It has only one set bit in binary form.
        //    => (n & (n-1)) will be 0 only for powers of 2
        return (n > 0 && (n & (n - 1)) == 0);
    }
};


//SC & TC=O(1)