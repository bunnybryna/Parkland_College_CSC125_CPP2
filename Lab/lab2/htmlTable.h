#ifndef _HTMLTABLE_H_
#define _HTMLTABLE_H_

#include <string>

using namespace std;

class HTMLTable
{
    public:
    // constructor
    HTMLTable();
    HTMLTable(int rows, int cols);
    void print();
    void insert(int row, int col, string text);
    void borderon();
    void borderoff();

    private:
    int m_row;
    int m_col;
    bool m_border;
    string m_table[100][100];

};
#endif
