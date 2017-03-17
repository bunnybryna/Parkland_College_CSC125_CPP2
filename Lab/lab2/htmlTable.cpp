#include <iostream>
#include "htmlTable.h"

HTMLTable::HTMLTable()
{

}

HTMLTable::HTMLTable(int rows, int cols)
{
    m_row = rows;
    m_col = cols;
    m_border = true;
    for (int row=0;row<rows;row++)
    {
        for (int col=0;col<cols;col++)
        {
            m_table[row][col]= " Bryna ";
        }
    }
}


void HTMLTable::insert(int row, int col, string text)
{
    m_table[row-1][col-1] = text;
}

void HTMLTable::print()
{
    if (m_border)
    {
        cout << "<table border='1'>" << endl;
    }
    else
    {
        cout << "<table border='0'>" << endl;
    }
    for (int i=0;i<m_row;i++)
    {
        cout << "<tr>";
        for (int j=0;j<m_col;j++)
        {
            cout <<"<td>" << m_table[i][j]<< "</td>";
        }
        cout << "</tr>"<<endl;
    }
    cout << "</table>" << endl;
}

void HTMLTable::borderon()
{
    m_border = true;
}

void HTMLTable::borderoff()
{
    m_border = false;
}
