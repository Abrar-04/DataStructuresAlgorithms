#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
class link
{
    private:
    Node *first,*last;
    public:
    link(){first=NULL;};
    ~link();

    void insert(int index,int x);
    int Delete(int index);
    int search(int key);
    int length();
    void display();
};


void link::insert(int index, int x)
{
    Node *t,*p=first;
    int i=0;

    if( index<0 || index > (length()+1) )return;

    t = new Node;
    t->data=x;
    t->next=t->prev=NULL;

    if(length()==0)
    {
        first = t;
        last = t;
    }
    else if(index == (length()+1))
    {
        last->next=t;
        t->prev=last;
        last=t;
    }
    else if(index == 1)
    {
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(i=1;i<index-1;i++){p=p->next;}
        Node *q = p->next;
        p->next = t;
        q->prev = t;
        t->next = q;
        t->prev = p;

    }


}
int link::Delete(int index)
{
    Node *p=first,*temp;
    int i;
    int x=-1;
    if(index<1 || index>length())return -1;

    if(length()==1)
    {
        temp = first;
        first = last = NULL;
    }
    else if(index==1)
    {
        temp = first;
        first=first->next;
        first->prev=NULL;
    }
    else if(index == length())
    {
        temp = last;
        last=last->prev;
        last->next=NULL;

    }
    else
    {
        for(i=1;i<index-1;i++){p=p->next;}
        temp = p->next;
        Node *q = temp->next;
        p->next=q;
        q->prev=p;
    }
    x=temp->data;
    delete temp;
    return x;

}

int link::length()
{
    Node *p = first;
    int len=0;
    //int i;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void link::display()
{
    Node *p=first;
    cout<<"\nThe linked list elements are\n";
    while(p)
    {
        cout<<p->data<<endl;

        p = p->next;
    }
    cout<<endl;
}

int link::search(int key)
{
    int x=-1;
    Node *p = first;
    while(p)
    {
        if(p->data==key)
        {
            x=p->data;
        }
        p=p->next;
    }
    return x;
}

link::~link()
{
    Node *p;
    while(first)
    {
        p=first;
        first=first->next;
        delete p;
    }
}


int main()
{


    link l;
    int value,x;

    l.insert(1,3);
    l.insert(2,5);
    l.insert(3,50);
    l.insert(4,598);
    l.insert(5,4);
    l.display();
    
    cout<<"\n Enter the element to search"<<endl;
    cin>>x;
    value = l.search(x);
    if(value==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"The element "<<value<<" was found"<<endl;
    }

    return 0;


}