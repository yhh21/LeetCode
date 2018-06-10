package test;

public class Leetcode0226 {
    public TreeNode invertTree(TreeNode root) {
    	if(root == null){
    		return null;
    	}
    	TreeNode pNode = invertTree(root.left);
    	root.left = invertTree(root.right);
    	root.right = pNode;
    	
    	return root;
    }
}
