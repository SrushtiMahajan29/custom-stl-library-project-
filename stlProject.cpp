#include<iostream>
using namespace std;

template<class T>
struct node{
    T data;
    struct node* next;
    struct node* prev;
};

template<class T>
class SinglyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor\n";
    first = NULL;
    Count = 0;
}
template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Count++;
}
template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = first;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct node<T> * temp = first;

    cout<<"Elements of the linked list are : \n";
    
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}

template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        first = first->next;
        delete temp;
    }
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}
template<class T>
void SinglyLL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }
     
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}
template<class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }
     
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        struct node<T> * targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;

        Count--;
    }
}




// Singly circular

template<class T>
class SinglyCLL{
    private:
        struct node<T> * first;//We cant initialize here bcoz memory is not allocated here Therefore we need constructor
        struct node<T> * last;
        int count;
    
        
    public:
        SinglyCLL();
        void insertFirst(T no);
        void insertLast(T no);
        void insertAtPos(T no,int pos);
        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int pos);
        void display();
        int countNode();
};
template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor\n\n";
    first=NULL;
    last=NULL;
    count=0;
}
template<class T>
void SinglyCLL<T>::insertFirst(T no)
{
    struct node<T> * newn=NULL;
    newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL && last==NULL)// || count==0 
    {
        first=newn;
        last=newn;
    }
    else
    {
        newn->next=first;
        first=newn;
    }
    last->next=first;

    count++;

}

template <class T>
void SinglyCLL<T>::insertLast(T no)
{
    struct node<T> * newn =NULL;
    newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL&& last==NULL)// || count==0 
    {
        first=newn;
        last=newn;
        last->next=first;
    }
    else
    {
        last->next=newn;
        last=newn;
        last->next=first;
    }
    count++;

}

template <class T>
void SinglyCLL<T>::deleteFirst()
{
    if(first==NULL && last ==NULL)//               count==0
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(first->next==first && last->next==first)//        count==1
    {
        delete first;
        first=NULL;
        last=NULL;   
    }
    else                                //count>1
    {
        first=first->next;
        delete last->next;
        last->next=first;
    }
    count--;
}

template<class T>
void SinglyCLL<T>::deleteLast()
{ 
    if(first==NULL && last ==NULL)//               count==0
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(first->next==first && last->next==first)//        count==1
    {
        delete first;
        first=NULL;
        last=NULL;   
    }
    else                                //count>1
    {
        struct node<T> * temp=first;
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        
        delete last;
        last=temp;
        last->next=first;
    }
    count--;
}

template <class T>
void SinglyCLL<T>:: display()
{
    cout<<"Elements of linked list are : \n";
    do{
        cout<<"| "<<first->data<<" |->";
        first=first->next;
    }
    while(first!=last->next);
    cout<<"NULL\n";
}
template <class T>
int SinglyCLL<T>::countNode()
{
    return count;    
}

template <class T>
void SinglyCLL<T>::insertAtPos(T no,int ipos)
{
    struct node <T> * temp=first;
    if(ipos<1 || ipos>count+1)// || count==0 
    {
        cout<<"Invalid position";
        return;
    }
    else if(ipos==1)
    {
        insertFirst(no);
    }
    else if(ipos==count+1)
    {
        insertLast(no);
    }
    else
    {
        struct node<T> * newn=NULL;
        newn=new struct node<T>;

        newn->data=no;
        newn->next=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        count++;
    }
}

template<class T>
void SinglyCLL<T>::deleteAtPos(int ipos)
{

    if(ipos<1 || ipos>count)// || count==0 
    {
        cout<<"Invalid position";
        return;
    }
    else if(ipos==1)
    {
        deleteFirst();
    }
    else if(ipos==count)
    {
        deleteLast();
    }
    else
    {
        struct node<T> * temp=first;
        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        struct node<T> * targatedNode=temp->next;
        temp->next=temp->next->next;
        delete targatedNode;
        count--;
    }
}


// DOubly Linear
template <class T>
class DoublyLL{
    private:
        struct node<T> * first;//We cant initialize here bcoz memory is not allocated here Therefore we need constructor
        int count;

    public:
        DoublyLL();
        void insertFirst(T no);
        void insertLast(T no);
        void insertAtPos(T no,int pos);
        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int pos);
        void display();
        int countNode();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside constructor\n\n";
    first=NULL;
    count=0;
}

template<class T>
void DoublyLL<T>::insertFirst(T no)
{
    struct node<T> * newn=NULL;
    newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(first==NULL)// || count==0 
    {
        first=newn;
    }
    else
    {
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    count++;

}

template <class T>
void DoublyLL<T>::insertLast(T no)
{
    struct node<T> * newn =NULL;
    newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL)// || count==0 
    {
        first=newn;
    }
    else
    {
        struct node<T> * temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
    count++;
}

template <class T>
void DoublyLL<T>::deleteFirst()
{
    if(first==NULL)//               count==0
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(first->next==NULL && first->prev==NULL)  //        count==1
    {
        delete first;
        first=NULL;
    }
    else                                //count>1
    {
        first=first->next;
        delete first->prev;
        first->prev=NULL;
    }
    count--;
}

template <class T>
void DoublyLL<T>::deleteLast()
{
    if(first==NULL)//               count==0
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(first->next==NULL && first->prev==NULL)//        count==1
    {
        delete first;
        first=NULL; 
    }
    else                                //count>1
    {
        struct node<T> * temp=first;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        
        delete temp->next;
        temp->next=NULL;
    }
    count--;
}

template <class T>
void DoublyLL<T>:: display()
{
    struct node<T> * temp=first;
    cout<<"Elements of linked list are : \n";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL\n";
    cout<<"\n Number of elements are: "<<count<<"\n";
}

template <class T>
int DoublyLL<T>::countNode()
{
    return count;    
}


template <class T>
void DoublyLL<T>::insertAtPos(T no,int ipos)
{
    struct node<T>* temp=first;
    if(ipos<1 || ipos>count+1)// || count==0 
    {
        cout<<"Invalid position";
        return;
    }
    else if(ipos==1)
    {
        insertFirst(no);
    }
    else if(ipos==count+1)
    {
        insertLast(no);
    }
    else
    {
        struct node<T>* newn=NULL;
        newn=new struct node<T>;

        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;

        count++;
    }
}

template <class T>
void DoublyLL<T>::deleteAtPos(int ipos)
{

    if(ipos<1 || ipos>count)// || count==0 
    {
        cout<<"Invalid position";
        return;
    }
    else if(ipos==1)
    {
        deleteFirst();
    }
    else if(ipos==count)
    {
        deleteLast();
    }
    else
    {
        struct node<T> * temp=first;
        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        struct node<T> * targatedNode=temp->next;
        temp->next=temp->next->next;
        delete targatedNode;
        temp->next->prev=temp;
        count--;
    }
}



// Doubly circular


template <class T>
class DoublyCLL{
    private:
        struct node<T> * first;//We cant initialize here bcoz memory is not allocated here Therefore we need constructor
        struct node<T> * last;
        int count;
    
        
    public:
        DoublyCLL();
        void insertFirst(T no);
        void insertLast(T no);
        void insertAtPos(T no,int pos);
        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int pos);
        void display();
        int countNode();
};


template <class T>
DoublyCLL<T> ::DoublyCLL()
{
    cout<<"Inside constructor\n\n";
    first=NULL;
    last=NULL;
    count=0;
}

template <class T>
void DoublyCLL<T>::insertFirst(T no)
{
    struct node<T> * newn=NULL;
    newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL)// || count==0 
    {
        first=newn;
        last=newn;
    }
    else
    {
        newn->next=first;
        first->prev=newn;
        first=newn;
    }
    first->prev=last;
    last->next=first;
    count++;

}


template <class T>
void DoublyCLL<T>::insertLast(T no)
{
    struct node<T> * newn =NULL;
    newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL)// || count==0 
    {
        first=newn;
        last=newn;
    }
    else
    {
        newn->prev=last;
        last->next=newn;
        last=newn;

    }
    first->prev=last;
    last->next=first;
    count++;
}

template <class T>
void DoublyCLL<T>::deleteFirst()
{
    if(first==NULL && last==NULL)//               count==0
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(first==last)//        count==1
    {
        delete first;
        first=NULL;
        last=NULL;
    }
    else                                //count>1
    {
        first=first->next;
        delete last->next;
        first->prev=last;
        last->prev=first;
    }
    count--;
}
// void DoublyCLL::deleteLast()
// {
//     if(first==NULL && last==NULL)//               count==0
//     {
//         cout<<"Linked list is empty\n";
//         return;
//     }
//     else if(first->next==first && last->next==first)//        count==1
//     {
//         cout<<"HII1";
//         delete first;
//         first=NULL; 
//         last=NULL;
//     }
//     else                                //count>1
//     {

//         last = last->prev;
// last->next = first; // Update the next pointer of the new last node
// first->prev = last; // Update the prev pointer of the first node
// delete last->next;  // Delete the old last node
 
//     }
//     count--;
// }


template <class T>
void DoublyCLL<T>::deleteLast()
{
    if (first == NULL && last == NULL)
    {
        cout << "Linked list is empty\n";
        return;
    }
    else if (first->next == first && last->next == first)
    {
        cout << "HII1";
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first; // Update the next pointer of the new last node
        first->prev = last; // Update the prev pointer of the first node
    }
    count--;
}


template <class T>
void DoublyCLL<T>:: display()
{
    struct node<T> * temp=first;
    cout<<"Elements of linked list are : \n";
   
    do{
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }while(temp!=last->next);
    cout<<"NULL\n";
  
}

template <class T>
int DoublyCLL<T>::countNode()
{
    return count;    
}

template <class T>
void DoublyCLL<T>::insertAtPos(T no,int ipos)
{
    struct node<T> * temp=first;
    if(ipos<1 || ipos>count+1)// || count==0 
    {
        cout<<"Invalid position";
        return;
    }
    else if(ipos==1)
    {
        insertFirst(no);
    }
    else if(ipos==count+1)
    {
        insertLast(no);
    }
    else
    {
        struct node<T> * newn=NULL;
        newn=new struct node<T>;

        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;
        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;

        temp->next=newn;
        newn->prev=temp;

        count++;
    }
}

template <class T>
void DoublyCLL<T>::deleteAtPos(int ipos)
{

    if(ipos<1 || ipos>count)// || count==0 
    {
        cout<<"Invalid position";
        return;
    }
    else if(ipos==1)
    {
        deleteFirst();
    }
    else if(ipos==count)
    {
        deleteLast();
    }
    else
    {
        struct node<T> * temp=first;
        for(int i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        // PNODE targatedNode=temp->next;
        // temp->next=temp->next->next;
        // delete targatedNode;
        // temp->next->prev=temp;
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        count--;
    }
}


// Stack
template <class T>
class Stack{
    private:
        struct node<T> * first;//We cant initialize here bcoz memory is not allocated here Therefore we need constructor
        int count;    
        
    public:
        Stack();
        void push(T no);
        int pop();
        void display();
};

template <class T>
Stack<T>::Stack()
{
    cout<<"Inside constructor\n\n";
    first=NULL;
    count=0;
}

template <class T>
void Stack<T>::push(T no)
{
    struct node<T> * newn =NULL;
    newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL)// || count==0 
    {
        first=newn;
    }
    else
    {
        newn->next=first;
        first=newn;
    }
    count++;
}

template <class T>
int Stack<T>::pop()
{
    int value=0;       
    struct node<T> * temp=first;
    if(first==NULL)//               count==0
    {
        cout<<"Queue is empty\n";
        return 0;
    }
    else                                //count>1
    {
        value=(first)->data; 
        first=first->next;
        delete temp;
    }
    count--;
}

template <class T>
void Stack<T>::display()
{
    struct node<T> * temp=first;       
    cout<<"Elements of stack are : \n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    cout<<"NULL\n";
}


// Queue

template<class T>
class Queue{
    private:
        struct node<T> * first;//We cant initialize here bcoz memory is not allocated here Therefore we need constructor
        int count;    
        
    public:
        Queue();
        void Enqueue(T no);
        int Dequeue();
        void display();
};


template<class T>
Queue<T>::Queue()
{
    cout<<"Inside constructor\n\n";
    first=NULL;
    count=0;
}

template<class T>
void Queue<T>::Enqueue(T no)
{
    struct node<T> * newn =NULL;
    newn=new struct node<T>;

    newn->data=no;
    newn->next=NULL;

    if(first==NULL)// || count==0 
    {
        first=newn;
    }
    else
    {
        struct node<T> * temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;

    }
    count++;
}

template<class T>
int Queue<T>::Dequeue()
{
    int value=0;       
    struct node<T> * temp=first;
    if(first==NULL)//               count==0
    {
        cout<<"Queue is empty\n";
        return 0;
    }
    else                                //count>1
    {
        value=(first)->data; 
        first=first->next;
        delete temp;
    }
    count--;
}

template<class T>
void Queue<T>::display()
{
    struct node<T> * temp=first;       
    cout<<"Elements of queue are : \n";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}


int main()
{
    int ch=0,exit=0;

    cout<<"\tWelcome to my Linked list library\n\n";
    cout<<"\tWhich Data structure you want to implement?\n\n";
    cout<<"1.Singly linear Linked List\n2.Singly Circular Linked List\n3.Doubly Linear Linked List\n4.Doubly Circular Linked List\n5.Stack\n6.Queue\n";
    cout<<"\tEnter your choice: ";
    cin>>ch;

    while(exit==0)
    {
            int choice=0;
        switch(ch)
        {
            case 1:{
                        cout<<"\tWhich data-type?\n1.int\n2.float\n3.double\n4.char\n\n";
                        cin>>choice;
                        if(choice==1)
                        {
                            int op=0,ctn=1;
                            SinglyLL <int>iobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        iobj.InsertFirst(no);
                                        break;}
                                case 2:{int no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        iobj.InsertLast(no);
                                        break;
                                }
                                case 3:{
                                    iobj.DeleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    iobj.DeleteLast();
                                        break;
                                }
                                case 5:{
                                    int no=0,pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        iobj.InsertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        iobj.DeleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        iobj.Display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                        // FLoat sll
                        else if(choice==2)
                        {
                            int op=0,ctn=1;
                            SinglyLL <float> fobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{float no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        fobj.InsertFirst(no);
                                        break;}
                                case 2:{float no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        fobj.InsertLast(no);
                                        break;
                                }
                                case 3:{
                                        fobj.DeleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    fobj.DeleteLast();
                                        break;
                                }
                                case 5:{
                                    float no=0; 
                                    int pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        fobj.InsertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        fobj.DeleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        fobj.Display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                    else if(choice==3)
                    {       int op=0,ctn=1;
                            SinglyLL <double> dobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{double no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        dobj.InsertFirst(no);
                                        break;}
                                case 2:{double no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        dobj.InsertLast(no);
                                        break;
                                }
                                case 3:{
                                        dobj.DeleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    dobj.DeleteLast();
                                        break;
                                }
                                case 5:{
                                    double no=0;
                                    int pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        dobj.InsertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        dobj.DeleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        dobj.Display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }

                    }
                    else if(choice==4)
                    {
                        int op=0,ctn=1;
                        SinglyLL <char> cobj;

                        while(ctn==1)
                        {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{char no=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cobj.InsertFirst(no);
                                        break;}
                                case 2:{char no=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cobj.InsertLast(no);
                                        break;
                                }
                                case 3:{
                                        cobj.DeleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    cobj.DeleteLast();
                                        break;
                                }
                                case 5:{
                                    char no=0;
                                    int pos=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        cobj.InsertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        cobj.DeleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        cobj.Display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                    }
                    else{
                       cout<<"Enter valid dtype";
                    }
                break;
            }
            case 2:{
                 cout<<"\tWhich data-type?\n1.int\n2.float\n3.double\n4.char\n\n";
                        cin>>choice;
                        if(choice==1)
                        {
                            int op=0,ctn=1;
                            SinglyCLL <int> iobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        iobj.insertFirst(no);
                                        break;}
                                case 2:{int no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        iobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                    iobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    iobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    int no=0,pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        iobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        iobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        iobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                        // FLoat sll
                        else if(choice==2)
                        {
                            int op=0,ctn=1;
                            SinglyCLL <float> fobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{float no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        fobj.insertFirst(no);
                                        break;}
                                case 2:{float no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        fobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                        fobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    fobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    float no=0; 
                                    int pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        fobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        fobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        fobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                    else if(choice==3)
                    {       int op=0,ctn=1;
                            SinglyCLL <double> dobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{double no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        dobj.insertFirst(no);
                                        break;}
                                case 2:{double no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        dobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                        dobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    dobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    double no=0;
                                    int pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        dobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        dobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        dobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }

                    }
                    else if(choice==4)
                    {
                        int op=0,ctn=1;
                        SinglyCLL <char> cobj;

                        while(ctn==1)
                        {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{char no=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cobj.insertFirst(no);
                                        break;}
                                case 2:{char no=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                        cobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    cobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    char no=0;
                                    int pos=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        cobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        cobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        cobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                    }
                    else{
                       cout<<"Enter valid dtype";
                    }
                
                break;}
            case 3: {
                 cout<<"\tWhich data-type?\n1.int\n2.float\n3.double\n4.char\n\n";
                        cin>>choice;
                        if(choice==1)
                        {
                            int op=0,ctn=1;
                            DoublyLL <int>iobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        iobj.insertFirst(no);
                                        break;}
                                case 2:{int no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        iobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                    iobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    iobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    int no=0,pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        iobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        iobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        iobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                        // FLoat sll
                        else if(choice==2)
                        {
                            int op=0,ctn=1;
                            DoublyLL <float> fobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{float no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        fobj.insertFirst(no);
                                        break;}
                                case 2:{float no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        fobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                        fobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    fobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    float no=0; 
                                    int pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        fobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        fobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        fobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                    else if(choice==3)
                    {       int op=0,ctn=1;
                            DoublyLL <double> dobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{double no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        dobj.insertFirst(no);
                                        break;}
                                case 2:{double no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        dobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                        dobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    dobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    double no=0;
                                    int pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        dobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        dobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        dobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }

                    }
                    else if(choice==4)
                    {
                        int op=0,ctn=1;
                        DoublyLL <char> cobj;

                        while(ctn==1)
                        {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{char no=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cobj.insertFirst(no);
                                        break;}
                                case 2:{char no=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                        cobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    cobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    char no=0;
                                    int pos=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        cobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        cobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        cobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                    }
                    else{
                       cout<<"Enter valid dtype";
                    }
                
                break;}
            case 4: {
                 cout<<"\tWhich data-type?\n1.int\n2.float\n3.double\n4.char\n\n";
                        cin>>choice;
                        if(choice==1)
                        {
                            int op=0,ctn=1;
                            DoublyCLL <int>iobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        iobj.insertFirst(no);
                                        break;}
                                case 2:{int no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        iobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                    iobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    iobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    int no=0,pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        iobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        iobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        iobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                        // FLoat sll
                        else if(choice==2)
                        {
                            int op=0,ctn=1;
                            DoublyCLL <float> fobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{float no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        fobj.insertFirst(no);
                                        break;}
                                case 2:{float no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        fobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                        fobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    fobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    float no=0; 
                                    int pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        fobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        fobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        fobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                    else if(choice==3)
                    {       int op=0,ctn=1;
                            DoublyCLL <double> dobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{double no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        dobj.insertFirst(no);
                                        break;}
                                case 2:{double no=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        dobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                        dobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    dobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    double no=0;
                                    int pos=0;
                                        cout<<"Enter element to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        dobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        dobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        dobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }

                    }
                    else if(choice==4)
                    {
                        int op=0,ctn=1;
                        DoublyCLL <char> cobj;

                        while(ctn==1)
                        {
                            cout<<"Which function? ";
                            cout<<"\n1.insert first\n2.insert last\n3.delete first\n4.delete last\n5. insert at pos\n6.delete at pos\n7.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{char no=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cobj.insertFirst(no);
                                        break;}
                                case 2:{char no=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cobj.insertLast(no);
                                        break;
                                }
                                case 3:{
                                        cobj.deleteFirst();
                                        break;
                                }
                                case 4:
                                {
                                    cobj.deleteLast();
                                        break;
                                }
                                case 5:{
                                    char no=0;
                                    int pos=0;
                                        cout<<"Enter character to insert: ";
                                        cin>>no;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        cobj.insertAtPos(no,pos);
                                        break;
                                }
                                case 6:{
                                    int pos=0;
                                        cout<<"Enter position";
                                        cin>>pos;
                                        cobj.deleteAtPos(pos);
                                        break;
                                }
                                case 7:{
                                        cobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                    }
                    else{
                       cout<<"Enter valid dtype";
                    }
                
                break;}
            case 5:{
                 cout<<"\tWhich data-type?\n1.int\n2.float\n3.double\n4.char\n\n";
                        cin>>choice;
                        if(choice==1)
                        {
                            int op=0,ctn=1;
                            Stack <int>iobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.Push\n2.Pop\n3.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to Push: ";
                                        cin>>no;
                                        iobj.push(no);
                                        break;
                                        }
                                case 2:{
                                        iobj.pop();
                                        break;
                                }            
                                case 3:{
                                        iobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                        // FLoat sll
                        else if(choice==2)
                        {
                            int op=0,ctn=1;
                            Stack <float>fobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.Push\n2.Pop\n3.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to Push: ";
                                        cin>>no;
                                        fobj.push(no);
                                        break;
                                        }
                                case 2:{
                                        fobj.pop();
                                        break;
                                }            
                                case 3:{
                                        fobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                    else if(choice==3)
                    {       int op=0,ctn=1;
                            Stack <double>dobj;
                        
                            while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.Push\n2.Pop\n3.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to Push: ";
                                        cin>>no;
                                        dobj.push(no);
                                        break;
                                        }
                                case 2:{
                                        dobj.pop();
                                        break;
                                }            
                                case 3:{
                                        dobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                    }
                    else if(choice==4)
                    {
                        int op=0,ctn=1;
                        Stack <char> cobj;

                        while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.Push\n2.Pop\n3.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to Push: ";
                                        cin>>no;
                                        cobj.push(no);
                                        break;
                                        }
                                case 2:{
                                        cobj.pop();
                                        break;
                                }            
                                case 3:{
                                        cobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                    }
                    else{
                       cout<<"Enter valid dtype";
                    }
                
                break;
                }
            case 6:{
                 cout<<"\tWhich data-type?\n1.int\n2.float\n3.double\n4.char\n\n";
                        cin>>choice;
                        if(choice==1)
                        {
                           int op=0,ctn=1;
                            Queue <int>iobj;
                        
                           while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.Enqueue\n2.Dequeue\n3.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{
                                        int no=0;
                                        cout<<"Enter element to Enqueue: ";
                                        cin>>no;
                                        iobj.Enqueue(no);
                                        break;
                                        }
                                case 2:{
                                        iobj.Dequeue();
                                        break;
                                }            
                                case 3:{
                                        iobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                        // FLoat sll
                        else if(choice==2)
                        {
                            int op=0,ctn=1;
                            Queue <float>fobj;
                        
                           while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.Enqueue\n2.Dequeue\n3.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to Enqueue: ";
                                        cin>>no;
                                        fobj.Enqueue(no);
                                        break;
                                        }
                                case 2:{
                                        fobj.Dequeue();
                                        break;
                                }            
                                case 3:{
                                        fobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                        }
                    else if(choice==3)
                    {       int op=0,ctn=1;
                            Queue <double>dobj;
                        
                           while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.Enqueue\n2.Dequeue\n3.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to Enqueue: ";
                                        cin>>no;
                                        dobj.Enqueue(no);
                                        break;
                                        }
                                case 2:{
                                        dobj.Dequeue();
                                        break;
                                }            
                                case 3:{
                                        dobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                    }
                    else if(choice==4)
                    {
                        int op=0,ctn=1;
                        Queue <char> cobj;

                        while(ctn==1)
                            {
                            cout<<"Which function? ";
                            cout<<"\n1.Enqueue\n2.Dequeue\n3.Display\n\n";
                            cin>>op;
                            switch(op)
                            {
                                case 1:{int no=0;
                                        cout<<"Enter element to Enqueue: ";
                                        cin>>no;
                                        cobj.Enqueue(no);
                                        break;
                                        }
                                case 2:{
                                        cobj.Dequeue();
                                        break;
                                }            
                                case 3:{
                                        cobj.display();
                                        break;
                                }
                                default:{cout<<"Enter valid option";
                                    break;}
                            }
                            cout<<"Want to continue?";
                            cin>>ctn;
                            }
                    }
                    else{
                       cout<<"Enter valid dtype";
                    }
                
                break;
                }
            
            default:
                cout<<"Invalid choice";
                break;
        }
        cout<<"Want to leave ?";
        cin>>exit;
    }
    return 0;
}