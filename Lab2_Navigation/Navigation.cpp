#include "Navigation.h"

Navigation::Navigation() {
    cout << "** in Navigation constructor **" << endl;
}

Navigation::~Navigation() {
    cout << "** in Navigation deconstructor **" << endl;
}

bool Navigation::readNetwork(string _mapName) {
    cout << "** in Navigation readNetwork() **" << endl;
    return 0;
}

queue<int> Navigation::computeShortestPath(int _startInd, int _endInd) {
    cout << "** in Navigation computeShortestPath() **" << endl;
    queue<int> paths;
    return paths;
}

void Navigation::printPath(queue<int> _path) {
    cout << "** in Navigation printPath() **" << endl;
}