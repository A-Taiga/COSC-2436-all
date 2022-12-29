#include "tree.h"


void tree::insert(int data) {
    if(root == nullptr) {
      root = new Node(degree);
      root->keys[0] = data;
      root->size += 1;
    }
    else{
      addAtLeaf(nullptr, root, data);
    }
  }
void tree::addAtLeaf(Node* parent, Node* n, int data) {
  if(n->leaf) {
    int i = n->size;
    while(i != 0 && n->keys[i-1] > data) {
      n->keys[i] = n->keys[i-1];
      i--;
    }
    n->keys[i] = data;
    n->size += 1;
  }
  else {
    int i = 0;
    while (i < n->size && data > n->keys[i]) {
      i++;
    }
    addAtLeaf(n, n->childptr[i], data);
  }
  if(n->size == degree) {
    if(n == root) {
      Node* temp = new Node(degree);
      temp->leaf = false;
      temp->childptr[0] = n;
      splitChild(temp, n);
      root = temp;
    }
    else
      splitChild(parent, n);
  }
}
void tree::splitChild(Node *parent, Node *leftNode) {
    Node *rightNode = new Node(degree);
    int mid = (degree - 1) / 2;
    int carry = leftNode->keys[mid];
    int size = leftNode->size;
    // copy half of the key from left node to right node;
    for (int i = mid + 1; i < size; i++) {
      rightNode->keys[i - mid - 1] = leftNode->keys[i];
      leftNode->size--;
      rightNode->size++;
    }
    // check if the node is a leaf node or not, if it is not a leaf node copy
    // half the pointer from left node to right node

    int index = 0;
    if (!leftNode->leaf) {
      for (int i = int(ceil(float(degree) / 2)); i <= degree; i++) {
        rightNode->childptr[index] = leftNode->childptr[i];
        leftNode->childptr[i] = nullptr;
        index++;
      }
      rightNode->leaf = leftNode->leaf;
    }
    // find the correct index to add the right node
    int i = degree - 1;
    while (parent->childptr[i] != leftNode) {
      parent->childptr[i + 1] = parent->childptr[i];
      i--;
    }
    parent->childptr[i + 1] = rightNode;
    // add the midle key to the parent
    i = degree;
    while (parent->keys[i - 1] == -1 && i != 0)
      i--;

    while (parent->keys[i - 1] > leftNode->keys[mid] && i != 0) {
      parent->keys[i] = parent->keys[i - 1];
      i--;
    }

    parent->keys[i] = carry;
    // cout << leftNode->keys[mid] << " Mid " << endl;
    parent->size += 1;
    leftNode->size -= 1;
  }
    void tree::print_level(int level, std::ofstream &out)
    {
        int curr_level = 0;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();
                for(int k = 0; k < temp->size; k++)
                  if(curr_level == level-1)
                    out << temp->keys[k] << " ";

                for(int j = 0; j < degree; j++)
                    if(temp->childptr[j] != nullptr)
                        q.push(temp->childptr[j]);
            }
            curr_level++;
        }
    }
  