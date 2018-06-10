package test;

import java.util.ArrayList;

//import java.util.Arrays;

public class Leetcode0500 {
	public String[] findWords(String[] words) {
		if(words.length == 0){
			return new String[]{};
		}
		int [] map = new int[128];
		char [] a = {'Q','W','E','R','T','Y','U','I','O','P','q','w','e','r','t','y','u','i','o','p'};
		char [] b = {'A','S','D','F','G','H','J','K','L','a','s','d','f','g','h','j','k','l'};
		char [] c = {'Z','X','C','V','B','N','M','z','x','c','v','b','n','m'};
		for (char d : a) {
			map[d] = 1;
		}
		for (char d : b) {
			map[d] = 2;
		}
		for (char d : c) {
			map[d] = 3;
		}
		ArrayList<String> rtn = new ArrayList<>();
		boolean flag = true;
		int first = 0;
		for (String d : words) {
			if(d.isEmpty()){
				continue;
			}
			flag = true;
			first = map[d.charAt(0)];
			for (int i = 1; i < d.length(); ++i) {
				if(first != map[d.charAt(i)]){
					flag = false;
					break;
				}
			}
			if(flag == true){
				rtn.add(d);
			}
		}
		return rtn.toArray(new String[rtn.size()]);
//		1.
//		String aString = "QWERTYUIOPqwertyuiop";
//		String bString = "ASDFGHJKLasdfghjkl";
//		String cString = "ZXCVBNMzxcvbnm";
//		ArrayList<String> rtn = new ArrayList<>();
//		int flag = 0;
//        for (int i = 0 ; i < words.length ; ++i) {
//        	flag = 0;
//			for(int j = 0 ; j < words[i].length() ; ++j){
//				if(aString.contains(words[i].subSequence(j, j + 1))){
//					if(flag ==0){
//						flag = 1;
//						continue;
//					}
//					if(flag != 1){
//						flag = -1;
//						break;
//					}
//				}
//				if(bString.contains(words[i].subSequence(j, j + 1))){
//					if(flag ==0){
//						flag = 2;
//						continue;
//					}
//					if(flag != 2){
//						flag = -1;
//						break;
//					}
//				}
//				if(cString.contains(words[i].subSequence(j, j + 1))){
//					if(flag ==0){
//						flag = 3;
//						continue;
//					}
//					if(flag != 3){
//						flag = -1;
//						break;
//					}
//				}
//			}
//			if(flag != -1){
//				rtn.add(words[i]);
//			}
//        }
//		return rtn.toArray(new String[rtn.size()]);
    }
}
