
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();
        int ans = INT_MAX;

        // Case 1: Check increasing order going right from 0
        bool inc = true;

        for (int i = 0; i < n; i++) {
            int idx = (zero + i) % n;

            if (nums[idx] != i) {
                inc = false;
                break;
            }
        }

        if (inc) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        // Case 2: Check increasing order going left from 0
        bool dec = true;

        for (int i = 0; i < n; i++) {
            int idx = (zero - i + n) % n;

            if (nums[idx] != i) {
                dec = false;
                break;
            }
        }

        if (dec) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
