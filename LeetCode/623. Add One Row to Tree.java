class TreeNode {
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
    private int value;
    private int targetDepth;
    public TreeNode addOneRow(TreeNode root, int value, int depth) {
        if (depth == 1) {
            return new TreeNode(value, root, null);
        }
        this.value = value;
        this.targetDepth = depth;
        depthFirstSearch(root, 1);
        return root;
    }

    private void depthFirstSearch(TreeNode node, int currentDepth) {
        if (node == null) {
            return;
        }
        if (currentDepth == targetDepth - 1) {
            TreeNode leftChild = new TreeNode(value, node.left, null);
            TreeNode rightChild = new TreeNode(value, null, node.right);
            node.left = leftChild;
            node.right = rightChild;
            return;
        }
        depthFirstSearch(node.left, currentDepth + 1);
        depthFirstSearch(node.right, currentDepth + 1);
    }
}