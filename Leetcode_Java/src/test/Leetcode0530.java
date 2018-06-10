package test;

public class Leetcode0530 {
	int [] array = new int [1000];
	int n = 0;
	
	private void traversal(TreeNode root) {
		if(root == null){
			return;
		}
		traversal(root.left);
		array[n] = root.val;
		++n;
		traversal(root.right);
	}
	
    public int getMinimumDifference(TreeNode root) {
    	traversal(root);
    	int res = Integer.MAX_VALUE;
    	for (int i = 1; i < n; i++) {
			res = Math.min(res , Math.abs(array[i] - array[i - 1]));
		}
        return res;
    }
}
