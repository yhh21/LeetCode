package test;

public class Leetcode0011 {
	public int maxArea(int[] height) {
        int m = -1, l = 0, r = height.length - 1;
        while(l < r){
        	m = Math.max(m, Math.min(height[r], height[l]) * (r - l) );
        	if(height[l] <= height[r]){
        		++l;
        	}else {
				--r;
			}
        }
        return m;
    }
}
