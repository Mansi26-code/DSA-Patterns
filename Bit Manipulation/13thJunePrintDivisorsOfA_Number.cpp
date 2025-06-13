Time Complexity:O(sqrt(n) + klogk), where k is the number of divisors and can be at most n. The sqrt(n) comes from the loop, and klogk from sorting.
Space Complexity:O(k), where k is the number of divisors which is stored in the vector 'ans'.


class Solution {
public:
    vector<int> divisors(int n) {
        vector<int>ans;
        int sqrtN=sqrt(n);
        for(int i=1;i<=sqrtN;i++)
        {
            if(n%i==0)
            {
                ans.push_back(i);
                if(i!=n/i)
                {
                    ans.push_back(n/i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//optimal approach

//sc & tc=O(n)

class Solution {
public:
    /* Function to find all 
    divisors of n */
    vector<int> divisors(int n) {
        
        // To store the divisors;
        vector<int> ans;
        
        // Iterate from 1 to n
        for(int i=1; i <= n; i++) {
            
            // If a divisor is found
            if(n % i == 0) {
                //Add it to the answer
                ans.push_back(i);
            }
        }
        
        // Return the result
        return ans;
    }
};