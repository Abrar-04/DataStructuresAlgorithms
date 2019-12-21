#include<iostream>
using namespace std;
template<class t>
class circular;
template<class t>
class node
{
friend class circular<t>;
private:
t data;
node<t> *next;
};
template<class t>
class circular
{
private:
node<t> *first;
int len;
public:
circular();
// ~circular();
bool isempty();
int length();
void insert(t element, int pos);
t remove(int pos);
void display();
};
//constructor
template<class t>
circular<t>::circular()
{
first=NULL;
len=0;
}
// isempty
template<class t>
bool circular<t>::isempty()
{
if(first==NULL||len==0)
return true;
else
return false;
}
template<class t>
int circular<t>::length()
{
return len;
}
template<class t>
void circular<t>::display()
{
node<t> *temp=first;
for(int i=1;i<=len;i++)
{
cout<<temp->data<<"-->";
temp=temp->next;
}
}
template<class t>
void circular<t>::insert(t element,int pos)
{
node<t> *temp=new node<t>;
temp->data=element;
if(isempty()) // inserting if CCL is Empty Case
{
first=temp;
temp->next=first;
}
else if(pos==1) // Inserting at begining of the CCL
{
temp->next=first;
node<t> *p=first;
for(int i=1;i<len;i++)
{
p=p->next;
}
first=temp;
p->next=temp;
}
else //Inserting Middle or at End of CCL
{
node<t> *p=first;
for(int i=1;i<pos-1;i++)
{
p=p->next;
}
temp->next=p->next;
p->next=temp;
}
len++; // For Any insertion len increment by 1
}
template<class t>
t circular<t>::remove(int pos)
{
node<t> *temp=first;
t x;
if(len==1) //Deleting if CCL is having only one node
{
first=NULL;
t x = temp->data;
delete temp;
}
else if (pos==1) //Deleting first node of CCL
{
node<t> *p=first;
for(int i=1;i<len;i++)
{
p=p->next;
}
first=first->next;
p->next=first;
x=temp->data;
delete temp;
}
else // Deleting any node of CCL
{
node<t> *p=first;
for(int i=1;i<pos-1;i++)
{
p=p->next;
}
temp=p->next;
p->next=temp->next;
x=temp->data;
delete temp;
}
len--; // for any deletion len reduce by 1
return x; // deleted node data
}
main()
{
circular<int>c;
c.insert(10,1);
c.insert(20,2);
c.insert(30,3);
c.insert(40,4);
c.insert(5,1);
c.insert(50,5);
cout<<"\n list of elements in CCL are \n";
c.display();
int x=c.remove(3);
cout<<"\n deleted elements is"<<x;
cout<<"\n now list is\n";
c.display();
cout<<"\n total length is "<<c.length();
}