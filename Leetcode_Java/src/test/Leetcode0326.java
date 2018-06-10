package test;

public class Leetcode0326 {
    public boolean isPowerOfThree(int n) {
        if(n <= 0){
        	return false;
        }
        return 1162261467 % n == 0;
    }
}
