package test;

public class Leetcode0543 {
	int res = 0;
    public int diameterOfBinaryTree(TreeNode root) {
    	traversal(root);
    	return res;
    }
    
    private int traversal(TreeNode root) {
		if(root == null){
			return 0;
		}
		int l = traversal(root.left);
		int r = traversal(root.right);
		if(l + r> res){
    		res = l + r;
    	}
		return Math.max(l , r) + 1; 
	}
}
