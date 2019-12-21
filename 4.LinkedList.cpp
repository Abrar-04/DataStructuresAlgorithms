#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class link
{
    private:
    Node *first;
    public:
    link(){first=NULL;};
    link(int a[],int n);
    ~link();

    void insert(int index,int x);
    int Delete(int index);
    int length();
    int search(int key);
    void display();
};



link::link(int a[],int n)
{
    Node *t,*last;
    int i;
    first = new Node;
    first->data=a[0];
    first->next=NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void link::insert(int index, int x)
{
    Node *t,*p=first;
    int i=0;

    // checking if index is valid


    if(index<0 || index>length())return;

    // insertion at the beginning

    if(index == 0)
    {
        t = new Node;
        t->data=x;
        t->next=first;
        first = t;

    }
    // insertion at the end or anywhere else

    else
    {
        for(i=0;i<index-1;i++)
        {
            p=p->next;

        }
        t=new Node;
        t->next=NULL;
        t->data=x;
        t->next=p->next;
        p->next=t;


    }
}

int link::Delete(int index)
{
    Node *q,*p=first;
    int i;
    int x=-1;
    if(index<1 || index>length())return -1;

    // deletion at beginning

    if(index==0)
    {
        p=first;
        x=first->data;
        first=first->next;
        delete p;
    }

    // deletion anywhere else
    else
    {
        for(i=0;i<index-1;i++){q=p;p=p->next;}
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;

}

int link::search(int key)
{
    int x=-1;

    Node *p = first;
    while(p)
    {
        if(p->data==key)
        {
            x = p->data;
            break;
        }
        p=p->next;
    }
    return x;
}

int link::length()
{
    Node *p = first;
    int len=0;
    int i;
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

    int A[]={1,2,3,4,5};
    int x,value;

    link l(A,5);


    l.display();

    l.insert(3,10);

    l.display();

    l.Delete(4);

    l.display();

    cout<< "\n enter the element to search"<<endl;
    cin>>x;
    value = l.search(x);

    if(value == -1)
    {
        cout<<" Element not found "<<endl;
    }else
    {
        cout << "The element " <<value<< " was found "<<endl;
    }




    return 0;

}