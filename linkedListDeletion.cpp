#include<iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // Self referencing structure
};

int count(struct Node *ptr)
{
    int c = 0;
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            ptr = ptr->next;
            c += 1;
        }
        return c;
    }
    else
    {
        return c;
    }
    return 1;
}

struct Node *deleteStartNode(struct Node *head){
    struct Node *p = head;
    head = p->next;
    free(p);
    return head;
};

struct Node *deleteAtLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = p->next;
    while(q->next != NULL){
        p =p->next;
        q =q->next;
    }
    p->next =q->next;
    free(q);
    
    return head;
};


struct Node *deleteAtIndex(struct Node *head){
    int c;
   if(count(head) == 0){
       cout<<"Linked list is Empty"<<endl;
    
   }
   else{
        int index , i=0;
        cout<<"Enter the index position to delete";
        cin>>index;
        c = count(head);
        if (index >= 0 && index <= c){
            if(index == 0){
                head = deleteStartNode(head);
                
            }
           else if (index == c-1)
            {
                head = deleteAtLast(head);
            }else{
                struct Node *p = head;
                while(i < index){
                    p =p->next;
                    i++;
                }
                struct Node *q = p->next;
                p->next = q->next;
                free(q);

            }
        }else{
            cout<<"Enter proper index position"<<endl;
        }
        
        
    }

    return head;

};

int display(struct Node *ptr)
{
    if (ptr != NULL)
    {
        cout << "---------------------------------------" << endl;
        cout << "The Elements of Linked List are : ";

        while (ptr != NULL)
        {
            cout << ptr->data << "  ";
            ptr = ptr->next;
        }
        cout << endl;
        cout << "---------------------------------------" << endl;
    }
    else
    {
        cout << "---------------------------------------" << endl;
        cout << "the linked list is EMPTY " << endl;
        cout << "---------------------------------------" << endl;
    }
    return 1;
};
int main(){
    struct Node *head;
    struct Node *tail;
    struct Node *tmp;
    int n, data;

    head = NULL;
    tail = NULL;
    cout << "how many element do you want to insert : ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data of element " << i + 1 << " : ";
        cin >> data;
        cout << endl;
        struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = data;
        tmp->next = NULL;
        if (i == 0)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    };

    head = deleteStartNode(head);
    display(head);
    head = deleteAtIndex(head);
    display(head);
    head = deleteAtLast(head);
    display(head);
    return 0;
}