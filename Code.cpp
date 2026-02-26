#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    struct Tracker 
    {
        std::string name;
        int priority;
    };
    std::vector<Tracker> taskList;

    Tracker Task; 
    if (taskList.empty())
    {
        int x = 0;
        while(x == 0)
        {
        std::cout << "No tasks in the list. Do you want to add a task?: " << std::endl;
        getline(std::cin, Task.name);

            if (Task.name == "No" || Task.name == "no"|| Task.name == "Nah" || Task.name == "nah" || Task.name == "Nope" || Task.name == "nope"|| Task.name == "Negative" || Task.name == "negative")
            {
                std::cout << "No task added. " << std::endl; //If user chooses not to add a task, the program will end.
                return x = 1;
            }
            else if (Task.name == "Yes" || Task.name == "yes" || Task.name == "Yup" || Task.name == "yup" || Task.name == "Sure" || Task.name == "sure" || Task.name == "Yeah" || Task.name == "yeah")
            {//if user chooses to add a task, the program will prompt them to enter the task name and priority, and then add it to the task list.
                std::cout << "How many tasks do you want to add?: ";
                std::cin >> x;
                for( int i = 0; i < x; i++)
                {
                    std::cout << "Please enter the task name (Or 'quit' to stop adding tasks): "; 
                    std::cin >> Task.name;

                    if (Task.name == "quit")
                    {
                        std::cout<< "Exiting Task Creation." << std::endl;
                        break;
                    }
                    else
                    {
                    std::cout << "Please enter the task priority (1-100): ";
                    std::cin >> Task.priority;

                    std::cout << "Task added: " << Task.name << " Priority: " << Task.priority << std::endl;
                    taskList.push_back(Task);
                    }
                }
                return x = 1;
            }
            else
            {
                std::cout << "Invalid input. Please enter a definitive answer (Yes/No)." << std::endl;
                
            }
        }
    }
    return 0;
}
