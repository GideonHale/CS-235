#include "TodoList.h"

// Redundant libraries:
// #include <iostream>
// #include <string>
// #include <vector>
// #include <fstream>

void helpFull(); // To reduce clutter in 'main'

void helpTag();

int main(int argc, char *argv[]) {
    TodoList myList;
    string date;
    string task;
    string cmdArg = argv[1];

    if (cmdArg.compare("add") == 0) {
        date = argv[2];
        task = argv[3];
        myList.add(date, task);
        helpTag();
    } else if (cmdArg.compare("remove") == 0) {
        task = argv[2];
        myList.remove(task);
        helpTag();
    } else if (cmdArg.compare("printList") == 0) {
        myList.printList();
        helpTag();
    } else if (cmdArg.compare("printDay") == 0) {
        date = argv[2];
        myList.printDay(date);
        helpTag();
    } else if (cmdArg.compare("help") == 0) {
        helpFull();
    } else {
        cout << "That is not a recognized command" << endl;
        helpTag();
    }

    return 0;
}


void helpFull() {
    cout << "add [date] [task]\t-- add a new task to the to-do list" << endl;
    cout << "remove [task]\t\t-- remove a task from the to-do list" << endl;
    cout << "printDay [date]\t\t-- list all tasks on a single day" << endl;
    cout << "printList\t\t-- print all tasks on the to-do ist" << endl;
}

void helpTag() {
    cout << endl << "** For assistance type \"help\" **" << endl;
}