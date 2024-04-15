public class TreeNode {
    int val;
    TreeNode left; 
    TreeNode right; 

    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int sumNumbers(TreeNode root) {
        return depthFirstSearch(root, 0);
    }
    private int depthFirstSearch(TreeNode node, int sum){
        if(node == null){
            return 0;
        }sum = sum * 10 + node.val;
        
        if(node.left == null && node.right == null){
            return sum;
            }
        return depthFirstSearch(node.left, sum) + depthFirstSearch(node.right, sum);
    }
}