/*
fqueue.cpp
12/3/13
Trevor Richardson

Test harness to determine functionality of queue.t.
*/

#include <iostream>
#include <queue.t>

void DisplayMenu();

// choose one from group A

//  A1: makes queues of char
typedef char ElementType;
const size_t maxSize = 10;
const char* eT = "char";
const char ofc = '\0';
// end A1 */

/*  A2: makes queues of TestType, a simple class storing a char (T is default)
class TestType
{
friend std::ostream &operator<<(std::ostream& os, const TestType tt);
friend std::istream &operator>>(std::istream& is, TestType tt);
public:
explicit TestType();
explicit TestType(char);
TestType(const TestType&);
TestType& operator= (const TestType&);
~TestType() {};
void TestTypeSet(char);
char TestTypeGet();

private:
char char_;
};

std::ostream &operator<<(std::ostream& os, const TestType tt)
{
os << tt.char_;
return os;
}

std::istream &operator>>(std::istream& is, TestType tt)
{
is >> tt.char_;
return is;
}

TestType::TestType()
: char_('T')
{}

TestType::TestType(char c)
: char_(c)
{}

TestType::TestType(const TestType& tt)
{
char_ = tt.char_;
}

TestType& TestType::operator= (const TestType& tt)
{
if (&tt != this)
{
char_ = tt.char_;
}
return *this;
}

void TestType::TestTypeSet(char c)
{
char_ = c;
}

char TestType::TestTypeGet()
{
return char_;
}

typedef TestType ElementType;
const size_t maxSize = 20;
const char* eT = "String";
const char ofc = ' ';
// end A2 */

/* //  A3: makes queues of int
typedef int ElementType;
const size_t maxSize = 100;
const char* eT = "int";
const char ofc = ' ';
// end A3 */

typedef fsu::Queue<ElementType> QueueType;

template < class Queue >
void CopyTest(Queue s);

template < class Queue >
void AssignTest(const Queue& s);

template < class Queue >
void ConstTest(const Queue& s);


int main()
{
  char selection;
  QueueType queue;
  ElementType Tval;
  std::cout << "This is a Queue < T > test program\n";
  DisplayMenu();
  do
  {
    std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
    std::cin >> selection;
    switch (selection)
    {
    case '+':
    case '1':
        std::cin >> Tval;
        queue.Push(Tval);
      break;
    case '-':
    case '2':
      if (!queue.Empty())
        queue.Pop();
      else
        std::cout << "Queue is empty" << std::endl;
      break;
    case 'C':
    case 'c':
      queue.Clear();
      break;
    case 'F':
    case 'f':
      if (!queue.Empty())
        std::cout << "Front of Queue: " << queue.Front() << std::endl;
      else
        std::cout << "Queue is empty" << std::endl;
      break;
    case 'E':
    case 'e':
      if (queue.Empty())
        std::cout << "Queue is empty" << std::endl;
      else
        std::cout << "Queue is not empty" << std::endl;
      break;
    case 'S':
    case 's':
      std::cout << "Queue size = " << queue.Size() << std::endl;
      break;
    case '=':
      CopyTest(queue);
      AssignTest(queue);
      break;
    case 'D':
    case 'd':
      std::cout << "Queue contents: ";
      queue.Display(std::cout);
      std::cout << '\n';
      break;
    case 'U':
    case 'u':
      std::cout << "Queue doesn't have a dump function" << std::endl;
      break;
    case 'M':
    case 'm':
      DisplayMenu();
      break;
    case 'Q':
    case 'q':
      break;
    default:
      std::cout << "  command not found\n";
    }
  } while ((selection != 'Q') && (selection != 'q'));
  std::cout << "\nHave a nice day." << std::endl;
  return 0;
}

void DisplayMenu()
{
  std::cout
    << "Push(Tval)  .............  + or 1\n"
    << "Pop()  ..................  - or 2\n"
    << "Clear()  ................  C\n"
    << "Front()  ................  F\n"
    << "Empty()  ................  E\n"
    << "Size()  .................  S\n"
    << "Copies  .................  =\n"
    << "Display queue ...........  D\n"
    << "Dump() ..................  U\n"
    << "Display this menu  ......  M\n";
}

template < class Queue >
void CopyTest(Queue s)
{
  std::cout << "CopyTest:\n";
  std::cout
    << "Copied object   size: " << s.Size() << '\n'
    << "            contents: ";
  s.Display(std::cout);
  std::cout << '\n';
}

template < class Queue >
void AssignTest(const Queue& s1)
{
  QueueType s2;
  s2 = s1;
  std::cout << "AssignTest:\n"
    << "Original object size: " << s1.Size() << '\n'
    << "            contents: ";
  s1.Display(std::cout);
  std::cout << '\n';
  std::cout
    << "Assignee object size: " << s2.Size() << '\n'
    << "            contents: ";
  s2.Display(std::cout);
  std::cout << '\n';
  std::cout << "ConstTest: OK" << std::endl;
}
