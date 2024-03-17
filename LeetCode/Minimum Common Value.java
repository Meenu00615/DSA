class Solution {
    public int getCommon(int[] num1, int[] num2){
        int p1 = 0, p2 = 0;
        int n1 = num1.length;
        int n2 = num2.length;
        while(p1<n1 && p2<n2){
            if(num1[p1]==num2[p2]) {
                return num1[p1];
            } else if(num1[p1]<num2[p2]) {
                p1++;
            } else {
                p2++;
            }
        }
        return -1;
    }
}