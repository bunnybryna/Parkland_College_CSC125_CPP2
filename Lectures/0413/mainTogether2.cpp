//http://www.csit.parkland.edu/~kurban/permanent/cpp-examples/doodleBug/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

class World
{
    public:
        World();
        void start();
    protected:
    private:
        void init();
        void dayLoop();
        void dayIteration();
        void print();
        int charCount(string st);

        /// 0 and 21 are the borders
        Cell* myGrid[22][22];
};
class Cell
{
    public:
        Cell();
        void makeBorder() {myIsBorder = true;}
        bool isBorder() {return myIsBorder;}

        void setUp(Cell* data) {myUp = data;}
        void setDown(Cell* data) {myDown = data;}
        void setLeft(Cell* data) {myLeft = data;}
        void setRight(Cell* data) {myRight = data;}

        Cell* getUp() {return myUp;}
        Cell* getDown() {return myDown;}
        Cell* getLeft() {return myLeft;}
        Cell* getRight() {return myRight;}

        string toString();

        void setCritter(Organism *data);
        bool empty();
        bool isAnt();
        void killCritter();
        void moveCritter();
        void resetMove() {if (!empty()) myCritter->resetMove(); }

    protected:
    private:
        Organism *myCritter;
        Cell *myUp;
        Cell *myDown;
        Cell *myLeft;
        Cell *myRight;
        bool myIsBorder;
};

class Grid
{
    public:
        Grid();
    protected:
    private:
};

class Cell;
class Organism
{
    public:
        Organism();
        virtual bool isAnt() {return false;}
        virtual bool isDoodleBug() {return false;}
        virtual string toString()=0; /// required
        virtual void move()=0; /// required

        void resetMove() {myMoved=false;}
    protected:
        Cell *myCell;
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void basicMove();
        void breedMove(int);

        bool myMoved;
        int myBreedCount;
        int myStarveCount;
    private:

};

class Ant : public Organism
{
    public:
        Ant(Cell* parent);
        bool isAnt() {return true;}
        virtual string toString() {return " o ";}
        void move();



    protected:
    private:
};

class DoodleBug : public Organism
{
    public:
        DoodleBug(Cell *parent);
        bool isDoodleBug(){return true;}
        virtual string toString() {return " X ";}
        void move();
        bool eatAnt();

    protected:
    private:
};

int main()
{
    srand(time(0));
    World wally;
    wally.start();

    return 0;
}


Grid::Grid()
{
    //ctor
}

World::World()
{
    int row, col, i;
    //ctor
    /// build and hookup the pointers in myGrid

    /// allocate space for each cell

    for (row=0;row<22;row++)
    {
        for (col=0;col<22;col++)
        {
            myGrid[row][col] = new Cell();
        }
    }

    /// border
    for (i=0;i<22;i++)
    {
        myGrid[0][i]->makeBorder();
        myGrid[21][i]->makeBorder();
        myGrid[i][0]->makeBorder();
        myGrid[i][21]->makeBorder();
    }

    /// set the pointers in the middle cells to their neighbors
    for (row=1;row<21;row++)
    {
        for (col=1;col<21;col++)
        {
            myGrid[row][col]->setUp(  myGrid[row-1][col] );
            myGrid[row][col]->setDown(  myGrid[row+1][col] );
            myGrid[row][col]->setLeft(  myGrid[row][col-1] );
            myGrid[row][col]->setRight(  myGrid[row][col+1] );
        }
    }
}

void World::start()
{
    cout << "Welcome " << endl;
    string cont;

    do
    {

       /// init stuff
       init();
       /// day by day
       dayLoop();

       cout << "Do it again?: [y/n]";
       getline(cin, cont);
    } while (cont == "y" || cont =="Y" );

    cout << "Bye " << endl;
}

void World::init()
{
    int percent, row, col;
    /// place critters in the world
    for (row=1;row<21;row++)
    {
        for (col=1;col<21;col++)
        {
            /// clean up previous world
            myGrid[row][col]->killCritter();

            /// whole thing 100.00 %
            percent = rand() % 10000;

            if (percent < 2500)
            {
                /// Ants   100/400 = 25.00%
                myGrid[row][col]->setCritter( new Ant( myGrid[row][col] )  );
            }
            else if(percent < 2625)
            {
                /// DoodleBugs 5/400 = 1.25%
                myGrid[row][col]->setCritter( new DoodleBug( myGrid[row][col]) );
            }
        }
    }
}

void World::dayLoop()
{
    char ch='y';
    /// infinite (for now)
    while (ch!='n')
    {
        dayIteration();
	cout << "Hit return to continue, x or q, then return to exit: ";
	ch = getchar();
	/// let's exit!
	switch (ch)
	  {
	  case 'x':
	  case 'X':
	  case 'q':
	  case 'Q':
	    exit(0);
	  }
    }
}

void World::dayIteration()
{
    int row, col;
    /// set everything to be unmoved
    for (row=1;row<21;row++)
    {
        for (col=1;col<21;col++)
        {
            myGrid[row][col]->resetMove();
        }
    }

    for (row=1;row<21;row++)
    {
        for (col=1;col<21;col++)
        {
            /// oops they all move at once.
            myGrid[row][col]->moveCritter();
        }
    }

    print();
}

void World::print()
{
    int row, col;
    for (row=0;row<22;row++)
    {
        for (col=0;col<22;col++)
        {
            cout << setw(3) << myGrid[row][col]->toString();
        }
        cout << endl;
    }

    cout << "             ";
    cout << "Counts: ants=" << charCount(" o ");
    cout << " doodlebugs=" << charCount(" X ");
    cout << endl;
}

int World::charCount(string st)
{
    int count=0, row, col;
    for (row=1;row<21;row++)
    {
        for (col=1;col<21;col++)
        {
            if (myGrid[row][col]->toString() == st)
                count ++;
        }
    }
    return count;
}

Cell::Cell()
{
    //ctor
    myIsBorder = false;
    /// null
    myUp = static_cast<Cell *>(0);
    myDown = static_cast<Cell *>(0);
    myLeft = static_cast<Cell *>(0);
    myRight = static_cast<Cell *>(0);

    myCritter = static_cast<Organism *>(0);

}

string Cell::toString()
{
    if ( isBorder() )
        return "+++";
        /// other stuff
    if (empty())
        return "   ";
    return myCritter->toString();

}

void Cell::setCritter(Organism *data)
{
    myCritter = data;
}

void Cell::killCritter()
{
    if (myCritter)
    {
        delete myCritter;
    }
    myCritter = static_cast<Organism *>(0);
}

void Cell::moveCritter()
{
    if (!empty())
    {
        myCritter->move();
    }
}

bool Cell::empty()
{
    if (isBorder())
    {
        /// borders are never empty
        return false;
    }
    return !myCritter;
}

bool Cell::isAnt()
{
    if (isBorder())
    {
        /// borders are never empty
        return false;
    }

    if ( empty() )
    {
        /// cant be an ant if it's empty
        return false;
    }

    return myCritter->toString() == " o ";
}

Organism::Organism()
{
    //ctor
    myBreedCount = 0;
    myStarveCount = 0;
    myMoved = false;

}


void Organism::moveUp()
{
    if ( (myCell->getUp()->empty()) )
    {
        /// set new cell to point to myself
        myCell->getUp()->setCritter( this  );
        /// set the old cell to point to null
        myCell->setCritter( static_cast<Organism *>(0)  );
        /// set myself to point to new cell
        myCell = myCell->getUp();
    }
}

void Organism::moveDown()
{
    if ( (myCell->getDown()->empty()) )
    {
        /// set new cell to point to myself
        myCell->getDown()->setCritter( this  );
        /// set the old cell to point to null
        myCell->setCritter( static_cast<Organism *>(0)  );
        /// set myself to point to new cell
        myCell = myCell->getDown();
    }
}

void Organism::moveLeft()
{
    if ( (myCell->getLeft()->empty()) )
    {
        /// set new cell to point to myself
        myCell->getLeft()->setCritter( this  );
        /// set the old cell to point to null
        myCell->setCritter( static_cast<Organism *>(0)  );
        /// set myself to point to new cell
        myCell = myCell->getLeft();
    }
}

void Organism::moveRight()
{
    if ( (myCell->getRight()->empty()) )
    {
        /// set new cell to point to myself
        myCell->getRight()->setCritter( this  );
        /// set the old cell to point to null
        myCell->setCritter( static_cast<Organism *>(0)  );
        /// set myself to point to new cell
        myCell = myCell->getRight();
    }
}

void Organism::basicMove()
{
    int dir;
    /// randomly pick a direction
    dir = rand() % 4;
    switch (dir)
    {
    case 0:
        /// up
        moveUp();
        break;
    case 1:
        /// down
        moveDown();
        break;
    case 2:
        /// left
        moveLeft();
        break;
    case 3:
        /// right
        moveRight();
        break;
    }
}

Ant::Ant(Cell *parent)
{
    //ctor
    myCell = parent;
}

void Ant::move()
{
    if (myMoved) return;
    myMoved = true;

    basicMove();
    myBreedCount ++;

    /// if it survives for 'steps' time steps, breed
    if (myBreedCount == 3)
    {
        /// check up
        if ( (myCell->getUp()->empty()) )
        {
            myCell->getUp()->setCritter( new Ant( myCell->getUp() ) );
        }
        /// check down
        else if ( (myCell->getDown()->empty()) )
        {
            myCell->getDown()->setCritter( new Ant( myCell->getDown() ) );
        }
        /// check left
        else if ( (myCell->getLeft()->empty()) )
        {
            myCell->getLeft()->setCritter( new Ant( myCell->getLeft() ) );
        }
        /// check right
        else if ( (myCell->getRight()->empty()) )
        {
            myCell->getRight()->setCritter( new Ant( myCell->getRight() ) );
        }
        myBreedCount = 0;
    }

}

DoodleBug::DoodleBug(Cell *parent)
{
    //ctor
    myCell = parent;
}

void DoodleBug::move()
{
    if (myMoved) return;
    myMoved = true;

    if (!eatAnt())
    {
        basicMove();
    }
    else
    {
        myStarveCount = 0;
    }

    myBreedCount ++;
    myStarveCount ++;

    /// if 3 steps without eating, die
    if (myStarveCount == 3)
    {
        myCell->killCritter();
        /// dont use an object after it's been delete
        return;
    }

    /// if it survives for 'steps' time steps, breed
    if (myBreedCount == 8)
    {
        /// check up
        if ( (myCell->getUp()->empty()) )
        {
            myCell->getUp()->setCritter( new DoodleBug( myCell->getUp() ) );
        }
        /// check down
        else if ( (myCell->getDown()->empty()) )
        {
            myCell->getDown()->setCritter( new DoodleBug( myCell->getDown() ) );
        }
        /// check left
        else if ( (myCell->getLeft()->empty()) )
        {
            myCell->getLeft()->setCritter( new DoodleBug( myCell->getLeft() ) );
        }
        /// check right
        else if ( (myCell->getRight()->empty()) )
        {
            myCell->getRight()->setCritter( new DoodleBug( myCell->getRight() ) );
        }
        myBreedCount = 0;
    }
}

bool DoodleBug::eatAnt()
{

    if ( (myCell->getUp()->isAnt()) )
    {
        /// kill off the ant, then move there
        myCell->getUp()->killCritter();
        /// set new cell to point to myself
        myCell->getUp()->setCritter( this  );
        /// set the old cell to point to null
        myCell->setCritter( static_cast<Organism *>(0)  );
        /// set myself to point to new cell
        myCell = myCell->getUp();
        return true;
    }

    if ( (myCell->getDown()->isAnt()) )
    {
        /// kill off the ant, then move there
        myCell->getDown()->killCritter();
        /// set new cell to point to myself
        myCell->getDown()->setCritter( this  );
        /// set the old cell to point to null
        myCell->setCritter( static_cast<Organism *>(0)  );
        /// set myself to point to new cell
        myCell = myCell->getDown();
        return true;
    }

    if ( (myCell->getLeft()->isAnt()) )
    {
        /// kill off the ant, then move there
        myCell->getLeft()->killCritter();
        /// set new cell to point to myself
        myCell->getLeft()->setCritter( this  );
        /// set the old cell to point to null
        myCell->setCritter( static_cast<Organism *>(0)  );
        /// set myself to point to new cell
        myCell = myCell->getLeft();
        return true;
    }

    if ( (myCell->getRight()->isAnt()) )
    {
        /// kill off the ant, then move there
        myCell->getRight()->killCritter();
        /// set new cell to point to myself
        myCell->getRight()->setCritter( this  );
        /// set the old cell to point to null
        myCell->setCritter( static_cast<Organism *>(0)  );
        /// set myself to point to new cell
        myCell = myCell->getRight();
        return true;
    }


    return false;
}
