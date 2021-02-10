
#include <iostream>

using namespace std;

struct node
{

    int data;
    node* next;
};
node* head;


bool IsFull()
{
    node* location;
    try
    {
        location = new node();
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}


bool IsEmpty()
{
    if(head==NULL)
        return true;
    else
        return false;
}

int top()
{
    if(IsEmpty()==1)
    {
        cout<<"list is empty.";
        return 0;
    }

    else
    {
        node* tempLast= new node();
        node* secondLast= new node();
        tempLast= head;
        secondLast= head;
        while(tempLast->next!=NULL )
        {
            secondLast=tempLast;
            tempLast= tempLast->next;
        }
        return  tempLast->data;
    }
}

void Push(int num)
{
    node* temp2;
    temp2 = new node();
    temp2->data = num;
    temp2-> next = NULL;
    if(head==NULL)
    {
        head=temp2;
    }
    else
    {
        node *nextnum= head;
        while(nextnum->next!=NULL)
        {
            nextnum=nextnum->next;
        }
        nextnum->next=temp2;
    }
}


void Pop()
{
    node* del_tempLast= new node();
    node* secondLast= new node();
    del_tempLast= head;
    secondLast= head;
    while(del_tempLast->next!=NULL )
    {
        secondLast=del_tempLast;
        del_tempLast= del_tempLast->next;
    }

    secondLast->next=NULL;
    delete del_tempLast;
}


void PrintStack()
{
    cout<<"List is :";
    //node *temp = head;
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp -> data<<" , ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main()
{

    cout<<"checking if stack is full:";
    if(IsFull()==0)
    {
        cout<<"Not full\n";
    }

    cout<<"checking if stack is empty:";
    if(IsEmpty()==1)
    {
        cout<<"Empty\n";
    }
    else
        cout<<"Not Empty\n";

    cout << "\nAdding on stack(LIFO)" << endl;
    Push(5);
    PrintStack();
    Push(6);
    PrintStack();
    Push(7);
    PrintStack();
    Push(8);
    PrintStack();
    Push(9);
    PrintStack();
    cout<<"Last element is "<<top();
    cout << "\npoping from  stack(LIFO)" << endl;
    Pop();
    PrintStack();
    Pop();
    PrintStack();
    Pop();
    PrintStack();
    cout<<"checking if stack is full:";
    if(IsFull()==0)
    {
        cout<<"Not full\n";
    }

    cout<<"checking if stack is empty:";
    if(IsEmpty()==1)
    {
        cout<<"Empty\n";
    }
    else
        cout<<"Not Empty\n";


    cout<<"Last element is "<<top();


    return 0;
}


