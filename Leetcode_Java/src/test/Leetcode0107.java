package test;

import java.util.LinkedList;
import java.util.List;

public class Leetcode0107 {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
    	List<List<Integer>> lists = new LinkedList<>();
    	traversal(lists, root, 0);
    	return lists;
    }
    
    private void traversal(List<List<Integer>> lists , TreeNode root , int deep) {
		if(root == null){
			return;
		}
		if (lists.size() <= deep ) {
			lists.add(0 , new LinkedList<>());
		}
		lists.get(lists.size() - 1 - deep).add(root.val);
		traversal(lists, root.left, deep + 1);
		traversal(lists, root.right, deep + 1);
	}
}
