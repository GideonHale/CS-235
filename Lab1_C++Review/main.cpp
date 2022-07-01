#include "TodoList.h"

// Redundant libraries:
// #include <iostream>
// #include <string>
// #include <vector>
// #include <fstream>

void helpFull();

void helpTag();

int main(int argc, char *argv[]) {
    Interface* myList = new TodoList;
    string date;
    string task;
    string cmdArg = argv[1];

    if (2 <= argc <= 4) {
        if (cmdArg.compare("add") == 0) {
            date = argv[2];
            task = argv[3];
            myList->add(date, task);
            helpTag();
        } else if (cmdArg.compare("remove") == 0) {
            task = argv[2];
            myList->remove(task);
            helpTag();
        } else if (cmdArg.compare("printList") == 0) {
            myList->printTodoList();
            helpTag();
        } else if (cmdArg.compare("printDay") == 0) {
            date = argv[2];
            myList->printDaysTasks(date);
            helpTag();
        } else if (cmdArg.compare("help") == 0) {
            helpFull();
        } else {
            cout << "That is not a recognized command" << endl;
            helpTag();
        }
    } else if (argc > 4) {
        cout << "There are too many arguments" << endl;
        helpTag();
    }

    delete myList;

    return 0;
}


void helpFull() {
    cout << "printList\t\t-- print all tasks on the to-do ist" << endl;
    cout << "printDay [date]\t\t-- list all tasks on a single day" << endl;
    cout << "add [date] [task]\t-- add a new task to the to-do list" << endl;
    cout << "remove [task]\t\t-- remove a task from the to-do list" << endl;
}

void helpTag() {
    cout << endl << "** For assistance type \"help\" **" << endl;
}