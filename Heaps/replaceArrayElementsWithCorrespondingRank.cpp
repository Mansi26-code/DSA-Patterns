// C++ program to replace each element of
// Array with it's corresponding rank
#include <bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr){
    int n = arr.size();
    vector<int> res(n);
    
    // Create min heap of pairs (element, index)
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
    greater<pair<int,int>>> pq();
    
    // Push elements with their indices
    for(int i = 0; i < n; i++) {
        pq.push({arr[i], i});
    }
    
    int rank = 0;
    int lastNum = INT_MAX;
    
    // Process elements in sorted order
    while(!pq.empty()) {
        int curr = pq.top().first;
        int index = pq.top().second;
        pq.pop();
        
        // Increment rank only for new numbers
        if(lastNum == INT_MAX || curr != lastNum) {
            rank++;
        }
        
        // Assign rank to original position
        res[index] = rank;
        lastNum = curr;
    }
    
    return res;
}


TC= O(n* log n)