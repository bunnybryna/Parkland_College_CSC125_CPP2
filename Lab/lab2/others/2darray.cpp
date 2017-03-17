#include <iostream>
#include <stdlib.h>

using namespace std;

class Matrix
{
public:
    // pointer to a series of pointers which will refer to the 2D array
    float ** matrix;
    // default constructor
    Matrix();
    Matrix(int rows, int cols);
    float ** alloc(int rows, int cols);
    // destructor method - deallocate the memory used by matrix
    void dealloc();
    ~Matrix();
    // resize the matrix and returns pointer to new arrya[0,0]
    float ** setSize(int rows, int cols);
    // getMatrix method - returns a single pointer to the begining of array[0,0]
    float * getMatrix();
    // getRow method - returns a pointer to the begining of row at array[x,0]
    float * getRow(int row);
    // getColumn - returns a pointer to the begining of the column [0,y]
    float * getColumn(int col);



private:
    int x;
    int y;
};

int main()
{
    Matrix my_matrix(2,3);


    return 0;
}

Matrix::Matrix()
{
    matrix = alloc(0,0);
}

Matrix::Matrix(int rows, int cols)
{
    matrix = alloc(rows,cols);
}

Matrix::~Matrix()
{
    dealloc();
}
void Matrix::dealloc()
{
    //iterate through the rows of the original
    for (int row=0;row<x;row++)
    {
        delete []matrix[row];
    }
    delete []matrix;
}

/*
int ** array;
array = new int*[10];
for (int i=0;i<10;i++)
{
    array[i]=new int[10];
}
*/
float ** Matrix::alloc(int rows, int cols)
{
    x = rows;
    y = cols;

    float ** new_matrix = new float *[rows];
    for (int row = 0; row < rows; row++)
    {
        new_matrix[row] = new float[cols];

    }
    return new_matrix;
}

float** Matrix::setSize(int rows, int cols)
{
    if (rows > x && cols > y){
        float ** new_matrix = alloc(rows, cols);
        // fill new matrix with the elements from the old matrix
        for (int i=0;i<rows;i++)
        {
            new_matrix[i]= matrix[i];
        }
        // release memory for the old matrix
        dealloc();
        return new_matrix;
    }
    else
    {
        return matrix;
    }

}

float * Matrix::getMatrix()
{
    float * start = matrix[0];
    return start;
}

float * Matrix::getRow(int row)
{
    if (row > x)
    {
        cout << "Error: the row at index " << row << " is out of bounds.";
    }
    else
    {
        float * rowIndex = matrix[row];
        return rowIndex;
    }

}

float * Matrix::getColumn(int col)
{
    if (col > y)
    {
        cout << "Error: the col at index " << col << " is out of bounds.";
    }
    else
    {
        float * colIndex = &matrix[0][col];
        return colIndex;
    }

}
