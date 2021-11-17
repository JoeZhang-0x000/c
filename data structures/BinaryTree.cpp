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
    BinaryTree(/* args */);
    ~BinaryTree();
};

BinaryTree::BinaryTree(/* args */)
{
}

BinaryTree::~BinaryTree()
{
}
