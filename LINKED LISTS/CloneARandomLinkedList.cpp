/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    map<RandomListNode* ,RandomListNode*>mp;
    RandomListNode* curr = A;
    while(A)
    {
        RandomListNode* temp = new RandomListNode(A->label);
        mp[A] = temp;
        A= A->next;
    }
    A = curr;
    while(A)
    {
        if(A->next == NULL)
        {
            mp[A]->next = NULL;
        }
        else
        {
            mp[A]->next = mp[A->next];
        }
        
        if(A->random == NULL)
        {
            mp[A]->random = NULL;
        }
        else
        {
            mp[A]->random = mp[A->random];
        }
        A = A->next;
    }
    return mp[curr];
    
}
