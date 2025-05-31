class Solution {
public:
    // Function to print numbers from n to 1 using recursion
    void printNumbers(int n) {
        // 🛑 Base case: if n becomes 0, stop the recursion
        if (n == 0)
            return;

        // 🔢 Print the current number
        cout << n << endl;

        // 🔁 Recursive call with n - 1
        printNumbers(n - 1);
    }
};
