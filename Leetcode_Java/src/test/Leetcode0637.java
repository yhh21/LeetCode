package test;

import java.util.LinkedList;
import java.util.List;

public class Leetcode0637 {
	int L = 0;
	double [][] num = new double [1000][2];
	
	private void traversal(TreeNode root , int level) {
		if(root == null){
			return;
		}
		num[level][0] += root.val;
		++num[level][1];
		if(level > L){
			L = level;
		}
		traversal(root.left, level + 1);
		traversal(root.right, level + 1);
	}
	
    public List<Double> averageOfLevels(TreeNode root) {
    	traversal(root, 0);
    	List<Double> list = new LinkedList<>();
    	for (int i = 0; i <= L; i++) {
			list.add(num[i][0] / num[i][1]);
		}
    	return list;
    }
}
