/* to use this,
     - write a form that calls this program with 'action=' in the <form> tag
     - call getPostData()
     - use getField(string) to access form information

*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "htmlform.h"
//#include "binarysearchtree.h"

using namespace std;

struct Node
{
	pair<int, string> data;
	Node* right;
	Node* left;
	private:
};

class BinarySearchTree
{
	public:
	BinarySearchTree()
	{
		m_Root = NULL;
	}
	~BinarySearchTree(){erase();}
	BinarySearchTree(const BinarySearchTree& other);
	void print();
	void inorder();
	void preorder();
	void postorder();
	bool empty()
	{
		return m_Root == NULL;
	}
	void insert(pair<int, string> data);
	void erase(){eraseHelper(m_Root); m_Root = NULL;}
	protected:
	private:
		void insertHelper(Node* &n, pair<int, string> data);
		void printHelper(Node* n);
		void preorderHelper1(Node* n);
		void preorderHelper2(Node* n);
		void inorderHelper1(Node* n);
		void inorderHelper2(Node* n);
		void postorderHelper1(Node* n);
		void postorderHelper2(Node* n);
		Node* copyHelper(Node* oldNode);
		void eraseHelper(Node* n);
		Node* m_Root;
};

void printProgram(string program);   /// print the program in HTML
void parseProgram(string program, BinarySearchTree& btree);
void parse(string line, BinarySearchTree& btree);



using namespace std;

int main()
{
  /// complete the http header
  cout << "Content-type: text/html\n\n";

  /// build a form object
  HTMLform steps;
  steps.getPostData();

  /// Show the debugging
  cout << "Binary Search Tree Parser Lab startup" << endl;
  steps.debug();

  /// the entire programs
  string program = steps.getField("program");
  //string program = "INSERT 25, BRYNA\nINSERT 15, BRYNA\nINSERT 50, BRYNA\nINSERT 10, BRYNA\nINSERT 22, BRYNA\nINSERT 35, BRYNA\nINSERT 70, BRYNA\nPOSTORDER\nINORDER\nPREORDER\n";
  printProgram(program);
  BinarySearchTree btree;
  parseProgram(program,btree);
  return 0;
}

void printProgram(string program)
{
  /// a single line
  string line;
  /// for counting the lines
  int count = 0;
  /// where the newline is (for peeling off a line)
  int pos;

  while ( string::npos != (pos = program.find("\n") ) )
    {
      line = program.substr(0, pos);    /// before the newline
      program = program.substr(pos+1);  /// after the newline
      /// there might newline characters at the end of line
      if (line[pos] < '0') line.erase(pos-1);


      /// here's where you need to process 'line'
      /// this routine just prints it.
      //cout << ++count << ": [" << line << "] len=" << line.size()<< "<br />" << endl;
    }

}

void parseProgram(string program, BinarySearchTree& btree)
{
  string line;
  int count = 0;
  int pos;
  while ( string::npos != (pos = program.find("\n") ) )
    {
      line = program.substr(0, pos);
      program = program.substr(pos+1);
      /*if (line[pos] < '0')
		  line.erase(pos-1);*/
	  parse(line,btree);
      cout << ++count << ": [" << line << "] len=" << line.size()<< "<br />" << endl;
    }
}

void parse(string line, BinarySearchTree& btree)
{
	if (line.substr(0,6) == "INSERT")
		{
			int commaPos = line.find(",");
			string value, str;
			value = line.substr(7,commaPos);
			str = line.substr(commaPos+2);
			// convert string to integer;
			int key = atoi(value.c_str());
			btree.insert(make_pair(key,str));
		}
	else if (line == "POSTORDER")
		{
			if (btree.empty())
			{
				cerr << "Empty tree." << endl;
			}
			btree.postorder();
		}
	else if (line == "PREORDER")
		{
			if (btree.empty())
			{
				cerr << "Empty tree." << endl;
			}
			btree.preorder();
		}
	else if (line == "INORDER")
		{
			if (btree.empty())
			{
				cerr << "Empty tree." << endl;
			}
			btree.inorder();
		}

    else if (line == "PRINT")
		{
			btree.print();
		}
	else
	{
		cerr << "Error: invalid command " << line << endl;
		exit(1);
	}
        return;
}

void BinarySearchTree::print()
{
    if (empty())
    {
        std::cout << "Empty Tree" << std::endl;
    }
    else
    {
        printHelper(m_Root);
    }

}

void BinarySearchTree::printHelper(Node* n)
{
    if (n == NULL) return;

    /// in order traversal of the tree
    printHelper(n->left);
    std::cout << n->data.first << ", " << n->data.second << endl;
    printHelper(n->right);
}

void BinarySearchTree::insert(pair<int, string> data)
{
    insertHelper(m_Root, data);
}

void BinarySearchTree::insertHelper(Node* &n, pair<int, string> data)
{
	// insert 'data' into a tree pointed to by 'n'
	// if n is null, it goes here
	if (n == NULL)
	{
		n = new Node;
		n->data.first = data.first;
		n->data.second = data.second;
		n->left = NULL;
		n->right = NULL;
		return;
	}
	// n is not null, so we can check left & right
	if (data.first < n->data.first)
	{
		insertHelper(n->left,data);
	}
	else if ((data.first == n->data.first) && data.second < n->data.second)
	{
		insertHelper(n->left,data);
	}
	else
	{
		insertHelper(n->right,data);
	}
}

void BinarySearchTree::inorder()
{
    if (empty())
    {
        std::cout << "Empty Tree" << std::endl;
    }
    else
    {
        inorderHelper1(m_Root);
		cout << endl;
		inorderHelper2(m_Root);
    }

}

void BinarySearchTree::inorderHelper1(Node* n)
{
    if (n == NULL) return;

    /// in order traversal of the tree
    inorderHelper1(n->left);
    std::cout << n->data.first << " " ;
    inorderHelper1(n->right);
}



void BinarySearchTree::inorderHelper2(Node* n)
{
    if (n == NULL) return;

    /// in order traversal of the tree
    inorderHelper2(n->left);
    std::cout << n->data.second << " ";
    inorderHelper2(n->right);
}

void BinarySearchTree::preorder()
{
    if (empty())
    {
        std::cout << "Empty Tree" << std::endl;
    }
    else
    {
        preorderHelper1(m_Root);
		cout << endl;
		preorderHelper2(m_Root);
    }

}


void BinarySearchTree::preorderHelper1(Node* n)
{
    if (n == NULL) return;

    /// pre order traversal of the tree
    std::cout << n->data.first << " " ;
    preorderHelper1(n->left);
    preorderHelper1(n->right);
}

void BinarySearchTree::preorderHelper2(Node* n)
{
    if (n == NULL) return;

    /// pre order traversal of the tree
    std::cout << n->data.second << " " ;
    preorderHelper2(n->left);
    preorderHelper2(n->right);
}

void BinarySearchTree::postorder()
{
    if (empty())
    {
        std::cout << "Empty Tree" << std::endl;
    }
    else
    {
        postorderHelper1(m_Root);
		cout << endl;
		postorderHelper2(m_Root);
    }

}

void BinarySearchTree::postorderHelper1(Node* n)
{
    if (n == NULL) return;

    /// post order traversal of the tree
    postorderHelper1(n->left);
    postorderHelper1(n->right);
    std::cout << n->data.first << " ";
}
void BinarySearchTree::postorderHelper2(Node* n)
{
    if (n == NULL) return;

    /// post order traversal of the tree
    postorderHelper2(n->left);
    postorderHelper2(n->right);
    std::cout << n->data.second <<" ";
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other)
{
    m_Root = copyHelper(other.m_Root);
}

Node* BinarySearchTree::copyHelper(Node* oldNode)
{
    if (oldNode == NULL) return NULL;
    /// otherwise build a new node
    Node* newNode = new Node();
    newNode->data.first = oldNode->data.first;
	newNode->data.second = oldNode->data.second;
    newNode->left = copyHelper(oldNode->left);
    newNode->right = copyHelper(oldNode->right);
    return newNode;

}

void BinarySearchTree::eraseHelper(Node* n)
{
  if (!n) return;
  eraseHelper(n->left);
  eraseHelper(n->right);
  delete n;
  return;
}

