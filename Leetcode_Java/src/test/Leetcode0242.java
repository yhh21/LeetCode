package test;

public class Leetcode0242 {
    public boolean isAnagram(String s, String t) {
    	if(s.length() != t.length()){
    		return false;
    	}
        int [] m1 = new int [128];
        int [] m2 = new int [128];
        for (int i = 0; i < s.length(); i++) {
			++m1[s.charAt(i)];
		}
        for (int i = 0; i < t.length(); i++) {
			++m2[t.charAt(i)];
		}
        for (int i = 'a'; i <= 'z'; i++) {
			if(m1[i] != m2[i]){
				return false;
			}
		}
        return true;
    }
}
