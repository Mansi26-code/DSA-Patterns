//similar question as "Koko eats banana "
//Brute force 
int repairCarsBrute(vector<int>& ranks, int cars) {
    long long maxTime = *min_element(ranks.begin(), ranks.end()) * (long long)cars * cars;

    for (long long t = 1; t <= maxTime; t++) {
        long long total = 0;
        for (int r : ranks) {
            total += (long long)(sqrt((double)t / r));
        }
        if (total >= cars) return t;
    }

    return -1;
}


//Optimal approach
class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            // Minimum possible time = 1
            long long s = 1;
    
            // Maximum possible time:
            // In worst case, best mechanic (with smallest rank) repairs all cars
            // Time = rank * cars^2
            long long e = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
    
            long long ans = -1;
    
            // Binary search on time
            while (s <= e) {
                long long mid = s + (e - s) / 2;
    
                long long totCars = 0;
    
                // Calculate how many cars can be repaired in `mid` time
                for (int i = 0; i < ranks.size(); i++) {
                    // For mechanic i, max cars they can repair in `mid` time is:
                    // time >= rank * cars^2  =>  cars <= sqrt(time / rank)
                    totCars += (long long)(sqrt((double)mid / ranks[i]));
                }
    
                // If we can repair required or more cars in `mid` time
                if (totCars >= cars) {
                    ans = mid;         // this is a possible answer
                    e = mid - 1;       // try to find smaller time
                } else {
                    s = mid + 1;       // need more time
                }
            }
    
            return ans;
        }
    