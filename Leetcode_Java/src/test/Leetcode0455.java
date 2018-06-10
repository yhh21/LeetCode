package test;

import java.util.Arrays;

public class Leetcode0455 {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int res = 0 , j = 0;
        for (int i : g) {
			for (; j < s.length;) {
				if (i <= s[j++]) {
					++res;
					break;
				}
			}
		}
        return res;
    }
}
