class Solution {
    public int firstMissingPositive(int[] nums) {
        int positiveNumber = 1;
        while(true){
            boolean exists = false;
            for(int i=0; i<nums.length; i++){
                if(nums[i]==positiveNumber){
                    exists = true;
                    break;
                }
            }
            //iterate through loop
            if(!exists) return positiveNumber;
            positiveNumber++;
        }
    }
}