
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


void MakeEmpty()
{
    if(head==NULL)
        cout<<"List is already empty\n";
    else
    {

        node* temp= new node();
        temp=head;
        head=NULL;
        node *tempPos;
        while(temp->next!=NULL)
        {
            tempPos=temp-> next;
            delete temp;
            temp = tempPos;
        }
        cout<<"Successfully made the list empty.\n";
    }
}


int LengthIs()
{
    int  Count =0;
    if(head==NULL)
    {
        return Count;
    }
    else
    {
        node *nextnum= head;
        Count++;
        while(nextnum->next!=NULL)
        {
            nextnum=nextnum->next;
            Count++;
        }
        return Count;
    }
}


void InsertItem(int number)
{
    node* temp2;
    temp2 = new node();
    temp2->data = number ;
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


void DeleteItem(int num)
{
    if(head==NULL)
    {
        cout<<"There is no item on the list.";
    }
    else
    {

        node* del_temp= new node();
        node* secondLast= new node();
        del_temp= head;
        secondLast= head;
        while(del_temp->next!=NULL )
        {
            secondLast=del_temp;
            del_temp= del_temp->next;
            if(num==del_temp->data)
            {
                secondLast->next=del_temp->next;
                delete del_temp;
                break;
            }

        }

    }
}

bool RetrieveItem(int iteam)
{
    if(head==NULL)
    {
        return false;
    }
    else
    {
        node* tempLast= new node();
        node* secondLast= new node();
        tempLast= head;

        while(tempLast->next!=NULL )
        {
            tempLast= tempLast->next;
            if(iteam ==tempLast->data)
            {
                return true;
                break;
            }

        }
        return  false;
    }

}


void PrintList()
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
    // checking is full
    cout<<"checking if Queue is full:";
    if(IsFull()==0)
    {
        cout<<"Not full\n";
    }

    // Make the list empty
    cout<<"Make the list empty by calling 'MakeEmpty()' function. ";
    MakeEmpty();

    cout<<"Length Is : "<<LengthIs()<<"\n";

    cout << "\nAdding on a unsorted list." << endl;
    InsertItem(5);
    PrintList();
    InsertItem(7);
    PrintList();
    InsertItem(3);
    PrintList();
    InsertItem(2);
    PrintList();
    InsertItem(9);
    PrintList();

    cout<<"Length Is:"<<LengthIs()<<"\n";
    cout<<"Finding the item(3) on the list: ";
    if(RetrieveItem(3)==1)
    {
        cout<<"Item is on the list \n";
    }
    else
    {
        cout<<"Item is 'not' on the list\n";
    }

    cout<<"Finding the item(12) on the list: ";
    if(RetrieveItem(12)==1)
    {
        cout<<"Item is on the list \n";
    }
    else
    {
        cout<<"Item is 'not' on the list\n";
    }

    cout << "\nDelete(2) from the unsorted list." << endl;
    DeleteItem(2);
    PrintList();
    cout << "\nDelete(7) from the unsorted list." << endl;
    DeleteItem(7);
    PrintList();

    cout<<"Length Is:"<<LengthIs()<<"\n";

    return 0;
}


