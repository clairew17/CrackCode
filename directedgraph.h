#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
using namespace std;

#define PROB 60

// construct a directed graph has @size nodes.
vector<pair<int, int> > DirectedGraph(int size) {
    vector<pair<int, int> > result;
    srand(time(NULL));
    int direction = 0;
    pair<int, int> temp;
    for (int i = 0; i < size-1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (rand() % 100 < PROB) {
                direction = rand() % 2;
                if (direction)
                    temp = make_pair(i, j);
                else
                    temp = make_pair(j, i);
                result.push_back(temp);
            }
        }
    }
    return result;
}