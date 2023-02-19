struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

struct ListNode* endOfFirstHalf(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL) {
        return true;
    }

    // �ҵ�ǰ�벿�������β�ڵ㲢��ת��벿������
    struct ListNode* firstHalfEnd = endOfFirstHalf(head);
    struct ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

    // �ж��Ƿ����
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalfStart;
    bool result = true;
    while (result && p2 != NULL) {
        if (p1->val != p2->val) {
            result = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // ��ԭ�������ؽ��
    firstHalfEnd->next = reverseList(secondHalfStart);
    return result;
}