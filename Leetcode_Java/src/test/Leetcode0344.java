package test;

public class Leetcode0344 {
	public String reverseString(String s) {
		char [] cs = s.toCharArray();
		int i = 0 , j = cs.length - 1;
		char t = ' ';
		while(i < j){
			t = cs[j];
			cs[j] = cs [i];
			cs[i] = t;
			++i;
			--j;
		}
		return new String(cs);
		
//		1.
//        StringBuffer stringBuffer = new StringBuffer(s);
//        return stringBuffer.reverse().toString();
    }
}
