package test;

import java.util.HashMap;

public class Leetcode0003 {
	public int lengthOfLongestSubstring(String s) {
		
         HashMap<Character, Integer> hashMap = new HashMap<>();
        int i = 0, j = 0 , t = 0;
        for(; j < s.length() ; ++j){
        	if(hashMap.containsKey(s.charAt(j))){
        		i = Math.max(hashMap.get(s.charAt(j)) + 1 , i);
        	}
        	t = Math.max(t, j - i + 1);
        	hashMap.put(s.charAt(j), j );
        }
		return t;
    }
}
