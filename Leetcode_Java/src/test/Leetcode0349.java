package test;

import java.util.LinkedList;

public class Leetcode0349 {
    public int[] intersection(int[] nums1, int[] nums2) {
    	final int M = 10000;
        boolean [] map = new boolean [2 * M];
        LinkedList<Integer> linkedList = new LinkedList<>();
        for (int i : nums1) {
			map[i + M] = true;
		}
        for (int i : nums2) {
			if(map[i + M]){
				map[i + M] = false;
				linkedList.add(i);
			}
		}
        int [] res = new int [linkedList.size()];
        for (int i = 0; i < res.length; i++) {
			res[i] = linkedList.get(i);
		}
        return res;
    }
}
