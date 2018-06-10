package test;

public class Leetcode0538 {
	int i = 0 ;
	public TreeNode convertBST(TreeNode root) {
        if(root == null){
        	return null;
        }
        convertBST(root.right);
        root.val += i;
        i = root.val;
        convertBST(root.left);
        return root;
    }
}
