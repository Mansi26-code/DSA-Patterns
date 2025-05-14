//Check whether a given integer n is an Armstrong number.
//A number is Armstrong if the sum of each of its digits raised to the power of the number of digits equals the number itself.

#include <cmath> // For using pow()

class Solution {
public:
    bool isArmstrong(int N) {
        int temp = N;
        int k = to_string(N).size();  // Count number of digits (k)
        int sum = 0;

        // Calculate the sum of each digit raised to the power k
        while (temp > 0) {
            int digit = temp % 10;        // Extract the last digit
            sum += pow(digit, k);         // Add digit^k to sum
            temp /= 10;                   // Remove the last digit
        }

        // Return true if the sum equals the original number
        return sum == N;
    }
};
⏱ Time Complexity:
O(k) where k is the number of digits in n.
(pow() is O(1) for small integers, so each digit is processed once.)

📦 Space Complexity:
O(1) – Uses constant extra space.