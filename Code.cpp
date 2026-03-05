#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

//All functions
void displayTasks();
void displayNotes();
void displayDiagram();
void displayTracker();
void createTasks();
void createNotes();
void createDiagram();
void createTracker();
void displayMenu();

//All structs
struct User_Interface
{
std::string function;
    void (*displayFunction)();

};
struct TaskManager 
{
    std::string name;
    int priority;
};

//Global variables
std::vector<TaskManager> taskList;

//UI arrays and pointers
User_Interface Tasks[] = 
    {
        {"View tasks", displayTasks},
        {"Create tasks", createTasks}
    };
User_Interface Notes[] = 
    {
        {"View notes", displayNotes},
        {"Create notes", createNotes}
    };
User_Interface Diagram[] = 
    {
        {"View diagram", displayDiagram},
        {"Create diagram", createDiagram}
    };
User_Interface Tracker[] = 
    {
        {"View tracker", displayTracker},
        {"Create tracker", createTracker}
    };
User_Interface Main_Menu[] = 
    {
        {"Menu", displayMenu}
    };
User_Interface* UI[] = 
    {
        Main_Menu,
        Tasks,
        Notes,
        Tracker,
        Diagram
    };
std::string UI_Names[] = 
    {
        "Main Menu",
        "Tasks",
        "Notes",
        "Tracker",
        "Diagram"
    };
int UI_Size[] = 
    {
        1,2,2,2,1 // Size of each UI array
    }; 
User_Interface* Current_UI = UI[0]; // Set the current UI to Main Menu by default
int current_Size = UI_Size[0]; // Set the current size to the size of the Main Menu UI
int current_UI_index = 0; // Set the current UI index to 0 (Main Menu)
int main()
{
    while(true)
    {
        std::string input;
        std::cout << "Welcome to the Productivity Manager! Please select an option from the menu: " << std::endl;
        int index = 0;
        for(const auto& name : UI_Names)
        {
            std::cout << index++ << ") " << name << std::endl;
        }
        getline(std::cin, input);
        int numInput = std::stoi(input);
        if (numInput == 0)
        {
            Current_UI = UI[0];
            current_Size = UI_Size[0];
            current_UI_index = 0;
            displayMenu();
            
        }
        else if (numInput == 1)
        {
            Current_UI = UI[1];
            current_Size = UI_Size[1];
            current_UI_index = 1;
            displayTasks();
            
        }
        else if (numInput == 2)
        {
            Current_UI = UI[2];
            current_Size = UI_Size[2];
            current_UI_index = 2;
            displayNotes();
            
        }
        else if (numInput == 3)
        {
            Current_UI = UI[3];
            current_Size = UI_Size[3];
            current_UI_index = 3;
            displayTracker();
            
        }
        else if (numInput == 4)
        {
            Current_UI = UI[4];
            current_Size = UI_Size[4];
            current_UI_index = 4;
            displayDiagram();
            
        }
        else
        {
            std::cout << "Invalid input. Please enter a valid option from the menu." << std::endl;
        }
    }
}

void displayTasks() 
{
    while(true)
    {
        std::string taskInput;
        std::cout<< "You have selected Tasks. Do you wish to make new tasks or view existing ones?(View Tasks/ Create Tasks/ Exit Tasks) " << std::endl;
        getline(std::cin, taskInput);
        if (taskInput == "View Tasks" || taskInput == "view tasks" || taskInput == "VIEW TASKS"|| taskInput == "View tasks" || taskInput == "view Tasks")
        {
            while(true)
            {
                while(taskList.empty())
                {
                    std::cout << "No tasks in the list. Do you want to add a task?: " << std::endl;
                    std::string input;
                    getline(std::cin, input);

                        if (input == "No" || input == "no"|| input == "Nah" || input == "nah" || input == "Nope" || input == "nope"|| input == "Negative" || input == "negative")
                        {
                            std::cout << "No task added. Returning to Tasks menu..." << std::endl; //If user chooses not to add a task, the program will return to the Tasks menu.
                            return;
                        }
                        else if (input == "Yes" || input == "yes" || input == "Yup" || input == "yup" || input == "Sure" || input == "sure" || input == "Yeah" || input == "yeah")
                        {
                            createTasks();
                        }
                        else
                        {
                            std::cout << "Invalid input. Please enter a definitive answer (Yes/No)." << std::endl;
                            continue;
                        }
                }
                std::cout << "Here are your tasks: " << std::endl;
                for (const auto& task : taskList)
                {
                    std::cout << "Task: " << task.name << " Priority: " << task.priority << std::endl;
                }
                break;
            }
        }
        else if (taskInput == "Create Tasks" || taskInput == "create tasks" || taskInput == "CREATE TASKS" || taskInput == "Create tasks" || taskInput == "create Tasks")
        {
            TaskManager TaskInput;
            std::cout << "How many tasks do you want to add?: ";
                int x;
                std::cin >> x;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character left in the stream
                for( int i = 0; i < x; i++)
                {
                    std::cout << "Please enter the task name (Or 'quit' to stop adding tasks): "; 
                    std::getline(std::cin, TaskInput.name);

                    if (TaskInput.name == "quit")
                    {
                        std::cout<< "Exiting Task Creation." << std::endl;
                        break;
                    
                    }
                    else
                    {
                    std::cout << "Please enter the task priority (1-100): ";
                    std::cin >> TaskInput.priority;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character left in the stream 
                    while (TaskInput.priority < 1 || TaskInput.priority > 100)
                    {
                    std::cout << "Invalid priority. Please enter a number between 1 and 100." << std::endl;
                    std::cin >> TaskInput.priority;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character left in the stream 
                    continue;
                    }

                    std::cout << "Task added: " << TaskInput.name << " Priority: " << TaskInput.priority << std::endl;
                    taskList.push_back(TaskInput);
                    }
                }
            }


        else if(taskInput == "Exit Tasks" || taskInput == "exit tasks" || taskInput == "EXIT TASKS" || taskInput == "Exit tasks" || taskInput == "exit Tasks")
        {
            std::cout << "You have exited the Tasks UI. Returning to main menu..." << std::endl;
            Current_UI = UI[0];
            current_Size = UI_Size[0];
            current_UI_index = 0;   
        }
        else
        {
            std::cout << "Invalid input. Please enter 'View Tasks', 'Create Tasks', or 'Exit Tasks'." << std::endl;
        }
    }
}

void displayMenu()
{

}


void displayNotes() 
{

}

void displayDiagram() 
{

}

void displayTracker() 
{

}
void createTasks() 
{

}

void createNotes() 
{

}
void createDiagram() 
{

}

void createTracker() 
{

}

/*void displayCalendar() {
for the far future, currently: 03/04/2026
}*/
