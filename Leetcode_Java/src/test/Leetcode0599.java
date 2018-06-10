package test;

import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

public class Leetcode0599 {
    public String[] findRestaurant(String[] list1, String[] list2) {
    	List<String> list = new ArrayList<>();
    	HashMap<String, Integer> map = new HashMap<>();
    	for (int i = 0; i < list1.length; i++) {
			map.put(list1[i], i);
		}
    	int min = Integer.MAX_VALUE;
    	for (int i = 0; i < list2.length && i <= min; i++) {
			if(map.containsKey(list2[i])){
				if(map.get(list2[i]) + i < min){
					list.clear();
					min = map.get(list2[i]) + i;
					list.add(list2[i]);
				}else if (map.get(list2[i]) + i == min) {
					list.add(list2[i]);
				}
			}
		}
    	return list.toArray(new String[list.size()]);
    	
//    	1.
//    	List<String> list = new ArrayList<>();
//    	int min = Integer.MAX_VALUE;
//        for (int i = 0; i < list1.length; i++) {
//			for (int j = 0; j < list2.length; j++) {
//				if(i + j <= min && list1[i].equals(list2[j])){
//					if(i + j < min){
//						list.clear();
//					}
//					list.add(list1[i]);
//					min = i + j;
//				}
//			}
//		}
//        return list.toArray(new String[list.size()]);
    }
}
