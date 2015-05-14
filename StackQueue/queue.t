/*
queue.t
12-2-13
Trevor Richardson

Define and implement the queue template class.
Designed to work with in2post as a linked list.

*/

#ifndef QUEUE_T
#define QUEUE_T

#include <iostream>

namespace fsu {

  template < typename T >
  class Queue
  {
  public:
    Queue(); // default constructor
    Queue(const Queue&); // copy constructor
    ~Queue(); // destructor
    Queue& operator = (const Queue&); // assignment operator
    // Queue < T > API
    void Push(const T& t); // push t onto queue
    T Pop(); // pop queue and return removed element; error if queue is empty
    T& Front(); // return front element of queue; error if queue is empty
    const T& Front() const; // const version
    size_t Size() const; // return number of elements in queue
    bool Empty() const; // return 1 if queue is empty, 0 if not empty
    void Clear(); // make the queue empty
    void Display(std::ostream& os, char ofc = '\0') const; // output contents through os
  private:
    class Link
    {
      Link(const T& t) : element_(t), nextLink_(0) {}
      T element_;
      Link * nextLink_;
      friend class Queue<T>;
    };
    Link * firstLink_;
    Link * lastLink_;
  };

  template < typename T >
  Queue<T>::Queue()
    : firstLink_(0), lastLink_(0)
  {}

  template < typename T >
  Queue<T>::Queue(const Queue& q1)
    : firstLink_(0), lastLink_(0)
  {
    if (q1.Empty())
      return;
    Queue<T>::Link* currentLink = q1.firstLink_;
    T data = currentLink->element_;
    Queue<T>::Link* newLink = new Link(data);
    firstLink_ = lastLink_ = newLink;
    currentLink = currentLink->nextLink_;
    while (currentLink != 0)
    {
      T data = currentLink->element_;
      Queue<T>::Link* newLink = new Link(data);
      lastLink_->nextLink_ = newLink;
      lastLink_ = newLink;
      currentLink = currentLink->nextLink_;
    }
  }

  template < typename T >
  Queue<T>& Queue<T>::operator= (const Queue& q1)
  {
    if (&q1 != this)
    {
      if (!q1.Empty())
      {
        Queue<T>::Link* currentLink = q1.firstLink_;
        T data = currentLink->element_;
        Queue<T>::Link* newLink = new Link(data);
        firstLink_ = lastLink_ = newLink;
        currentLink = currentLink->nextLink_;
        while (currentLink != 0)
        {
          T data = currentLink->element_;
          Queue<T>::Link* newLink = new Link(data);
          lastLink_->nextLink_ = newLink;
          lastLink_ = newLink;
          currentLink = currentLink->nextLink_;
        }
      }
    }
    return *this;
  }

  template < typename T >
  Queue<T>::~Queue()
  {
    if (!Empty())
    {
      Queue<T>::Link* currentLink = firstLink_;
      Queue<T>::Link* tempLink;

      while (currentLink != 0)
      {
        tempLink = currentLink;
        currentLink = currentLink->nextLink_;
        delete tempLink;
      }
    }
  }
  template < typename T >
  void Queue<T>::Push(const T& t)
  {
    Queue<T>::Link* newLink = new Link(t);
    if (Empty())
      firstLink_ = lastLink_ = newLink;
    else
    {
      lastLink_->nextLink_ = newLink;
      lastLink_ = newLink;
    }
  }

  template < typename T >
  T Queue<T>::Pop()
  {
    if (Empty())
    {
      std::cerr << "Cannot pop, queue is empty!" << std::endl;
      exit(EXIT_FAILURE);
    }
    else
    {
      Queue<T>::Link* tempLink = firstLink_;

      if (firstLink_ == lastLink_)
        firstLink_ = lastLink_ = 0;
      else
        firstLink_ = firstLink_->nextLink_;
      T data = tempLink->element_;
      delete tempLink;
      return data;
    }
  }

  template < typename T >
  T& Queue<T>::Front()
  {
    if (!Empty())
      return firstLink_->element_;
    std::cerr << "Cannot return front, queue is empty!" << std::endl;
    exit(EXIT_FAILURE);
  }
  template < typename T >
  const T& Queue<T>::Front() const
  {
    if (!Empty())
      return firstLink_->element_;
    std::cerr << "Cannot return front, queue is empty!" << std::endl;
    exit(EXIT_FAILURE);
  }

  template < typename T >
  size_t Queue<T>::Size() const
  {
    if (Empty())
      return 0;
    Queue<T>::Link* currentLink = firstLink_;
    size_t size = 0;
    while (currentLink != 0)
    {
      currentLink = currentLink->nextLink_;
      ++size;
    }
    return size;
  }

  template < typename T >
  bool Queue<T>::Empty() const
  {
    return firstLink_ == 0;
  }

  template < typename T >
  void Queue<T>::Clear()
  {
    if (!Empty())
    {
      Queue<T>::Link *currentLink = firstLink_;
      Queue<T>::Link *tempLink;

      while (currentLink != 0)
      {
        tempLink = currentLink;
        currentLink = currentLink->nextLink_;
        delete tempLink;
      }
    }
    firstLink_ = lastLink_ = 0;
  }

  template < typename T >
  void Queue<T>::Display(std::ostream& os, char ofc ) const
  {
    if (Empty())
      return;
    Queue<T>::Link* currentLink = firstLink_;
    if (ofc != '\0')
    {
      while (currentLink != 0)
      {
        os << currentLink->element_ << ofc;
        currentLink = currentLink->nextLink_;
      }
    }
    else
    {
      while (currentLink != 0)
      {
        os << currentLink->element_;
        currentLink = currentLink->nextLink_;
      } // end while
    } // end else
  } // end Display

  template < typename T >
  std::ostream& operator << (std::ostream& os, const Queue<T>& S)
  {
    S.Display(os, '\0');
    return os;
  }

}

#endif