#include "ArgumentManager.h"
#include "BST.h"
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  // Argument manager
  ArgumentManager am(argc, argv);
  ifstream inputFile(am.get("input"));
  ofstream outputFile(am.get("output"));
  // ifstream inputFile("input1.txt");
  // ofstream outputFile("output9.txt");

  string line;
  BST tree;
  while (inputFile >> line) {
    int num = stoi(line);
    tree.insert(num);
  }
  string content = tree.preOrder(tree.getRoot(), "[x]");
	cout << content << endl;
	outputFile << content.substr(0, content.length() - 1);

	inputFile.close();
	outputFile.close();
  return 0;
}