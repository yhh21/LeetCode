package test;

public class Leetcode0002 {
	public class ListNode {
	     int val;
	     ListNode next;
	     ListNode(int x) { val = x; }
	}
	
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode root = new ListNode(0), r = root;
		int i = 0;
		while(l1 != null || l2 != null){
			if(l1 != null){
				i += l1.val;
				l1 = l1.next;
			}
			if(l2 != null){
				i += l2.val;
				l2 = l2.next;
			}
			r.next = new ListNode(i%10);
			i /= 10;
			r = r.next;
		}
		if(i > 0){
			r.next = new ListNode(i%10);
		}
		return root.next;
		
		
//		1.
//		ListNode root = l1, p1 = l1, p2 = l2 , r = root;
//		int i = 0, j = 0;//j=进位
//		while(true){
//			i = p1.val + p2.val + j;
//			j = i/10;
//			p1.val = i%10;
//			r = p1;//当前计算节点
//			p1 = p1.next;
//			p2 = p2.next;
//			if(p1 == null || p2 == null){//有null停止
//				break;
//			}
//		}
//		if(p2 != null){
//			r.next = p2;
//		}
//		if(j > 0){
//			while(r.next != null){
//				r.next.val += j;
//				j = r.next.val/10;
//				r.next.val %= 10;
//				r = r.next;
//			}
//			if(j > 0){
//				r.next = new ListNode(j%10);
//			}
//		}
//		return root;
    }
}
