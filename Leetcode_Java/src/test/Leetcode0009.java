package test;

public class Leetcode0009 {
	public boolean isPalindrome(int x) {
		//1.不得不说Leetcode的运行时间是跟网速的关系很大，MDZZ
        if(x < 0 || (x%10 == 0 && x > 10)){
        	return false;
        }
        int r = 0;//反转后的数
        int t = x;
        for(; t != 0 ; ){
        	r = r * 10 + t % 10;
        	t /= 10;
        }
        return x == r;
    }
}
