/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    //As input node of the linkedlist
    //public method is palindrome is called
    //To check linkedlist is palindrome or not
    public boolean isPalindrome(ListNode head) {
        //defining the pointers
        ListNode fast = head;
        ListNode slow = head;
        //compare with original list at the head
        while (fast!=null && fast.next!=null){
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode temp = reverse(slow);
        while(temp!=null && head!= null){
            if(temp.val!= head.val) return false;
            temp = temp.next;
            head = head.next;
        }
        return true;
    }
    //Irerative reversal
    public ListNode reverse(ListNode head){
        ListNode p =null;
        ListNode q =null;
        ListNode r = head;
        while(r!=null){
            p = q;
            q = r;
            r = r.next;
            q.next = p;
        }
        return q;
    }
}