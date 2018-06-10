package test;

public class Leetcode0404 {
	int res = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null){
        	return 0;
        }
        if(root.left != null && root.left.left == null && root.left.right == null){
        	res += root.left.val;
        }
        sumOfLeftLeaves(root.left);
        sumOfLeftLeaves(root.right);
        return res;
    }
}
