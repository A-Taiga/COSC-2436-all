#include <fstream>
#include <iostream>
using namespace std;
struct node {
  string id;
  node *next;
};
class list {
private:
  node *head;
  int size;

public:
  list() : head(nullptr), size(0) {}
  void add(node *n, string decoded) {
    if (n == 0) {
      node *temp = new node;
      temp->id = decoded;
      temp->next = nullptr;
      head = temp;
      size++;
      return;
    } else {
      node *temp = new node;
      temp->id = decoded;
      temp->next = head;
      head = temp;
      size++;
      return;
    }
    add(n->next, decoded);
  };
  void remove(node *n, string s) {
    if (n == 0)
      return;

    if (n->id == s) {
      size--;
      head = n->next;
      delete n;
      return;
    }

    if (n->next != 0 && n->next->id == s) {
      size--;
      node *temp = n->next;
      n->next = n->next->next;
      delete temp;
      return;
    }
    remove(n->next, s);
  };
  void sort(node *n) {
    if (n == 0 || n->next == 0)
      return;
    node *curr = n;
    node *min = findMin(n);
    swap(curr, min);
    sort(n->next);
  };

  void swap(node *curr, node *min) {
    if (curr == 0 || min == 0)
      return;
    string temp = curr->id;
    curr->id = min->id;
    min->id = temp;
  };

  node *getHead() { return head; };

  node *findMin(node *n) {
    if (n == 0)
      return 0;
    string min = process(n->id);

    node *ans = 0;
    while (n != 0) {
      string temp = process(n->id);
      if (compare(temp, min) < 0) {
        min = temp;
        ans = n;
      }
      n = n->next;
    }
    return ans;
  };

  int compare(string a, string b) {
    if (a.length() != b.length())
      return a.length() - b.length();
    for (int i = 0; i < a.length(); i++) {
      if (a[i] == b[i])
        continue;
      else
        return ((int)a[i] - (int)b[i]);
    }
    return 0;
  }

  string process(string s) {
    while (s[0] == '0')
      s = s.substr(1);
    return s;
  }
  int getSize() { return size; }
  void print(ofstream &a, node *h) {
    if (h == nullptr) {
      return;
    }
    cout << h->id << endl;
    a << h->id << endl;
    print(a, h->next);
  };
};
