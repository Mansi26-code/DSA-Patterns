class Solution {
    public:
        int guessNumber(int n) {
            int s = 1, e = n;
    
            while (s <= e) {
                int mid = s + (e - s) / 2;   // Avoids overflow
                int g = guess(mid);         // Call the provided API
                if (g == 0)
                    return mid;             // Correct guess
                else if (g == 1)
                    s = mid + 1;            // Guess is too low
                else
                    e = mid - 1;            // Guess is too high
            }
            return -1;  // Just in case, although this line is never actually reached
        }
    };
    