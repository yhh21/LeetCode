package test;

public class Leetcode0005 {
	public String longestPalindrome(String s) {
		
		//1.所谓的O(n)的算法?应该是Java的String类导致的超时，刷题还是首选c++。
        //String改成StringBuilder
		// Insert '#'
	    StringBuilder t = new StringBuilder("$#");
	    for (int i = 0; i < s.length(); ++i) {
	        t.append(s.charAt(i) + "#");
	    }
	    t.append("%");//$#b#a#b#a#b#
	    // Process t
	    int[] p = new int[t.length()];
	    int mx = 0, id = 0, resLen = 0, resCenter = 0;
	    for (int i = 1; i < t.length() - 1; ++i) {
	        p[i] = mx > i ? Math.min(p[2 * id - i], mx - i) : 1;
	        while (t.charAt(i + p[i]) == t.charAt(i - p[i])) ++p[i];
	        if (mx < i + p[i]) {
	            mx = i + p[i];
	            id = i;
	        }
	        if (resLen < p[i]) {
	            resLen = p[i];
                    resCenter = i;
	        }
	    }
	    return s.substring((resCenter - resLen) / 2, (resCenter - resLen) / 2 + resLen - 1);
    }
}
