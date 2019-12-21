#include<iostream.h>
template<class T>
class Queue
{
private:
int front,rear;
T *queue;
int maxsize;
public:
Queue(int maxqueuesize)
{
front=0;
rear=-1;
maxsize=maxqueuesize;
queue=new T[maxsize];
}
~Queue()
{
delete[] queue;
}
int isempty();
int isfull();
void insert();
void deletion();
void atfront();
void atrear();
void display();
};
template<class T>
int Queue<T>::isempty()
{
if((front==0&&rear==-1)||(front==rear+1))
return 1;
else
return 0;
}
template<class T>
int Queue<T>::isfull()
{
if(rear==maxsize-1)
return 1;
else
return 0;
}
template<class T>
void Queue<T>::atfront()
{
if(isempty())
cout<<"\n Sorry the queue is empty!";
else
cout<<"\n Front element of the queue is : "<<queue[front]<<"\n";
}
template<class T>
void Queue<T>::atrear()
{
if(isempty())
cout<<"\n Sorry the queue is empty!";
else
cout<<"\n Rear element of the queue is : "<<queue[rear]<<"\n";
}
template<class T>
void Queue<T>::insert()
{
T ele;
if(isfull())
cout<<"\n Sorry the queue is full!";
else
{
cout<<"\n Enter the element to insert : ";
cin>>ele;
queue[++rear]=ele;
}
}
template<class T>
void Queue<T>::deletion()
{
if(isempty())
cout<<"\n Sorry the queue is empty!";
else
cout<<"\n Deleted element of the queue is : "<<queue[front++];
}
template<class T>
void Queue<T>::display()
{
if(isempty())
cout<<"\n Sorry the queue is empty!";
else
{
cout<<"\n Queue elements: \n";
for(int i=front;i<=rear;i++)
{
cout<<"\t"<<queue[i]<<"\n";
}
}
}
int main()
{
Queue<int> q(5);
q.insert();
q.insert();
q.insert();
q.insert();
q.insert();
q.atfront();
q.atrear();
q.display();
q.deletion();
q.deletion();
q.atfront();
q.atrear();
q.display();
}