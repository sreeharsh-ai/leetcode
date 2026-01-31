/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Merge k lists using divide and conquer
struct ListNode* mergeKListsHelper(struct ListNode** lists, int left, int right) {
    if (left > right) return NULL;
    if (left == right) return lists[left];
    
    int mid = left + (right - left) / 2;
    struct ListNode* l1 = mergeKListsHelper(lists, left, mid);
    struct ListNode* l2 = mergeKListsHelper(lists, mid + 1, right);
    return mergeTwoLists(l1, l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    return mergeKListsHelper(lists, 0, listsSize - 1);
}

