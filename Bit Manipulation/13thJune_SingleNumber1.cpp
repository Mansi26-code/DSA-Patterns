class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        //your code goes here
        int xorr=0;
        for(int i=0;i<nums.size();i++)
        {
            xorr=xorr^nums[i];
        }
        return xorr;
    }
};

//TC=O(n)  & SC=O(1)