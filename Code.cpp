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
struct NoteManager
{
    std::string title;
    std::string content;
};

//Global variables
std::vector<TaskManager> taskList;
std::vector<NoteManager> noteList;

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
           createTasks();
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
{while(true)
    {
        std::string NoteInput;
        std::cout<< "You have selected Notes. Do you wish to make new notes or view existing ones?(View Notes/ Create Notes/ Exit Notes) " << std::endl;
        getline(std::cin, NoteInput);
        if (NoteInput == "View Notes" || NoteInput == "view notes" || NoteInput == "VIEW NOTES"|| NoteInput == "View notes" || NoteInput == "view Notes")
        {
            while(true)
            {
                while(noteList.empty())
                {
                    std::cout << "No notes in the list. Do you want to add a note?: " << std::endl;
                    std::string Notenput;
                    getline(std::cin, NoteInput);

                        if (NoteInput == "No" || NoteInput == "no"|| NoteInput == "Nah" || NoteInput == "nah" || NoteInput == "Nope" || NoteInput == "nope"|| NoteInput == "Negative" || NoteInput == "negative")
                        {
                            std::cout << "No note added. Returning to Notes menu..." << std::endl; //If user chooses not to add a note, the program will return to the Notes menu.
                            return;
                        }
                        else if (NoteInput == "Yes" || NoteInput == "yes" || NoteInput == "Yup" || NoteInput == "yup" || NoteInput == "Sure" || NoteInput == "sure" || NoteInput == "Yeah" || NoteInput == "yeah")
                        {
                            createNotes();
                        }
                        else
                        {
                            std::cout << "Invalid input. Please enter a definitive answer (Yes/No)." << std::endl;
                            continue;
                        }
                }
                std::cout << "Here are your notes: " << std::endl;
                for (const auto& note : noteList)
                {
                    std::cout << "Title: " << note.title << " Content: " << note.content << std::endl;
                }
                break;
            }
        }
        else if (NoteInput == "Create Notes" || NoteInput == "create notes" || NoteInput == "CREATE NOTES" || NoteInput == "Create notes" || NoteInput == "create Notes")
        {
            NoteManager NoteInput;
            std::cout << "How many notes do you want to add?: ";
                int y;
                std::cin >> y;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character left in the stream
                for( int i = 0; i < y; i++)
                {
                    std::cout << "Please enter the note title (Or 'exit' to stop adding notes): "; 
                    std::getline(std::cin, NoteInput.title);

                    if (NoteInput.title == "exit" || NoteInput.title == "Exit" || NoteInput.title == "EXIT")
                    {
                        std::cout<< "Exiting Note Creation." << std::endl;
                        break;
                    
                    }
                    else
                    {
                    std::cout << "Please enter the note's content: ";
                    std::getline(std::cin, NoteInput.content);
                    noteList.push_back(NoteInput);
                    }
                }
                    if (NoteInput.title == "exit" || NoteInput.content == "Exit" || NoteInput.title == "Exit" || NoteInput.content == "exit")
                    {
                        std::cout<< "Exiting Note Creation." << std::endl;
                        break;
                    
                    }
                    else
                    {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character left in the stream 
                    
                    std::cout << "Note added: " << NoteInput.title << " Content: " << NoteInput.content << std::endl;
                    noteList.push_back(NoteInput);
                    }
            }

        
        else if(NoteInput == "Exit Notes" || NoteInput == "exit notes" || NoteInput == "EXIT NOTES" || NoteInput == "Exit notes" || NoteInput == "exit Notes")
        {
            std::cout << "You have exited the Notes UI. Returning to main menu..." << std::endl;
            Current_UI = UI[0];
            current_Size = UI_Size[0];
            current_UI_index = 0;   
        }
        else
        {
            std::cout << "Invalid input. Please enter 'View Notes', 'Create Notes', or 'Exit Notes'." << std::endl;
        }
    }
}

void displayDiagram() 
{

}

void displayTracker() 
{

}
void createTasks() 
{
    TaskManager TaskCreate;
    std::cout << "How many tasks do you want to add?: ";
    int x;
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character left in the stream
    for( int i = 0; i < x; i++)
    {
        std::cout << "Please enter the task name (Or 'exit' to stop adding tasks): "; 
        std::getline(std::cin, TaskCreate.name);

        if (TaskCreate.name == "exit" || TaskCreate.name == "Exit" || TaskCreate.name == "EXIT")
        {
            std::cout<< "Exiting Task Creation." << std::endl;
            break;
                    
        }
        else
        {
        std::cout << "Please enter the task priority (1-100): ";
        std::cin >> TaskCreate.priority;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character left in the stream 
        while (TaskCreate.priority < 1 || TaskCreate.priority > 100)
        {
        std::cout << "Invalid priority. Please enter a number between 1 and 100." << std::endl;
        std::cin >> TaskCreate.priority;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character left in the stream 
        continue;
        }

        std::cout << "Task added: " << TaskCreate.name << " Priority: " << TaskCreate.priority << std::endl;
        taskList.push_back(TaskCreate);
        }
    }
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
