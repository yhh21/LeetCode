package test;

public class Leetcode0566 {
    public int[][] matrixReshape(int[][] nums, int r, int c) { 
        if(nums.length * nums[0].length != r * c){
        	return nums;
        }
        int [][] rtn = new int [r][c];
        int rr = 0 , cc = 0;
        for (int[] is : nums) {
			for (int i : is) {
				rtn[rr][cc] = i;
				++cc;
				rr += cc / c;
				cc %=c;
			}
		}
        return rtn;
    }
}
