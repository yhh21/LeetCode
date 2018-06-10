package test;

import java.util.ArrayList;
import java.util.HashMap;

public class Leetcode0350 {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> list = new ArrayList<>();
        for (int i : nums1) {
			map.put(i, map.getOrDefault(i, 0) + 1);
		}
        for (int i : nums2) {
			if(map.getOrDefault(i, 0) > 0){
				list.add(i);
				map.put(i, map.get(i) - 1);
			}
		}
        int [] res = new int [list.size()];
        for (int i = 0; i < res.length; i++) {
			res[i] = list.get(i);
		}
        return res;
    }
}
