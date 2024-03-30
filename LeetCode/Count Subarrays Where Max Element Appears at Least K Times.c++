class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long answer = 0;
        int countMax = 0;
        int j=0;
        for(int i = 0; i < n; ++i){
            while(j < n && countMax < k){
                countMax += nums[j] == maxVal;
                ++j;
            }
            if(countMax < k) break;
            answer += n-j+1;
            countMax -= nums[i]==maxVal;
        }
        return answer;
    }
};