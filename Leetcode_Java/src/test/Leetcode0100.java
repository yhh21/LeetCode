package test;

public class Leetcode0100 {
	boolean b = true;
    public boolean isSameTree(TreeNode p, TreeNode q) {
    	if(p == null && q == null){
    		return true;
    	}else if(p == null || q == null){
    		return false;
    	}else if(p.val != q.val){
    		return false;
    	}
    	if (b) {
			b = isSameTree(p.left, q.left);
		}
    	if (b) {
			b = isSameTree(p.right, q.right);
		}
    	return b;
    }
}
