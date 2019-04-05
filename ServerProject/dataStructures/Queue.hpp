#ifndef SCRABBLE_QUEUE_HPP
#define SCRABBLE_QUEUE_HPP

// Libraries
#include <iostream>

#define SIZE 10
using namespace std;

template <class E>
class Queue{

    E *elements; //!< Array to store queue elements
    int max_cap; //!< Maximun capacity of the queue
    int top; //!< Current top of Queue
    int bottom; //!< Current bottom of Queue
    int size; //!< Size of the queue

public:

    //! Constructor
    //! @param size [in]: Maximun size of the queue
    Queue(int size = SIZE);

    //! Utility function to remove front element from the queue
    void dequeue();

    //! Utility function to add an element to the queue
    //! \param data [in]: Item to add.
    void enqueue(E data);

    //! Utility function to return the first element in the queue
    E peek();

    /* ---------------------------------------------
     *              GETTERS & SETTERS
     * ---------------------------------------------*/

    int getSize();

    bool isEmpty();

    bool isFuel();

};


// Methods implementation

template <class E>
Queue<E>::Queue(int size) {
    this->elements = new E(size);
    this->max_cap = size;
    this->top = 0;
    this->bottom = 0;
    this->size = 0;
}

template <class E>
void Queue<E>::dequeue() {

    // Check if queue is empty
    if(isEmpty()){
        std::cout<<"Queue Underflow"<<std::endl;
        exit(EXIT_FAILURE);
    }

    cout<<"Removing: "<<elements[top]<<endl;
    top = (top+1)%max_cap;
    size--;
}

template <class E>
void Queue<E>::enqueue(E data) {

    // Check if Queue is full
    if (isFuel()) {
        cout<<"Queue Overflow"<<endl;
        exit(EXIT_FAILURE);
    }

    cout<<"Inserting.. "<<data<<endl;

    bottom = (bottom+1)%max_cap;
    elements[bottom] = data;
    size++;
}

template <class E>
E Queue<E>::peek() {

    if(isEmpty()){
        std::cout<<"Queue Underflow"<<std::endl;
        exit(EXIT_FAILURE);
    }
    return elements[top];
}

template <class E>
int Queue<E>::getSize() { return size;}

template <class E>
bool Queue<E>::isEmpty() {
    return getSize()==0;
}

template <class E>
bool Queue<E>::isFuel() {
    return getSize()==max_cap;
}

#endif