class Solution {
    public int findDuplicate(int[] nums) {
        //first index initialization with the slow pointer
        //same for the fast
        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];  //one step
            fast = nums[nums[fast]]; // move two step
        }

        while(slow != fast);  //initilize slow2
        int slow2 = 0;

        do{
            slow = nums[slow];
            slow2 = nums[slow2];     
        }
        while(slow != slow2);
        return slow2;
    }
}