package test;

public class Leetcode0541 {
    public String reverseStr(String s, int k) {
        char [] cs = s.toCharArray();
        for (int i = 0; i < cs.length; i += 2 * k) {
			swap(cs, i, Math.min(i + k - 1, cs.length - 1));
		}
        return new String(cs);
    }
    
    private void swap(char [] cs , int s , int e) {
		while (s < e) {
			char t = cs[s];
			cs[s] = cs[e];
			cs[e] = t;
			++s;
			--e;
		}
	}
}
