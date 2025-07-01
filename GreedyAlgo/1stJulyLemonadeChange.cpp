class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       
        int n=bills.size();
        int i=0;
        int countFives=0,countTens=0;
        while(i<n)
        {
          if(bills[i]==5)
          {
            countFives++;
           
          }
          else if(bills[i]==10)
          {
            if(countFives>0)
            {
                 countTens++;
                 countFives--;
               
            }
            else
            {
                return false;
            }
            
          }

          else if(bills[i]==20)
          {
           if(countTens>0 && countFives>0)
            {
                countTens--;
                countFives--;
               
            }
           else if(countFives>2)
            {
                countFives-=3;
              
               
            }
            
            else
            return false;
          }
          i++;
        }
        return true;
    }
};

//TC=O(n)
