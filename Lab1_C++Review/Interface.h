#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>

using namespace std;

class interface {
public:
    // Writes data from TodoList.txt to vector 'tasks'
    interface() {}

    // Writes date from vector 'tasks' to TodoList.txt
    virtual ~interface() {}

    // Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    virtual void add(string _duedate, string _task) = 0;

    // Removes an item from the todo list with the specified task name
    virtual void remove(string _task) = 0;

    // Prints out all items of a todo list with a particular due date (specified by _duedate)
    virtual void printDaysTasks(string _date) = 0;

    // Prints out the full todo list to the console
    virtual void printTodoList() = 0;
};

#endif