# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode | None) -> ListNode | None:
    # 1---------------------------------------------------------1
        # dummy = ListNode()
        # curr = head

        # while curr:
        #     prev = dummy
        #     while prev.next and prev.next.val < curr.val:
        #         prev = prev.next
        #     nxt = curr.next
        #     curr.next = prev.next
        #     prev.next = curr
        #     curr = nxt

        # return dummy.next
    # 1-------------------------------------------------------1
        arr = []
        it = head
        while it:
            arr.append(it.val)
            it = it.next
        arr.sort()
        it = head
        for val in arr:
            it.val = val
            it = it.next
        return head