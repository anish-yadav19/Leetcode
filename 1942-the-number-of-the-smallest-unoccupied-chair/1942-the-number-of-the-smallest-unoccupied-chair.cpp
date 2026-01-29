//Company Tags  		    : Uber, Facebook, Microsoft, Yelp, Google, Snapchat, Amazon, Cisco - Qn had small Variations
 
//Approach - 3 (min heap + set)
/*
    priority_queue(min heap) - To get the friend with minimum departure time
    ordered_set              - To get the least available chair
*/
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> p;
    priority_queue<p, vector<p>, greater<p>> pq;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        int targetArrivalTime = times[targetFriend][0];
        
        sort(begin(times), end(times));
        
        set<int> chairNum; //ordered set (we will get the least available chair number in the beginning) (You could also use min heap for this also)
        
        int lastChair = 0;
        
        for(vector<int> &time : times) {
            int arrival  = time[0];
            int depart   = time[1];
            int currSeat = -1;
 
            while(!pq.empty() && pq.top().first <= arrival) {
                chairNum.insert(pq.top().second); //insert the chairs which are being emptied
                pq.pop();
            }

            if(chairNum.empty()) {
                currSeat = lastChair;
                lastChair++;
            } else {
                currSeat = *(chairNum.begin());  //ordered set (we will get the least available chair number in the beginning)
                chairNum.erase(currSeat); //this chair is now occupied
            }
            pq.push({depart, currSeat});
            if(arrival == targetArrivalTime)
                return currSeat;
        }
        
        return -1;
    }
};

