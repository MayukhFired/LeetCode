# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution:
#     def merge(self , l1: ListNode , l2: ListNode) -> ListNode:
#         if not l1:
#             return l2
#         if not l2:
#             return l1
#         dummy = ListNode(0)
#         tail = dummy

#         while l1 and l2:
#             if l1.val < l2.val:
#                 tail.next = l1
#                 l1 = l1.next
#             else:
#                 tail.next = l2
#                 l2 = l2.next
#             tail = tail.next
#         tail.next = l1 if l1 else l2
#         return dummy.next

#     def mergeSort(self , head: ListNode) -> ListNode:
#         if not head or not head.next:
#             return head
        
#         prev = None
#         slow = head
#         fast = head

#         while fast and fast.next:
#             prev = slow 
#             slow = slow.next
#             fast = fast.next.next

#         if prev:
#             prev.next = None
        
#         l1 = head
#         l2 = slow

#         l1 = self.mergeSort(l1)
#         l2 = self.mergeSort(l2)

#         return self.merge(l1 , l2)
    # def sortList(self, head: ListNode | None) -> ListNode | None:
    #     return self.mergeSort(head)

class Solution:
    def sortList(self , head: optional[ListNode]) -> optional[ListNode]:
        arr = []
        curr = head
        while curr:
            arr.append(curr.val)
            curr = curr.next
        arr.sort()
        curr = head
        for val in arr:
            curr.val = val
            curr = curr.next
        return head