package test;

public class Leetcode0171 {
	public int titleToNumber(String s) {
        int res = 0;
        char [] cs = s.toCharArray();
        for (char c : cs) {
			res = res * 26 + c - 'A' + 1;
		}
        return res;
    }
}
