class Solution{  
  public:  
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here
        sort(Jobs.begin(),Jobs.end(),[](vector<int>&a, vector<int>&b){
          return a[2]>b[2];
        });

        int maxDeadline=-1;
        for(int i=0;i<Jobs.size();i++)
        {
          maxDeadline=max(maxDeadline,Jobs[i][1]);
        }
int n=Jobs.size();
int time=0;
int jobs=0;
int totalProfit=0;
        vector<int>slots(maxDeadline,-1);
        for(int i=0;i<n;i++)
        {
          int jobId=Jobs[i][0];
          int deadline=Jobs[i][1];
          int profit=Jobs[i][2];

          for(int slot=deadline-1;slot>=0;slot--)
          {
            if(slots[slot]==-1)
            {
               slots[slot]=jobId;
              
               jobs++;
               totalProfit+=profit;
               break;


            }
          }
        }
        return {jobs,totalProfit};

    } 
};

//Time Complexity:O(n log n + n*maxDeadline)
//Space Complexity:O(maxDeadline)
