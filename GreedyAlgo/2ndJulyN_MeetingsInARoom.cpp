class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        vector<pair<int,int>>meetings;
        for(int i=0;i<start.size();i++)
        {
            meetings.push_back({start[i],end[i]});
        }

        //[{1,2},{3,4},{0,6}....]

      sort(meetings.begin(), meetings.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.second < b.second;
             });

   
      int possibleMeets=1;
      int lastEnd=meetings[0].second;
      for(int i=1;i<meetings.size();i++)
      {
        int start=meetings[i].first;
       

        if(lastEnd<start)
        {
            possibleMeets++;
            lastEnd=meetings[i].second;
        }
      }
      return possibleMeets;


    }
};

//Time Complexity:O(n) to create the vector of pairs + O(n log n) for sorting + O(n) to iterate through the sorted vector, resulting in O(n log n).
//Space Complexity:O(n) to store the vector of pairs.