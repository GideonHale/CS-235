#include "TodoList.h"

// Writes data from TodoList.txt to vector 'tasks'
TodoList::TodoList() {
    ifstream inFile("TodoList.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            tasks.push_back(line);
        }
        inFile.close();
    }
}

// Writes date from vector 'tasks' to TodoList.txt
TodoList::~TodoList() {
    ofstream outFile("TodoList.txt", ofstream::out | ofstream::trunc);
    for (int i = 0; i < tasks.size(); i++) {
        outFile << tasks.at(i) << endl;
    }
    outFile.close();
}

// Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
void TodoList::add(string _duedate, string _task) {
    cout << "Adding Task\t-- " << _duedate << ": " << _task << endl;
    tasks.push_back(_duedate + ": " + _task);
}

// Removes an item from the todo list with the specified task name
void TodoList::remove(string _task) {
    int remvIndex;
    bool found = false;
    for (int i = 0; i < tasks.size() && !found; i++) {
        if (tasks.at(i).find(_task) != string::npos) {
            remvIndex = i;
            found = true;
            cout << "Removing Task\t-- " << tasks.at(i) << endl;
            tasks.erase(tasks.begin() + remvIndex); // If there are multiple with the same name, only the first will be deleted
        }
    }
    if (!found) {
        cout << "** There was no task found called \"" << _task << "\" **" << endl;
    }
}

// Prints out all items of a todo list with a particular due date (specified by _duedate)
void TodoList::printDaysTasks(string _date) {
    bool found = false;
    cout << "Items on " << _date << ":" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks.at(i).find(_date) != string::npos) {
            int _taskStartIndex = _date.size() + 2;
            string _task = tasks.at(i).substr(_taskStartIndex, tasks.at(i).at(tasks.at(i).size() - 1));
            cout << " - " << _task << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "** There were no tasks found on \"" << _date << "\" **" << endl;
    }
}

// Prints out the full todo list to the console
void TodoList::printTodoList() {
    // char box = \u2610;
    cout << "Printing To-Do List:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << "- " << tasks.at(i) << endl;
    }
}