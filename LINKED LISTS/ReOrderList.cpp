/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Input:
//n= 6
//0 - 1 - 2 - 3 - 4 - 5

//Output:
//0 - 5 - 1 - 4 - 2 - 3

ListNode* Solution::reorderList(ListNode* A)
{
    int length=0;
    ListNode *temp=A;
    if(length==2)
    return A;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    int mid=(length-1)/2;
    temp=A;
    while(mid--)
    temp=temp->next;

    ListNode *prev=NULL,*curr=temp->next,*nxt;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    temp->next=prev;
    //0 - 1 - 2 - 5 - 4 - 3
    //0 - 5 - (start)1 - 2 - 5,  (rev)4 - 3
    //0 - 5 - 1 - 4 - (start)2 - 5, (rev)3
    //0 - 5 - 1 - 4 - 2 - 3 - 5
    ListNode *start=A;
    ListNode *rev=temp->next;
    temp->next=NULL;
    while(rev!=NULL)
    {
        ListNode *tmp=start->next;
        start->next=rev;
        ListNode *tmp2=rev->next;
        rev->next=tmp;
        start=tmp;
        rev=tmp2;
    }
    return A;
}
