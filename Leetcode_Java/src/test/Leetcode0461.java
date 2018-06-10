package test;

public class Leetcode0461 {
	public int hammingDistance(int x, int y) {
		x ^= y;
        y = 0;
        for(; x != 0 ; x>>=1){
        	y += x & 1;
        }
        return y;
    }
}
