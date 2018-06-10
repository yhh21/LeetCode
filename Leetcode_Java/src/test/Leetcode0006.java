package test;

public class Leetcode0006 {
	public String convert(String s, int numRows) {
		
		//1.String�ĳ�StringBuilder���ٶ����
        if(s.length() <= numRows || numRows == 1){
        	return s;
        }
        StringBuilder r = new StringBuilder("");
        int m = numRows + numRows - 2;
        int i = 0, j;
        //��һ��
        while(i * m < s.length()){
        	r.append(s.charAt(i * m));
        	++i;
        }
        //�м伸�У�j=�ڼ���
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
        //���һ��
        i = 0;
        while((i * m) + numRows - 1 < s.length()){
        	r.append(s.charAt((i * m) + numRows - 1));
        	++i;
        }
        return r.toString();
    }
}
