package test;

public class Leetcode0504 {
    public String convertToBase7(int num) {
    	return Integer.toString(num, 7);
    	
//    	1.
//    	if(num == 0){
//    		return "0";
//    	}
//        String res = "";
//        boolean flag = true;//ÕıÊı
//        if(num < 0){
//        	flag = false;
//        	num *= -1; 
//        }
//        while(num > 0){
//        	res = "" + num % 7 + res;
//        	num /= 7;
//        }
//        if (!flag) {
//			res = "-" + res;
//		}
//        return res;
    }
}
