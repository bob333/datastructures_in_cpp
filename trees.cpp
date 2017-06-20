#include <iostream>

using namespace std;

class Node
{
public:
  Node(int data) : left(0), right(0), data(data)
  {
  }

  friend ostream& operator<<(ostream &s, Node &n)
  {
    s<<"hello";
    return s;
  }

  void insertLeft(Node *left)
  {
    this->left = left;
  }

  void insertRight(Node *right)
  {
    this->right = right;
  }

  int height()
  {
    // count the height from the bottom up and then report
    int leftHeight = left ? left->height() + 1 : 0;
    int rightHeight = right ? right->height() + 1 : 0;
    return (leftHeight > rightHeight) ? leftHeight : rightHeight;
  }

private:
  Node *left;
  Node *right;
  int data;
};

int main()
{
  Node n(0);
  Node n1(1);
  Node n2(2);
  Node n3(3);
  Node n4(4);
  n.insertLeft(&n1);
  n1.insertLeft(&n2);
  n2.insertLeft(&n3);
  n2.insertRight(&n4);
  cout<<n.height();
}
