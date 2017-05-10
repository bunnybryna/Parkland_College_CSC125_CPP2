#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>

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
		void preorderHelper(Node* n);
		void inorderHelper(Node* n);
		void postorderHelper(Node* n);
		Node* copyHelper(Node* oldNode);
		void eraseHelper(Node* n);
		Node* m_Root;
};


int main()
{
    Node n,m;
	n.data = make_pair(1,"Bryna");
	cout << n.data.first << n.data.second << endl;
	m.data = make_pair(2,"Zhao");
	cout << m.data.first << m.data.second << endl;
    BinarySearchTree strBST;
    strBST.insert(make_pair(25,"Bryna"));
    strBST.insert(make_pair(15,"Bryna"));
    strBST.insert(make_pair(50,"Bryna"));
    strBST.insert(make_pair(10,"Bryna"));
    strBST.insert(make_pair(22,"Bryna"));
    strBST.insert(make_pair(35,"Bryna"));
    strBST.insert(make_pair(70,"Bryna"));
    strBST.insert(make_pair(4,"Bryna"));	
    strBST.insert(make_pair(12,"Bryna"));
    strBST.insert(make_pair(18,"Bryna"));
    strBST.insert(make_pair(24,"Bryna"));	
    strBST.insert(make_pair(31,"Bryna"));	
    strBST.insert(make_pair(44,"Bryna"));
    strBST.insert(make_pair(66,"Bryna"));
    strBST.insert(make_pair(90,"Bryna"));
    strBST.print();

    cout << "Traversals:" << endl;
    cout << "preorder: ";
    strBST.preorder();
    cout << endl;

    cout << "inorder: ";
    strBST.inorder();
    cout << endl;

    cout << "postorder: ";
    strBST.postorder();
    cout << endl;

   

    return 0;
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
        inorderHelper(m_Root);
    }

}

void BinarySearchTree::inorderHelper(Node* n)
{
    if (n == NULL) return;

    /// in order traversal of the tree
    inorderHelper(n->left);
    std::cout << n->data.first << ", " << n->data.second << endl;
    inorderHelper(n->right);
}

void BinarySearchTree::preorder()
{
    if (empty())
    {
        std::cout << "Empty Tree" << std::endl;
    }
    else
    {
        preorderHelper(m_Root);
    }

}


void BinarySearchTree::preorderHelper(Node* n)
{
    if (n == NULL) return;

    /// pre order traversal of the tree
    std::cout << n->data.first << ", " << n->data.second << endl;
    preorderHelper(n->left);
    preorderHelper(n->right);
}

void BinarySearchTree::postorder()
{
    if (empty())
    {
        std::cout << "Empty Tree" << std::endl;
    }
    else
    {
        postorderHelper(m_Root);
    }

}

void BinarySearchTree::postorderHelper(Node* n)
{
    if (n == NULL) return;

    /// post order traversal of the tree
    postorderHelper(n->left);
    postorderHelper(n->right);
    std::cout << n->data.first << ", " << n->data.second << endl;
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

