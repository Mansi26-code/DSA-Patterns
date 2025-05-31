class Solution {
public:
    // 🔁 Recursive function to print numbers from n to 1
    void printNumbers(int n) {
        // 🛑 Base case: if n becomes 0, stop recursion
        if (n == 0)
            return;

        // 🔢 Print current number
        cout << n << endl;

        // 🔁 Recursive call to print next number
        printNumbers(n - 1); // ✅ Fixed typo here
    }
};
