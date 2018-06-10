package test;

public class Leetcode0070 {
    public int climbStairs(int n) {
    	if(n <= 2){
    		return n;
    	}
        int [] map = new int [n];
        map[0] = 1;
        map[1] = 2;
        for (int i = 2; i < n; i++) {
			map[i] = map[i - 1] + map[i - 2];
		}
        return map[n - 1];
    }
}
