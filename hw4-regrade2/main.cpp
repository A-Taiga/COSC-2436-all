#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include "tree.h"
#include "instructions.h"
#include "priority_queue.h"
#include "ArgumentManager.h"

using namespace std;


void tokenize(string line, Node& node) {

    int split;
    split = line.find(':');
    node.command = line.substr(0,split);
    split = line.find('[')+1;
    node.info = line.substr(split,line.find_last_of(']')-split);
    split = line.find_last_of('(')+1;
    node.priority = stoi(line.substr(split,line.find_last_of(')')));
    
    if(node.command == "BST")
        node.info = "";
}


int main(int argc, char *argv[]) {
    ArgumentManager am(argc,argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    // ofstream output("testOut.txt");
    // ifstream input("hi.txt");

    tree t;
    myQ::priority_queue pq;
    string output_type;
    string line;

    while(getline(input,line)) {

        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());

        if(line.empty())
            continue;

        if(line == "Preorder") {
            output_type = "Preorder";
            break;
        } else if(line == "Postorder") {
            output_type = "Postorder";
            break;
        } else if(line == "Inorder") {
            output_type = "Inorder";
            break;
        }
        Node *temp = new Node();
        tokenize(line,*temp);
        pq.enqueue(temp);
    }

    queue<string> queue;
    packet *root = nullptr;

    int q_size = 0;
    while(!pq.empty()) {
        q_size = queue.size();
        if(pq.front()->command == "DECODE") {
            queue.push(pq.front()->info);
            pq.dequeue();
        } else if(!queue.empty() && pq.front()->command == "SWAP") {
            queue.push(swap(queue.front(),pq.front()->info));
            queue.pop();
            pq.dequeue();
        
        } else if(!queue.empty() && pq.front()->command == "REMOVE") {
            queue.push(remove(queue.front(),pq.front()->info));
                queue.pop();
            pq.dequeue();
        } else if(!queue.empty() && pq.front()->command == "ADD") {
            queue.push(add(queue.front(),pq.front()->info));
                queue.pop();
            pq.dequeue();
        } else if(!queue.empty() && pq.front()->command == "REPLACE") {
            queue.push(replace(queue.front(),pq.front()->info));
                queue.pop();
            pq.dequeue();
        } else if(!queue.empty() && pq.front()->command == "BST") {
            root = t.insert(root,new packet(queue.front(),queue.front().length()));
            queue.pop();
            pq.dequeue();
        }
        else {
            pq.dequeue();
        }
    }
    if(output_type == "Preorder") {
        t.preorder(output,root);
    } else if(output_type == "Inorder") {
        t.inorder(output,root);
    } else if(output_type == "Postorder") {
        t.postorder(output,root);
    }
    return 0;
}



