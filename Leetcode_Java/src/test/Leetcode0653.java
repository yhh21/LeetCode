package test;


public class Leetcode0653 {
	boolean [] map;
	boolean flag;
	
	private void traversal(TreeNode root, int k) {
		if(flag || root == null){
			return;
		}
		map[k - root.val + 10000] = true;
		if(map[root.val + 10000] && k != 2 * root.val){
			flag = true;
		}
		traversal(root.left, k);
		traversal(root.right, k);		
	}
	
    public boolean findTarget(TreeNode root, int k) {
    	map = new boolean[k + 20000];
        traversal(root, k);
        return flag;
    }
}
