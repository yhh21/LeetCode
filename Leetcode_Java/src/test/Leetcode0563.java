package test;

//import java.util.Arrays;

public class Leetcode0563 {
	int res = 0;
    public int findTilt(TreeNode root) {
        traversal(root);
        return res;
    }
    
    private int traversal(TreeNode root) {
		if(root == null){
			return 0;
		}
		int left = traversal(root.left);
		int right = traversal(root.right);
		res += Math.abs(left - right);
		return left + right + root.val;
	}
}
