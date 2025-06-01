#include <iostream>
using namespace std;

// Recursive function to print the string in reverse
void solve(string s, int idx) {
    // 🛑 Base case: if index reaches end of string, return
    if (idx == s.length())
        return;

    // 🔁 Recursive call to next index
    solve(s, idx + 1);

    // ⬅️ Print character after recursion returns (reverse order)
    cout << s[idx];
}

int main() {
    string s = "hello";
    cout << "Reversed string: ";
    solve(s, 0);
    cout << endl;
    return 0;
}


⏱ Time Complexity (TC): O(n)
➡️ One recursive call per character.

🧠 Space Complexity (SC): O(n)
➡️ Due to the recursive call stack, where n is the length of the string.