package test;

public class Leetcode0006 {
	public String convert(String s, int numRows) {
		
		//1.String改成StringBuilder，速度起飞
        if(s.length() <= numRows || numRows == 1){
        	return s;
        }
        StringBuilder r = new StringBuilder("");
        int m = numRows + numRows - 2;
        int i = 0, j;
        //第一行
        while(i * m < s.length()){
        	r.append(s.charAt(i * m));
        	++i;
        }
        //中间几行，j=第几行
        for(j = 1; j < numRows - 1 ; ++j){
        	i = 0;
        	while(true){
        		if(i * m + j < s.length()){
        			r.append(s.charAt(i * m + j));
        		}else {
					break;
				}
        		if((i + 1) * m - j < s.length()){
        			r.append(s.charAt((i + 1) * m - j));
        		}else {
					break;
				}
    			++i;
        	}
        }
        //最后一行
        i = 0;
        while((i * m) + numRows - 1 < s.length()){
        	r.append(s.charAt((i * m) + numRows - 1));
        	++i;
        }
        return r.toString();
    }
}
