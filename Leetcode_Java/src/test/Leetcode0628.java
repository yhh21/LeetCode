package test;

public class Leetcode0628 {
    public int maximumProduct(int[] nums) {
        int a = Integer.MIN_VALUE , b = a , c = b , d = Integer.MAX_VALUE , e = d;//a > b > c , d < e
        for (int i : nums) {
			if(i >= a){
				c = b;
				b = a;
				a = i;
			}else if (i >= b) {
				c = b;
				b = i;
			}else if (i > c) {
				c = i;
			}
			if(i <= e){
				d = e;
				e = i;
			}else if (i < d) {
				d = i;
			}
		}
        return b * c > d * e ? a * b * c : a * d * e;
    }
}
