//brute force
//TC=O(n)
//SC=O(1)

class Solution {
public:

    /* Function to find the XOR 
    of numbers from L to R*/
    int findRangeXOR(int l, int r){			
        
        // To store the XOR of numbers
		int ans = 0;
		
		// XOR all the numbers
		for(int i=l; i <= r; i++) {
		    ans ^= i;
		}
		
		// Return the result
		return ans;
	}
};


//Optimal

//TC & SC=O(1)

class Solution{	
	public:

    int xorring(int n)
    {
         if(n%4==0)
            return n;

            else if(n%4==1)
            return 1;

            else if(n%4==2)
            return n+1;

            else
            return 0;
    }
		int findRangeXOR(int l,int r){
			//your code goes here
return xorring(r)^xorring(l-1);
           



		}
};