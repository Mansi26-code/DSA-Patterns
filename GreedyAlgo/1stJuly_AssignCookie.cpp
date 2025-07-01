#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie) {
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        int m = Student.size();
        int n = Cookie.size();
        int totalStudents = 0;

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (Cookie[j] >= Student[i]) {
                totalStudents++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return totalStudents;
    }
};


Time Complexity:O(m log m + n log n + min(m, n))

Space Complexity:O(1).