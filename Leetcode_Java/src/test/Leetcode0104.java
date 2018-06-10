package test;

public class Leetcode0104 {
	int L = 1;
	
	private void traversal(TreeNode root , int level) {
		if(level > L){
			L = level;
		}
		if(root.left != null){
			traversal(root.left, level + 1);
		}
		if(root.right != null){
			traversal(root.right, level + 1);
		}
		
	}
	
	public int maxDepth(TreeNode root) {
        if(root == null){
        	return 0;
        }
        traversal(root, 1);
        return L;
    }
}
