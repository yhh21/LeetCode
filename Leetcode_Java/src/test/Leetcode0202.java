package test;

public class Leetcode0202 {
    public boolean isHappy(int n) {
        int a = n , b = n;
        do {
			a = fun(a);
			b = fun(fun(b));
		} while (a != b);
        if(a != 1){
        	return false;
        }else {
			return true;
		}
    }
    
    private int fun(int n) {
		int res = 0;
		while (n > 0) {
			res += (n % 10) * (n % 10);
			n /= 10;
		}
		return res;
	}
}