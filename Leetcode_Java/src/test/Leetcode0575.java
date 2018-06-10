package test;

public class Leetcode0575 {
    public String reverseWords(String s) {
    	if(s.isEmpty()){
    		return s;
    	}
        String [] ss = s.split(" ");
        StringBuffer rtn = new StringBuffer();
        boolean first = true;
        for (String string : ss) {
        	if (!first) {
				rtn.append(" ");
			}
			rtn.append(new StringBuffer(string).reverse());
			first = false;
		}
        return rtn.toString();
    }
}
