// INPUT A MAZE TO THE INPUT.TXT file and print out its graph form for 
// path finding

#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <iomanip>
using namespace std;



int** connections(int size, int **m)
{
    int n = size * size;

    int **arr = new int*[n];
    for(int i = 0; i < n; i++)
        arr[i] = new int[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = 0;

    for(int r = 0; r < size; r++)
    {

        for(int c = 0; c < size; c++)
        {
            if(m[r][c] != 0)
            {
                if(r-1 >= 0 && m[r-1][c] == 1) // up;
                    arr[(size*r)+c][((size*r)+c)-size] = 1;

                if(r+1 < size && m[r+1][c] == 1) // down
                    arr[(size*r)+c][((size*r)+c)+size] = 1;

                if(c-1 >= 0 && m[r][c-1] == 1) // left
                    arr[(size*r)+c][((size*r)+c)-1] = 1;

                if(c+1 < size && m[r][c+1] == 1) //right
                    arr[(size*r)+c][((size*r)+c)+1] = 1;

                if((r-1 >= 0 && c-1 >= 0) && m[r-1][c-1] == 1) //top left
                    arr[(size*r)+c][((size*r)+c)-size-1] = 1;

                if((r-1 >= 0 && c+1 < size) && m[r-1][c+1] == 1) // top right
                    arr[(size*r)+c][((size*r)+c)-size+1] = 1;

                if((r+1 < size && c-1 >= 0) && m[r+1][c-1] == 1) //bottom left
                    arr[(size*r)+c][((size*r)+c)+size-1] = 1;

                if((r+1 < size && c+1 < size) && m[r+1][c+1] == 1) //bottom right
                    arr[(size*r)+c][((size*r)+c)+size+1] = 1;
            }
        }
    }


    // for(int i = 0; i < n; i++)
    // {   
    //     for(int j = 0;j < n; j++)
    //     {
    //         if(arr[i][j] != 0)
    //             cout << arr[i][j] << " ";
    //         else
    //             cout << '-' << " ";
    //     }
    //     cout << endl;
    // }

    return arr;
    
}


void path(int size, int **m, int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int distance[size];
    for(int i = 0; i < size; i++)
        distance[i] = INT_MAX;

    distance[src] = 0;

    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < size; i++)
        {
            int v = i;
            int weight = m[u][i];
            if(m[u][i] != 0)
            {
                if(distance[v] > distance[u]+ weight)
                {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v],v));
                }
            }
        }
    }
    cout.width(6);

    cout << left << "src";
    cout << "destination";
    cout.width(12);
    cout << right << "distance" << endl;
    for(int i = src+1; i < size; i++) {
        // char next = start+i-src;
        cout << setw(0) << setfill(' ');
        if(distance[i] != INT_MAX)
        {   
        std::cout << src <<  setw(10) << right << i << "\t\t " <<  distance[i] << std::endl;
        // cout << setw(30) << setfill('-') << "-" << endl;

        }
    }
    std::cout << std::endl;
    cout << endl;
}



int main() 
{


    cout << "Using dijkstra's algorithm to find shortest path from one point to another from inputed maze" << endl;




    int size;

    fstream input("input.txt");

    input >> size;
    input.ignore();





    int **m = new int*[size];
    for(int i = 0; i < size; i++)
        m[i] = new int[size];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            m[i][j] = 0;
    
    
    int i = 0;
    string line;
    while(getline(input,line))
    {
        line.erase(remove(line.begin(),line.end(),'\r'),line.end());
        line.erase(remove(line.begin(),line.end(),'\n'),line.end());

        int p = 0;
        int j = 0;
        istringstream ss(line);
        while(ss >> p)
        {
            m[i][j] = p;
            j++;
        }
        i++;
    }

    

    int **a = connections(size,m);
    for(int i = 0; i < size*size; i++)
        {   
            for(int j = 0;j < size*size; j++)
            {
                if(a[i][j] != 0)
                    cout << a[i][j] << " ";
                else
                    cout << '-' << " ";
            }
            cout << endl;
        }

    path(size*size,a,1);
    
    return 0;
}