class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] countnum = new int[1000];
        for(int x: nums){
            ++countnum[x];
        }
        int ans = 0, mx = -1;
        for(int x: countnum){
            if(mx<x){
                mx=x;
                ans = x;}
             else if (mx == x){
                ans+=x;
            }
        }
        return ans;
    }
}
//Complexity O(n)