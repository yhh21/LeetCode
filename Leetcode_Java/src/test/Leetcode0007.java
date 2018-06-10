package test;

public class Leetcode0007 {
	public int reverse(int x) {
		double a = 0;
		int t = Math.abs(x);
		
		for(; t > 0 ;){
			a = a * 10 + t % 10;
			t /= 10;
		}
		
		a *= x>=0 ? 1 : -1;
		
		if(a > Integer.MAX_VALUE  || a < Integer.MIN_VALUE){
			return 0;
		}
        
        return (int)a;
    }
}
