class Solution {
    public int lengthOfLastWord(String s) //method defining
    {
        String[] str = s.split(" ");
return str[str.length-1].length(); //to access the last element
 }
}
