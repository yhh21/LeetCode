package test;

public class Leetcode0108 {
	public TreeNode sortedArrayToBST(int[] nums) {
        return convert(nums, 0, nums.length - 1);
    }
	
	private TreeNode convert(int [] nums , int s , int e) {
		if(s > e){
			return null;
		}
		int mid = (s + e) / 2;
		TreeNode node = new TreeNode(nums[mid]);
		node.left = convert(nums, s, mid - 1);
		node.right = convert(nums, mid + 1 , e);
		return node;
	}
}
