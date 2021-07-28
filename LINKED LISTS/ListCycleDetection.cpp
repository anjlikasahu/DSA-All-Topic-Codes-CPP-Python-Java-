/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *slow=A;
    ListNode *fast=A;
    while(fast->next!=NULL &&fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            slow=A;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
    
    
}

 /*
 Other solution:
 {
 map<ListNode*, int> mp;
    while(A!=NULL){
        if(mp[A] != 0){
            return A;
        }
         mp[A] = 1;
         A= A->next;
    }
 return NULL; 
 } */
