#ifndef CLASSES                 //template file so saved as a header file
#define CLASSES

#include <string>               //included necc. STLs so header file can stand alone (good practice)
#include <iterator>                 
                                //'using namespace std' or any using declarations not good for header files

template <typename T>    
class SimpleList                   //abstract base class
{                                 //defines the simply linked list to implement the stacks or queues
    private:
        std::string listName;
        class node {             //Building blocks of SimpleList: The node reps. each memory slot of stack or queue.
            public:
                T info;
                node* next;
        };
        node* rear;          
        node* front;
           
    public:
        T removed;     
        SimpleList(std::string name)
        {
            rear = NULL;         //set pointers called 'rear' and 'front' to NULL. 
            front = NULL;        //Note: NOT dummy nodes.
            listName = name;
        }          
        std::string retrieve()
        {
            return listName;
        }
        virtual void push(T const&) = 0;   //A pure virtual function implicitly makes the class it is defined for abstract
        virtual T pop() = 0;               //Abstract classes cannot be instantiated. 
        bool is_empty();                   //Derived classes need to override/implement all inherited pure virtual functions.
    
    protected:
        void insert_start(T const&);    //push for stack
        void insert_end(T const&);      //push for queue
        T remove_start();               //pop for both             
};

template <typename T> 
class Stack : public SimpleList<T>      //stack is derived class of SimpleList 
{
    public:               
        Stack(std::string name):SimpleList<T>(name){}    //constructor
        void push(T const&);   //push takes in an int, double, or string
        T pop();               //pop returns an int, double, or string
};

template <typename T> 
class Queue : public SimpleList<T>    //Queue is derived class of SimpleList. Same as Stack except push function differs.
{
    public:
        Queue(std::string name):SimpleList<T>(name){}
        void push(T const&);
        T pop();
};



template <typename T>
void Stack<T>::push(T const&data)
{
    this->insert_start(data);      //insert at the start bc Stack is LIFO
}

template <typename T>
T Stack<T>::pop()
{
    return this->remove_start();
}

template <typename T>
void Queue<T>::push(T const&data)
{
    this->insert_end(data);        //insert at the end bc Queue is FIFO
}

template <typename T>
T Queue<T>::pop()
{
    return this->remove_start(); //pop same for both because it just removes start and makes second-to-front node the new front
}

template <typename T>
void SimpleList<T>::insert_start(T const&data)
{
    node* temp = new node;    //create a new temporary node. -Like a new book.
    temp->info = data;        //put the input data in temp. 
    temp->next = NULL;        //after temp there's nothing

    if(front == NULL)
    {
        rear = temp;       //if stack or q is empty, first node falls to the rear. 
    }                      //-Like dropping books into a open top box, the first book lands at the bottom of the box
    else
    {
        temp -> next = front;  //places temp before front. -Like dropping a book on top of an existing stack
    }

    front = temp;       //-The book you just just dropped is now the top (or the front) of the stack
}

template <typename T>
void SimpleList<T>::insert_end(T const&data)
{
    node* temp = new node;   
    temp->info = data;
    temp->next = NULL;

    if(front == NULL)
    {
        front = temp;  //-Like pushing balls into a vertical pipe from underneath. Both ends of the pipe are open. 
    }                  //The first ball in is the top (or front). Any balls afterwards will go under it.
    else 
    {
        rear->next = temp; //places temp behind rear. -Like pushing a ball under the line of existing balls
    }

    rear = temp;  //-The ball you just pushed is now on the bottom (or rear) of the pipe
}

template <typename T>
T SimpleList<T> ::remove_start()  //like taking a book off the top of the stack. Same thinking if it was a ball and queue.
{
    node* temp = new node;

    if(front != NULL)       
    {     
        temp = front;       
        front = front->next;    //the book that was under it is now the top of the stack
        removed = temp->info;
        delete temp;

        return removed;   //NOTE: if stack or q is empty, the if statement won't run and 'return' will hold 
    }                     //the last popped value before it became empty. Recall that 'return' is not a node, 
                          //it's just an int, double, or string variable. Workaround is to use is_empty 
}                         //to check so it just never pops when empty. This avoids the use pointers in this class.

template <typename T> 
bool SimpleList<T>::is_empty()   //must be used to check if stack or q is empty before attempting to pop
{
    if(front == NULL)
    {
        return true;
    }
    else
    {
        return false; 
    }
}
 
template<class InputIterator, class T>
InputIterator search (InputIterator first, InputIterator last, const T& val)  //search function. 
{                                                                             //Use with the input to last being prev(list.end) .
                                 //list.end() points to nothing, it returns a theoretical iterator 1 past the true end of the list.
                                                 //so prev(list.end) returns the true end of the list 

    for(first; (first!=(last)) ;first++)  //search from [first, true end)
    {
        if (((*first)->retrieve())==(val))
        {
            return (first);        //if find a match return iterator to it
        }         
    } 
    return (last); //if it can't find a match after going through [first, true end) 
                   //then it returns the true end which is initialized to "no match" in main.cpp                    
} 
                   //NOTE: if the list was empty then first = last and the for statement won't run so 
                   //the block just returns last which will always be "no match". 
                   //this way can never return a NULL iterator which could cause segmentation faults. Also avoids having to make the class return a pointer to an iterator.
#endif 

