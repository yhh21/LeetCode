package test;

public class Leetcode0121 {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE , res = 0;
        for (int i = 0; i < prices.length; i++) {
			min = Math.min(min, prices[i]);
			res = Math.max(res, prices[i] - min);
		}
        return res;
    }
}
