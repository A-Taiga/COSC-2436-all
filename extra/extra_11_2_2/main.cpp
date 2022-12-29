// extra_11_2_2
// created map function to map the words of the first chapter of Moby Dick
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "map.cpp"

int main() {

    map<std::string> m;
    std::ifstream input("input.txt");
    std::string line;

    while(std::getline(input,line)) {
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());

        if(line.empty())
            continue;
        std::istringstream ss(line);
        std::string str;
        while(ss >> str) {
            std::string result = "";
            for(int i = 0; i < str.length(); i++) {
                
                if(ispunct(str[i])) {
                    if(str[i] == '\'')
                        result += std::tolower(str[i]);
                } else {
                    result += std::tolower(str[i]);
                }

            }
            m.insert(result);
        }
    }
    std::cout << std::endl;
    
    std::cout << "WORDS AND THEIR FREQUENCY FROM THE FIRST CHAPTER OF MOBY DICK" << std::endl;
    std::cout << "USING A CUSTOM MADE MAP CLASS USING AN AVL TREE" << std::endl;
    std::cout << std::endl;
    std::cout << "MAP HEIGHT: " << m.get_height() << std::endl;
    std::cout << "WORD COUNT: " << m.element_count() << std::endl;
    std::cout << std::endl;
    m.print();

    return 0;
}