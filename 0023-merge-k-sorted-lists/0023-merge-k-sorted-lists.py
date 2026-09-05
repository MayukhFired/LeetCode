# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        
        interval = 1
        while interval < len(lists):
            for i in range(0 , len(lists) - interval , interval * 2):
                lists[i] = self.mergeTwo(lists[i] , lists[i + interval])
            interval *= 2
        return lists[0]

    def mergeTwo(self , l1 : ListNode , l2 : ListNode) -> ListNode:
        dummy = ListNode(-1)
        curr = dummy

        while l1 and l2:
            if l1.val <= l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next

        curr.next = l1 if l1 else l2
        return dummy.next