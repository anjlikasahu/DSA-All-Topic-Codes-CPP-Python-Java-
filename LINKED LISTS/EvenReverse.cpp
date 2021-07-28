/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Add val to tail of list
void push(ListNode **head, ListNode **tail, ListNode *val)
{
    if (!(*head))
        *head = *tail = val;
    else {
        (*tail)->next = val;
        *tail = (*tail)->next;
    }
}

// Split as per even and odd positions
pair<ListNode *, ListNode *>
split(ListNode *head)
{
    ListNode *oddH = nullptr, *oddT = nullptr;
    ListNode *eveH = nullptr, *eveT = nullptr;
    int pos = 1;
    while (head) {
        ListNode *next = head->next;
        // Isolate node
        head->next = nullptr;
        // Add to correspnding list
        if (pos & 1) // Odd
            push(&oddH, &oddT, head);
        else
            push(&eveH, &eveT, head);
        head = next;
        ++pos;
    }
    
    return {oddH, eveH};
}

// Reverse list
ListNode *
reverse(ListNode *head)
{
    ListNode *prev = nullptr;
    while (head) {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    
    return prev;
}

// Given list A and B, return a list with elements from A and B in interleaving manner
ListNode *
mergeLists(ListNode *A, ListNode *B)
{
    ListNode *head = nullptr, *tail = nullptr;
    while (A and B) {
        ListNode *nextA = A->next, *nextB = B->next;
        A->next = nullptr, B->next = nullptr;
        push(&head, &tail, A);
        push(&head, &tail, B);
        A = nextA, B = nextB;
    }
    if (A) tail->next = A;
    if (B) tail->next = B;
    
    return head;
}

ListNode* Solution::solve(ListNode* A) {
    
    // Step 1 : Divide into two lists as per odd and even positions
    ListNode *odd, *even;
    tie(odd, even) = split(A);
    
    // Step 2 : Reverse the even list
    even = reverse(even);
    
    // Step 3 : Merge the odd list and reversed even list interleavingly
    ListNode *merged = mergeLists(odd, even);
    
    return merged;
}