#include<iostream>
#include<string>
using namespace std;
class BinaryTree
{
private:
    /* data */
     string value;
     struct BinaryTree *lchild,*rchild;
public:
    BinaryTree(string v);
    ~BinaryTree();
};

BinaryTree::BinaryTree(string v)
{
    this->value = v;
}

BinaryTree::~BinaryTree()
{
    
}
