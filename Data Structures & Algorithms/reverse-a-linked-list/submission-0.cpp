class Solution {
   public:
    ListNode* reverseList1(ListNode* head, ListNode** ans) {
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            (*ans) = head;
           cout<<(head?head->val:-1)<<"  "<<((*ans)?(*ans)->val:-1)<<endl;
            return head;
        }
        cout << (head ? head->val : -1) << endl;
        ListNode* prev = reverseList1(head->next, ans);
        head->next=NULL;
        prev->next = head;
         cout<<(head?head->val:-1)<<"  "<<(prev?prev->val:-1)<<((*ans)?(*ans)->val:-1)<<endl;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = NULL;
        reverseList1(head, &ans);
        return ans;
    }
};
