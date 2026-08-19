class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> mp;

        // Store reserved seats using bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            mp[row] |= (1 << s);
        }

        // Initially every row can accommodate 2 groups
        int ans = 2 * n;

        // Check only rows having reservations
        for (auto &[row, mask] : mp) {

            int groups = 0;

            // 2,3,4,5
            if ((mask & ((1 << 2) | (1 << 3) | 
                        (1 << 4) | (1 << 5))) == 0) {
                groups++;
            }

            // 6,7,8,9
            if ((mask & ((1 << 6) | (1 << 7) | 
                        (1 << 8) | (1 << 9))) == 0) {
                groups++;
            }

            // If neither side works, try middle: 4,5,6,7
            if (groups == 0) {
                if ((mask & ((1 << 4) | (1 << 5) |
                            (1 << 6) | (1 << 7))) == 0) {
                    groups = 1;
                }
            }

            // This row was counted as 2 initially
            ans -= 2;
            ans += groups;
        }

        return ans;
    }
};