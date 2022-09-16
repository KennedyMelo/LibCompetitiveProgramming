class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), inf = 1e9, j;
        vector<int>dp(n+1, inf);
        dp[0] = -inf;
        int tam =0;
        for(int i=0; i<n; i++){
            j = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if(dp[j-1] < nums[i] && nums[i] < dp[j]){
                dp[j] = nums[i];
                tam = max(tam, j);
            }
        }
        return tam;
    }
};