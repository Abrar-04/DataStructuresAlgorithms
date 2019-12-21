#include<iostream>
using namespace std;
template<class t>
class cqueue
{
private:
t *q;
int capacity,front,rear,count;
public:
cqueue(int c);
~cqueue();
bool isempty();
bool isfull();
void insert( t element);
t remove();
void display();
};
template<class t>
cqueue<t>::cqueue(int c)
{
capacity=c;
front=0;
rear=0;
count=0;
q=new t[capacity];
}
template<class t>
cqueue<t>::~cqueue()
{
delete[] q;
}
template<class t>
bool cqueue<t>::isempty()
{
if(front==rear)
return true;
else
return false;
}
template<class t>
bool cqueue<t>::isfull()
{
if((rear+1)%capacity==front)
return true;
else
return false;
}
template<class t>
void cqueue<t>::insert(t element)
{
if(isfull())
cout<<"queue is full you can't add";
else
{
rear=(rear+1)%capacity;
q[rear]=element;
count++;
}
}
template<class t>
t cqueue<t>::remove()
{
if(isempty())
cout<<"\nSorry the queue is empty!";
else
{
front=(front+1)%capacity;
count--;
return q[front];
}
}
template<class t>
void cqueue<t>::display()
{
if(isempty())
cout<<"\nSorry the queue is empty!";
else
{
cout<<"\nQueue elements are : ";
int f=front;
for(int i=0;i<count;i++)
{
f=(f+1)%capacity;
cout<<q[f]<<" ";
}
}
}
int main()
{
cqueue<int> cq(5);
cq.insert(10);
cq.insert(20);
cq.insert(30);
cq.insert(40);
cq.insert(50);
cq.display();
int x=cq.remove();
cout<< "removed element is"<<x;
int y=cq.remove();
cout<<"second removed element is"<<y;
cq.display();
cq.insert(50);
cq.insert(60);
cq.display();
}