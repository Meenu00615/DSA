class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        int maxLength = 0;
        for(int start = 0, end = 0; end<nums.length;++end){
            frequencyMap.merge(nums[end], 1, Integer::sum);

            while(frequencyMap.get(nums[end])>k){
                frequencyMap.merge(nums[start], -1, Integer::sum);
                start++;
            }
            maxLength = Math.max(maxLength, end - start + 1);
        }
        return maxLength;
    }
}