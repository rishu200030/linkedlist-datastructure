#include <iostream>
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
struct Node *insertAtFirst(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the Element which is inserted at 1st Position : ";
    cin >> ptr->data;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtIndex(struct Node *head)
{

    int index, data, i = 0, c;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    cout << "Enter the Index position : ";
    cin >> index;
    cout << endl;
    c = count(head);
    if (index >= 0 && index <= c)
    {
        if (index == 0)
        {
            head = insertAtFirst(head);
        }
        else
        {
            cout << "Enter the Element which is inserted at " << index << " Position : ";
            cin >> data;
            cout << endl;
            while (i != index - 1)
            {
                p = p->next;
                i++;
            }
            ptr->data = data;
            ptr->next = p->next;
            p->next = ptr;
        }
    }
    else
    {
        cout << "Index out of Range" << endl;
    }

    return head;
}

struct Node *insertAtEnd(struct Node *head)
{
    int data;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    cout << endl;
    cout << "Enter the Element which is inserted at Last Position : ";
    cin >> data;
    cout << endl;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;

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

int main()
{
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
    }
    int option;

    cout << "welcome , please enter the operation to be performed" << endl;
    do
    {
        cout << "***********************" << endl;
        cout << "  OPERTAIONS " << endl;
        cout << "To INSERT AT STARTING POSITION press 1" << endl;
        cout << "To INSERT AT A PARTICULAR INDEX POSITION press 2" << endl;
        cout << "To INSERT AT A PARTICULAR LAST POSITION press 3" << endl;
        cout << "To DISPLAY press 4" << endl;
        cout << "To QUIT press 0" << endl;
        cout << "***********************" << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            head = insertAtFirst(head);
            break;
        case 2:
            head = insertAtIndex(head);
            break;
        case 3:
            head = insertAtEnd(head);
            break;
        case 4:
            display(head);
            break;
        case 0:
            break;

        default:
            cout << "please enter valid option" << endl;
        }
    } while (option != 0);

    return 0;
}
