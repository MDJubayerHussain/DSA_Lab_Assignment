
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




void Enqueue(int ItemType)
{
    node* temp2;
    temp2 = new node();
    temp2->data = ItemType ;
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


void Dequeue(int &ItemType)
{
    node* del_temp= new node();
    del_temp= head;
    ItemType=del_temp->data;
    head= head->next;
    delete del_temp;
}



void PrintQueue()
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
        cout<<"Make the list empty by calling 'MakeEmpty()' function. ";
    MakeEmpty();

    cout<<"checking if Queue is full:";
    if(IsFull()==0)
    {
        cout<<"Not full\n";
    }

    cout<<"checking if Queue is empty:";
    if(IsEmpty()==1)
    {
        cout<<"Empty\n";
    }
    else
        cout<<"Not Empty\n";

    cout << "\nAdding on Queue(FIFO)" << endl;
    Enqueue(5);
    PrintQueue();
    Enqueue(6);
    PrintQueue();
    Enqueue(7);
    PrintQueue();
    Enqueue(8);
    PrintQueue();
    Enqueue(9);
    PrintQueue();


    cout<<"checking if Queue is empty:";
    if(IsEmpty()==1)
    {
        cout<<"Empty\n";
    }
    else
    {
        cout<<"Not Empty\n";
    }


    cout << "\nDelete from Queue(FIFO)" << endl;
    int Item;
    Dequeue(Item);
    cout<< "you deleted :"<< Item<<"  ";
    PrintQueue();
    Dequeue(Item);
    cout<< "you deleted :"<< Item<<"  ";
    PrintQueue();
    Dequeue(Item);
    cout<< "you deleted :"<< Item<<"  ";
    PrintQueue();

    cout<<"Make the list empty by calling 'MakeEmpty()' function. ";
    MakeEmpty();
    PrintQueue();



    return 0;
}
//void MakeEmpty();
//void Enqueue(ItemType);done done
//void Dequeue(ItemType&);
//bool IsEmpty(); done done
//bool IsFull();done done
//void PrintQueue(); done
