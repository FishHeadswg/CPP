/*
  fstack.cpp
  12/1/13
  Trevor Richardson

  Test harness to determine functionality of stack.t.
*/

#include <iostream>
#include <stack.h>

void DisplayMenu();

// choose one from group A

//  A1: makes stacks of char
typedef char ElementType;
ElementType fill = '*';
const size_t maxSize = 10;
const char* eT = "char";
const char ofc = '\0';
// end A1 */

/* //  A2: makes stacks of TestType, a simple class storing a char (T is default)
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
ElementType fill = TestType('*');
const size_t maxSize = 20;
const char* eT = "String";
const char ofc = ' ';
// end A2 */

/* //  A3: makes stacks of int
typedef int ElementType;
ElementType fill = 0;
const size_t maxSize = 100;
const char* eT = "int";
const char ofc = ' ';
// end A3 */

typedef fsu::Stack<ElementType, maxSize> StackType;

template < class Stack >
void CopyTest(Stack s);

template < class Stack >
void AssignTest(const Stack& s);

template < class Stack >
void ConstTest(const Stack& s);


int main()
{
  char selection;
  StackType stack(fill);
  ElementType Tval;
  std::cout << "This is a Stack < char > test program\n";
  DisplayMenu();
  do
  {
    std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
    std::cin >> selection;
    switch (selection)
    {
    case '+':
    case '1':
      if (stack.Capacity() != stack.Size())
      {
        std::cin >> Tval;
        stack.Push(Tval);
      }
      else
      {
        std::cout << "Stack is full" << std::endl;
        std::cin >> Tval;
      }
      break;
    case '-':
    case '2':
      if (!stack.Empty())
        stack.Pop();
      else
        std::cout << "Stack is empty" << std::endl;
      break;
    case 'C':
    case 'c':
      stack.Clear();
      break;
    case 'T':
    case 't':
      if (!stack.Empty())
        std::cout << "Top of Stack: " << stack.Top() << std::endl;
      else
        std::cout << "Stack is empty" << std::endl;
      break;
    case 'E':
    case 'e':
      if (stack.Empty())
        std::cout << "Stack is empty" << std::endl;
      else
        std::cout << "Stack is not empty" << std::endl;
      break;
    case 'S':
    case 's':
      std::cout << "Stack size = " << stack.Size() << std::endl;
      break;
    case '=':
      CopyTest(stack);
      AssignTest(stack);
      break;
    case 'D':
    case 'd':
      std::cout << "Stack contents: ";
      stack.Display(std::cout);
      std::cout << '\n';
      break;
    case 'U':
    case 'u':
      stack.Dump(std::cout);
      std::cout << '\n';
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
    << "Top()  ..................  T\n"
    << "Empty()  ................  E\n"
    << "Size()  .................  S\n"
    << "Copies  .................  =\n"
    << "Display stack ...........  D\n"
    << "Dump() ..................  U\n"
    << "Display this menu  ......  M\n";
}

template < class Stack >
void CopyTest(Stack s)
{
  std::cout << "CopyTest:\n";
  std::cout
    << "Copied object   size: " << s.Size() << '\n'
    << "            contents: "; 
  s.Display(std::cout);
  std::cout << '\n';
}

template < class Stack >
void AssignTest(const Stack& s1)
{
  StackType s2;
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
