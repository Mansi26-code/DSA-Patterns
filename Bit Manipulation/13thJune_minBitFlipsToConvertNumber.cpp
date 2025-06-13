class Solution {
   public:
    int minBitsFlip(int start, int goal) {
        // Your code goes here
        // pehle to dono ka xorr nikalo so that we can get that total  how many
        // bits are different between these two
        int xorr = start ^ goal;
        // now count the number of set bits in the xorr
        int count = 0;
        while (xorr > 0) {
            count += (xorr & 1);
            xorr >>= 1;
        }
        return count;
    }
};

//Time Complexity:The time complexity is O(log(n)) because the while loop iterates based on the number of bits in the XOR result.
//Space Complexity:The space complexity is O(1) as it uses a constant amount of extra space.
