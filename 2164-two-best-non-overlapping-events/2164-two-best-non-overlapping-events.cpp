class Solution {
public:
    int binarySearch(vector<vector<int>>& events, int endTime) {
        int low = 0;
        int high = events.size() - 1;
        int res = events.size();

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(events[mid][0] > endTime) {
                res = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return res;
    }

    int solve(vector<vector<int>>& events, int idx, int eventAttended, vector<vector<int>>& dp) {
        if(eventAttended == 2 || idx >= events.size()) {
            return 0;
        }

        if(dp[idx][eventAttended] != -1) {
            return dp[idx][eventAttended];
        }

        int nextValidEventIdx = binarySearch(events, events[idx][1]);

        int attended = events[idx][2] + solve(events, nextValidEventIdx, eventAttended + 1, dp);
        int not_attended = solve(events, idx + 1, eventAttended, dp);

        return dp[idx][eventAttended] = max(attended, not_attended);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        vector<vector<int>> dp(events.size(), vector<int>(2, -1));

        return solve(events, 0, 0, dp);
    }
};
