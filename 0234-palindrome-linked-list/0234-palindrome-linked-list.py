# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode | None) -> bool:
    # 1----------------------------------1
        # arr = []
        # while head:
        #     arr.append(head.val)
        #     head = head.next
        # return arr == arr[::-1]
    # 1----------------------------------1
        if head == None or head.next == None:
            return True
        fast = head
        slow = head

        while fast and fast.next:
            temp = slow
            slow = slow.next
            fast = fast.next.next
        if fast:
            slow = slow.next
        prev = None
        curr = slow

        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        
        p1 = head
        p2 = prev
        
        while p2:
            if p1.val != p2.val:
                return False
            p1 = p1.next
            p2 = p2.next
        return True