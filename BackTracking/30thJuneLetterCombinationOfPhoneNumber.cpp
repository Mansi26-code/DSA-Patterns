
class Solution {
public:

void solve(int index,unordered_map<char,string>mp, string digits, vector<string>&ans, string &temp )

{
    if(index==digits.size())
    {
        ans.push_back(temp);
        return;
    }
  char digit=digits[index];
  string letters=mp[digit];

  for(char ch:letters)
  {
    temp.push_back(ch);
    solve(index+1,mp,digits,ans,temp);
    temp.pop_back();
  }

    
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>ans;
        string temp;

         if(digits.empty())
        return ans;
        solve(0,mp,digits,ans,temp);
        return ans;
    }
};