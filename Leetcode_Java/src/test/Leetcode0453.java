package test;


public class Leetcode0453 {
    public int minMoves(int[] nums) {
        int rtn = 0, min = nums[0];
        for (int i : nums) {
			min = Math.min(min, i);
		}
        for (int i : nums) {
			rtn += Math.abs(min - i);
		}
        return rtn;
    }

}
