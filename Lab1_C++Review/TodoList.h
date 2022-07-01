#ifndef TODO_LIST_H
#define TODO_LIST_H

#include "Interface.h"

#include <fstream>
#include <vector>

// Redundant libraries:
// #include <iostream>
// #include <string>

class TodoList: public interface {
public:
    // Writes data from TodoList.txt to vector 'tasks'
    TodoList();

    // Writes date from vector 'tasks' to TodoList.txt
    virtual ~TodoList();

    // Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    virtual void add(string _duedate, string _task);
    
    // Removes an item from the todo list with the specified task name
    virtual void remove(string _task);

    // Prints out all items of a todo list with a particular due date (specified by _duedate)
    virtual void printDaysTasks(string _date);
    
    // Prints out the full todo list to the console
    virtual void printTodoList();

private:
    vector<string> tasks;
};

#endif