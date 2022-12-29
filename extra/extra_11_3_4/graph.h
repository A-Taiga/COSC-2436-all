#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <cmath>
#include "list.h"
#include "iomanip"

struct vertex {
    std::string key;
    std::string abv;
    int val;
    list *l;
    vertex(std::string _key = "", std::string _abv = "", int _val = -1):key(_key),abv(_abv),val(_val),l(nullptr){}
};

class graph {

private:
    int size;
    int last_i;
    std::string *keys;
    int map_size;
    vertex **map;

    int hasher(std::string _str);
    int find_prime(int arr[], int low, int high, int val);
    int find(std::string key);



public:
    graph(int size);
    void add(std::string str, std::string abv);
    void link(std::string src, std::string dest, int weight);
    void print()
    {   
        std::cout << std::endl;
        std::cout << "Graph of the Continental United States" << std::endl;
        std::cout << "using an adjaciency list and hash map for key value pairs" << std::endl;
        std::cout << "States with their weights are on the right" << std::endl;
        for(int i = 0; i < 100; i++)
                std::cout << "━";
        std::cout << std::endl;
        std::cout << std::left;
        for(int i = 0; i < last_i; i++)
        {
            std::cout.width(15);
            std::cout << keys[i] << " : ";

            int key_i = find(keys[i]);
            if(map[key_i]->l != nullptr)
            {
                Node *cu = map[key_i]->l->get_head();
                while(cu != nullptr)
                {
                    std::cout << std::left << cu->abv << " " << cu->val << " ┃ ";
                    cu = cu->next;
                }

            }
            std::cout << std::left << std::endl;
            for(int i = 0; i < 100; i++)
                std::cout << "━";
            std::cout << std::endl;

        }
    }
};



#endif