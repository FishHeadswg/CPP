/*
    maze.h 

    02/04/14
    Trevor Richardson
    trichard

    Defines classes Maze and Cell which together form a system for solving
    certain maze problems. A "maze problem" consists of the following three
    items: 

    1. A "maze", being a rectangular array of square cells such that:
 
       a. The exterior perimeter of the rectangle is solid (impenetrable).

       b. Walls between cells may be designated as extant, meaning a barrier is
          in place, or non-extant, meaning passage between cells at that
          location is not restricted.
  
       c. Cells are numbered consequtively from left to right and top to bottom,
          beginning with cell number 0 in the upper left corner.

    2. A designated "start" cell.

    3. A designated "goal" cell.

    A "path" in a maze is a sequence of cell numbers such that adjacent cells
    in the sequence share a common face with no wall.  A "solution" to a maze
    problem is a path in the maze from the start cell to the goal cell.

    Maze files
    ==========

    Maze problems are represented externally by "maze files".
    The following file structure and semantics are assumed:

    File structure / syntax:
    -----------------------
    The file consists of unsigned decimal integer entries that can be
    organized as follows:

      numrows numcols   
      (first row)       
      (second row)
      ...
      (last row)
      start goal        

    Here "numrows" and "numcols" are two unsigned integers.  Following these two
    numbers are (numrows) x (numcols) unsigned integers, typically arranged in a
    rectangular array.  Finally there are two unsigned integers "start" and
    "goal" at the end. For convenience of human reading, the numbers may be
    organized as above, with two numbers followed by a rectangular array of
    numbers followed by two more numbers.

    Data of any kind, such as file documentation, may be placed in the file after the
    "goal" entry with no semantic interpretation.

    Because the semantically relevant portion of the file consists of integer
    entries only, no particular row/column format for the file is assumed.

    File semantics:
    --------------

    The first two numbers "numrows" and "numcols" give the number of rows and
    columns, respectively, in the maze. The last two numbers "start" and "goal"
    give the cell numbers of the starting and goal locations in the maze
    problem. There should be exactly (numrows)x(numcols) entries in between,
    representing individual cells in the maze by increasing cell number.

    The numbers representing individual cells are "walls codes" that give
    specific information about walls of that particular cell. Each walls code is
    an integer in the range [0..15] and is used to encode the cell walls for the
    four sides of the cell using the binary representation:

      1's bit = north wall
      2's bit = east  wall
      4's bit = south wall
      8's bit = west  wall

    If the bit is "1" the designated wall exists, if the bit is "0" the
    designated wall does not exist. For example, if the walls code for a cell
    is 11,

      11 = 8 + 2 + 1 = 1011(binary)

    implies north, east, and west walls but no south wall: a cell something like
    this:
       _ 
      | |

    a cell that is open at the bottom, or south, face and closed at the other
    three faces. (Think of north as "up" in visualizing a maze.)

    class Maze
    ==========

    A class for solving maze problems consisting of a rectangular array of
    square cells. A maze problem consists of a maze, a begin cell, and a goal
    cell. A solution consists of a sequence of cell numbers from the start cell
    to the goal cell. 

    Maze objects are in the namespace maze. 

    A Maze object has these capabilities:

    1. bool Initialize(char*)

       Reads data from a maze file and sets up the internal representation of the
       maze problem. Checks file syntax while reading. Returns true when read is
       successful.

    2. bool Consistent() const

       Checks the internal representation (established by Initialize() from a maze
       file) for consistency of walls, detecting and reporting all situations
       where adjacent cells do not agree on raising their common wall and where
       the exterior walls are not raised. Returns true when no inconsistencies
       are found.

    3. void Solve()

       Uses breadth-first-search to find a solution to the internally represented
       maze problem. 
 
    4. void ShowMaze(std::ostream&) const

       Produces a graphic of the maze using the internal representation.

    A Maze object can hold one internal maze representation, read from a maze
    file. Class Maze is designed to be a singleton: only one Maze object exists
    in a given execution environment.

    class Cell
    ==========

    Class Cell is a subsidiary class for Maze, tightly coupled by granting
    friend status to class Maze.  A Cell object represents one square cell in a
    2-d maze, used by Maze to represent rectangular mazes of square cells. 
    The constructors and assignment operator of Cell are public, to facilitate
    storing Cell objects in container classes. All other methods and data are
    private, hence accessible only by the friend class Maze.

    Copyright 2014
 */

#ifndef _MAZE_H
#define _MAZE_H

#include <iostream>
#include <list.h>
#include <vector.h>
#include <deque.h>
#include <queue.h>
#include <stack.h>

namespace maze
{

  //------------------------------
  //   class Maze
  //------------------------------

  class Cell;

  class Maze 
  {
  public: 

    bool Initialize    ( const char* filename );
    bool Consistent    () const;
    void Solve         ( fsu::List < unsigned long > & solution );
    void ShowMaze      ( std::ostream& os = std::cout ) const;

         Maze          ();
         ~Maze         ();

  private: // variables
    unsigned long                                   numrows_, numcols_;
    Cell *                                          start_;
    Cell *                                          goal_;
    fsu::Vector < Cell >                            cellVector_;  // cell inventory
    // fsu::Stack  < Cell* , fsu::Vector < Cell* > >   conStack_;    // DFS
    fsu::Queue  < Cell* , fsu::Deque  < Cell* > >   conQueue_;    // BFS

  private: // methods
    void Clear();

    // not intended to be used -- do not implement
    Maze             (const Maze&);  // copy constructor
    Maze& operator = (const Maze&);  // assignment operator

  }  ;  // class Maze

  //------------------------------
  //   class Cell
  //------------------------------

  class Cell
  {
    friend bool Maze::Consistent() const;

  public:
                  Cell             ();
                  ~Cell            ();
                  Cell             (const Cell& c);
    Cell&         operator =       (const Cell& c);

    void          Clear            ();

    void          SetID            (unsigned long id);
    unsigned long GetID            ()                const;
    void          SetParent        (Cell*);
    Cell*         GetParent        ()                const;
    void          SetVisited       ();
    void          UnSetVisited     ();
    bool          IsVisited        ()                const;
  
    void          AddNeighbor      (Cell * N);
    Cell*         GetNextNeighbor  ()                const;
    bool          IsNeighbor       (const Cell * N)  const;

  private:  // variables
    unsigned long        id_;
    fsu::List < Cell* >  neighborList_;
    bool                 visited_;
    Cell *               searchParent_; // needed only for BFS

  } ;  // class Cell

} // namespace

#endif
