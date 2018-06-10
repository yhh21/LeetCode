package test;

import java.util.LinkedList;
import java.util.List;

public class Leetcode0401 {
    public List<String> readBinaryWatch(int num) {
        List<String> list = new LinkedList<>();
        for(int h = 0 ; h < 12 ; ++h){
        	for (int m = 0; m < 60 ; ++m) {
				if(Integer.bitCount(h * 64 + m) == num){
					list.add(String.format("%d:%02d", h , m));
				}
			}
        }
        return list;
    }
}
