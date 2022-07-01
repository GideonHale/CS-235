#include "Navigation.h"

Navigation::Navigation() {
    // cout << "** in Navigation constructor **" << endl;
}

Navigation::~Navigation() {
    // cout << "** in Navigation deconstructor **" << endl;
}

bool Navigation::readNetwork(string _mapName) {
    // cout << "** in Navigation readNetwork() **" << endl;

    ifstream inFile;
    inFile.open(_mapName);
    if (inFile.is_open()) {
        inFile >> numNodes;
        costs.resize(numNodes);
        for (int i = 0; i < costs.size(); i++) {
            costs.at(i).resize(numNodes);
            for (int j = 0; j < costs.at(i).size(); j++) {
                inFile >> costs.at(i).at(j);
            }
        }
        inFile.close();

        // cout << "Adjacency Matrix:" << endl;
        // for (int i = 0; i < numNodes; i++) {
        //     for (int j = 0; j < numNodes; j++) {
        //         cout << costs.at(i).at(j) << "  ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    } else {
        cout << "** Requested file could not be opened **";
    }
    
    return 0;
}

queue<int> Navigation::computeShortestPath(int _startInd, int _endInd) {
    // cout << "** in Navigation computeShortestPath() **" << endl;

    priority_queue< Node, vector<Node>, Node > prQueue;
    Node n;
    n.cost = 0;
    n.path.push(_startInd);
    prQueue.push(n);

    try {
        while (prQueue.top().path.back() != _endInd) {        
            Node current = prQueue.top();
            prQueue.pop();
            int last = current.path.back();
            for (int j = 0; j < costs.size(); j++) {
                if (costs.at(last).at(j) >= 0) {
                    Node nNext;
                    nNext.cost = current.cost + costs.at(last).at(j);
                    nNext.path = current.path;
                    nNext.path.push(j);
                    prQueue.push(nNext);
                }
            }
        }
    } catch (...) {
        cout << "** The parameters given could not be applied to the map **" << endl << endl;
    }

    return prQueue.top().path;
}

void Navigation::printPath(queue<int> _path) {
    // cout << "** in Navigation printPath() **" << endl;

    int totCost = 0;
    bool noError;

    try {
        costs.at(_path.back());
        cout << "Best path from " << _path.front() << " to " << _path.back() << ": ";
    } catch (...) {
        noError = false;
    }
    
    if (noError) {
        for (int i = 0; !_path.empty(); i++) {
            cout << _path.front() << " ";
            int initFront = _path.front();
            _path.pop();
            
            try {
                if (costs.at(initFront).at(_path.front()) >= 0) {
                    totCost += costs.at(initFront).at(_path.front());
                }
            } catch (...) {
                noError = false;
            }
        }
        cout << endl;
        if (noError) {
            cout << "Total cost: " << totCost << endl << endl;
        } else {
            cout << "** The total cost could not be determined **" << endl << endl;
        }
    }
}