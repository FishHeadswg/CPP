/*
    maze.cpp

    02/04/14
    Trevor Richardson
    trichard
  
    Uses breadth-first search to solve mazes 
    initialized from input files and check for consistency.

*/

#include <fstream>
#include <iomanip>
#include <genalg.h>
#include <maze.h>

#define NORTH 1
#define EAST 2
#define SOUTH 4
#define WEST 8

namespace maze
{

  //------------------------------
  //   class Maze
  //------------------------------

  void Maze::Clear ()
  {
    // clears each cell in cellVector_
    for (fsu::Vector < Cell >::Iterator itr = cellVector_.Begin();
      itr != cellVector_.End(); ++itr)
    {
      itr->Clear();
    }
    // pops each element from cellVector_
    for (size_t i = 0; i < cellVector_.Size(); ++i)
      cellVector_.PopBack();
    // just to be thorough
    Cell *newCell = new Cell;
    cellVector_.SetSize(0, *newCell);
    conQueue_.Clear();
  }

  // Maze solver using BFS
  void Maze::Solve(fsu::List<unsigned long>& solution)
  {
    conQueue_.Clear();
    for (fsu::Vector < Cell >::Iterator itr = cellVector_.Begin();
      itr != cellVector_.End(); ++itr)
    {
      itr->UnSetVisited();
      itr->SetParent(0);
    }
    start_->SetVisited();
    conQueue_.Push(start_);
    Cell *N = nullptr;
    while (!conQueue_.Empty())
    {
      while (conQueue_.Front()->GetNextNeighbor())
      {
        N = conQueue_.Front()->GetNextNeighbor();
        N->SetVisited();
        N->SetParent(conQueue_.Front());
        conQueue_.Push(N);
        if (N == goal_)
          break;
      }
      conQueue_.Pop();
    }
    // Populates solution list starting from goal and working back
    N = goal_;
    solution.Clear();
    solution.PushFront(N->GetID());
    while (N->GetParent())
    {
      N = N->GetParent();
      solution.PushFront(N->GetID());
    }
  }

  // Maze initialization
  bool Maze::Initialize (const char* filename)
  {
    Maze::Clear(); // clear any previously initialized maze
    std::ifstream mazeFile(filename, std::ios::in); // open maze
    if (!mazeFile) // invalid file
    {
      std::cerr << "Could not read maze file!" << std::endl;
      return 0;
    }
    mazeFile >> numrows_ >> numcols_; // read dimensions
    unsigned long dimensions = numrows_ * numcols_;
    cellVector_.SetSize(dimensions); // size vector
    unsigned short wall; // *LOCAL* variable for wallcodes
    for (unsigned long i = 0; i < dimensions; ++i)
    {
      // Populates celld by wall code while checking boundaries
      if (mazeFile >> wall)
      {
        cellVector_[i].SetID(i);
        unsigned col = i % numcols_;
        unsigned row = i / numcols_;
        if ((row > 0) && (!(wall & NORTH)))
          cellVector_[i].AddNeighbor(&cellVector_[i - numcols_]);
        if ((row == 0) && !(wall & NORTH))
          std::cerr << "** DEFECT: walls code[" << i 
          << "] repaired at North face maze boundary " << filename << std::endl;
        if ((col < (numcols_ - 1)) && !(wall & EAST))
          cellVector_[i].AddNeighbor(&cellVector_[i + 1]);
        if ((col == (numcols_ - 1)) && !(wall & EAST))
          std::cerr << "** DEFECT: walls code[" << i 
          << "] repaired at East face maze boundary " << filename << std::endl;
        if ((row < (numrows_ -1)) && !(wall & SOUTH))
          cellVector_[i].AddNeighbor(&cellVector_[i + numcols_]);
        if ((row == (numrows_ - 1)) && !(wall & SOUTH))
          std::cerr << "** DEFECT: walls code[" << i 
          << "] repaired at South face maze boundary " << filename << std::endl;
        if ((col > 0) && !(wall & WEST))
          cellVector_[i].AddNeighbor(&cellVector_[i - 1]);
        if ((col == 0) && !(wall & WEST))
          std::cerr << "** DEFECT: walls code[" << i 
          << "] repaired at West face maze boundary " << filename << std::endl;
      } // end if

      else // input ended before expected
      {
        std::cerr << "Maze file dimensions are incorrect!" << std::endl;
        return 0;
      } // end else
    } // end for
    unsigned long start, goal;
    // reads start/goal and makes sure they're valid for the maze dimensions
    if (mazeFile >> start >> goal)
    {
      if (!(start < dimensions))
      {
        std::cerr << "Start is outside cell bounds!" << std::endl;
        return 0;
      }
      if (!(goal < dimensions))
      {
        std::cerr << "Goal is outside cell bounds!" << std::endl;
        return 0;
      }
      start_ = &(cellVector_[start]);
      goal_ = &(cellVector_[goal]);
      return 1;
    }
    // start/goal missing
    std::cerr << "** DEFECT: Maze::Initialize(): unable to read size data " 
      "from " << filename << std::endl;
    return 0;
  }

  // checks consistency of mazes 
  bool Maze::Consistent() const
  {
    unsigned long dimensions = numrows_ * numcols_;
    bool inconsistent = 0; // ticker to allow all inconsistencies to be checked
    // checks each cell and its neighbors for asymmetries and reports them
    for (unsigned long i = 0; i < dimensions; ++i)
      for (fsu::ConstListIterator<Cell *> itr = 
        cellVector_[i].neighborList_.Begin();
        itr != cellVector_[i].neighborList_.End(); ++itr)
      {
        if ((cellVector_[i].IsNeighbor(*itr)) && 
          !((*itr)->IsNeighbor(&cellVector_[i])))
        {
          std::cerr << "** DEFECT: neighbor asymmetry between cells "
            << cellVector_[i].GetID() << " and " << (*itr)->GetID() 
            << std::endl;
          inconsistent = 1;
        }

        // Boundary walls check already done in initialize

        // check if neighbor is adjacent for tunnel errors
        /*if ((cellVector_[i].IsNeighbor(*itr)) && (*itr)->GetID() != (i - 1) 
          && ((*itr)->GetID() != (i + 1))
          && ((*itr)->GetID() != (i - numcols_))
          && ((*itr)->GetID() != (i + numcols_)))
        {
          std::cout << (*itr)->GetID() << " " << (i - 1)
            << (*itr)->GetID() << " " << (i + 1)
            << (*itr)->GetID() << " " << (i - numcols_)
            << (*itr)->GetID() << " " << (i + numcols_) << std::endl;
          std::cerr << "Tunneling error at cell " << i << std::endl;
          inconsistent = 1;
        }*/
        if (i != cellVector_[i].GetID())
          std::cerr << "ID mismatch at cell " << i << std::endl;
      } // end for
    if (inconsistent == 1)
      return 0;
    return 1;
  }

  void Maze::ShowMaze(std::ostream& os) const
  {
    os << " ** ShowMaze not implemented\n";
  }

  // Maze:: implementations below are already done

  Maze::Maze () : numrows_(0), numcols_(0), start_(0), goal_(0), 
    cellVector_(0), conQueue_()
  {}

  Maze::~Maze ()
  {
    Clear();
  }

  //------------------------------
  //   class Cell
  //------------------------------

  Cell& Cell::operator = (const Cell& c) // note: called by Vector::SetSize()
  {
    if (this != &c)
    {
      id_ = c.id_;
      neighborList_ = c.neighborList_;
      visited_ = c.visited_;
      searchParent_ = c.searchParent_;
    }
    return *this;
  }

  void Cell::Clear()
  {
    id_ = 0;
    visited_ = 0;
    neighborList_.Clear();
    searchParent_ = 0;
  }

  void Cell::AddNeighbor (Cell * N)
  {
    neighborList_.PushBack(N);
  }

  Cell* Cell::GetNextNeighbor () const
  {
    // sequentially search neighbor list for unvisited neighbor,
    //   return address when found (early bailout)
    // return 0 if not found
    for ( fsu::ConstListIterator<Cell *> i = neighborList_.Begin();
      i != neighborList_.End(); ++i)
    {
      if ((*i)->IsVisited() == 0)
        return *i;
    }
    return 0;
  } 

  bool Cell::IsNeighbor (const Cell * N) const
  {
    // is N on my neighbor list? 
    // sequentially search neighbor list,
    //   return 1 if found (early bailout)
    // return 0 if not found
    for (fsu::ConstListIterator<Cell *> i = neighborList_.Begin();
      i != neighborList_.End(); ++i)
    {
      if (*i == N)
        return 1;
    }
    return 0;
  }

  // Cell:: implementations below are already done

  void Cell::SetID (unsigned long id)
  {
    id_ = id;
  }

  unsigned long Cell::GetID () const
  {
    return id_;
  }

  void Cell::SetVisited ()
  {
    visited_ = 1;
  }

  void Cell::UnSetVisited ()
  {
    visited_ = 0;
  }

  bool Cell::IsVisited () const
  {
    return visited_;
  }

  void  Cell::SetParent(Cell *parent)
  {
    this->searchParent_ = parent;
  }

  Cell* Cell::GetParent() const
  {
    return this->searchParent_;
  }

  // default constructor, required to create vector of cells
  Cell::Cell  () : id_(0), neighborList_(), visited_(0), searchParent_(0)
  {}

  // destructor - calls Cell::Clear()
  Cell::~Cell ()
  {
    Clear();
  }

  // copy constructor - implemented, but sends message when called
  // (we should not be using it)
  Cell::Cell(const Cell& c) : id_(c.id_), neighborList_(c.neighborList_),
    visited_(c.visited_)
  {
    std::cout << "** ERROR: call to Cell copy constructor\n";
  }

} // namespace
