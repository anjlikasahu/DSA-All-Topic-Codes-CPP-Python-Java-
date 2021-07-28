/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head, int k) {
    
    ListNode* current = head;
    ListNode* next;
    ListNode* prev = NULL;
    int count = 0;
    
    //reverse first k nodes of the linked list 
    while (current != NULL && count < k)
    {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
    }
    //Now head points to the kth node. So change next of head to (k+1)th node
  
    if(head != NULL)
    head->next = current;
    
    // We do not want to reverse next k nodes. So move the current
    //pointer to skip next k nodes
    
    count = 0;
    while(count < k-1 && current != NULL )
    {
    current = current->next;
    count++;
    }
    //4) Recursively call for the list
    //starting from current->next. And make
    //rest of the list as next of first node
    if(current != NULL)
    current->next = solve(current->next, k);

    /* 5) prev is new head of the input list */
    return prev;  

}
