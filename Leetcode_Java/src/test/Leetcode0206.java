package test;

public class Leetcode0206 {
    public ListNode reverseList(ListNode head) {
        ListNode p = null;
        while (head != null) {
			ListNode next = head.next;
			head.next = p;
			p = head;
			head = next;
		}
        return p;
    }
}