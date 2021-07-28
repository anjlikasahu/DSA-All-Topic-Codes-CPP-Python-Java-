import java.util.*;
class Node {
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
} 

class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while (t-- > 0) {
            int n = sc.nextInt();
            
            int a = sc.nextInt();
            Node head = new Node(a);
            Node tail = head;
            
            for (int i=0; i<n-1; i++)
            {
                a = sc.nextInt();
                tail.next = new Node(a);
                tail = tail.next;
            }
            
            int k = sc.nextInt();
            
            Solution ob = new Solution();
            head = ob.rotate(head,k);
            printList(head);
        }
    }
    
    public static void printList(Node n) {
        while (n != null) {
            System.out.print(n.data + " ");
            n = n.next;
        }
        System.out.println();
    }
}
// } Driver Code Ends


/* node of linked list:

class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }
}

*/

class Solution{
    //Function to rotate a linked list.
    public Node rotate(Node head, int k) {
        // add code here
        int cnt =0;
        Node curr = head;
        Node curr1 = head;
        while(curr!=null)
        {
            curr = curr.next ;
            cnt++;
        }
        k = k%cnt;
        if(k==0)
        {
            return head;
        }
        curr = head;
        for(int i=0;i<k;i++)
        {
            curr1 = curr;
            curr = curr.next;
        }
        Node prev = curr;
        Node temp = curr;
        curr1.next = null;
        while(prev.next!=null)
        {
            prev = prev.next;
        }
        prev.next = head;
        head = temp;
        return head;
        
    }
}
