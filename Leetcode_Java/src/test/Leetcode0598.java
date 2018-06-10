package test;

public class Leetcode0598 {
    public int maxCount(int m, int n, int[][] ops) {
    	int amin = m, bmin = n;
        for (int[] is : ops) {
			if(is[0] < amin){
				amin = is[0];
			}
			if(is[1] < bmin){
				bmin = is[1];
			}
		}
        return amin * bmin;
    }
}
