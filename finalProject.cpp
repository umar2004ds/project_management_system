#include <iostream>
#include<conio.h>
#include <string>

using namespace std;


    class Task{
        public:
        string description;
        bool completed;

        Task(string descrp) : description(descrp) , completed(false) {

        }
        Task(){

        }

        void markCompleted(){
            completed = true;
        }

    };

    class User{
        public:
        string name;

        User(){

        }

        User(char myName){
            name = myName;
        }
    };

    class Project : public Task{
        public:

        int noOfUsers, noOfTasks;

        Project(){

        }

        void userCount(){
            cout << endl << "Enter Number of Members for this project: ";
            cin >> noOfUsers;
        }

        void taskCount(){
            cout << endl << "Enter Number of Tasks for this project: ";
            cin >> noOfTasks;
        }

            

        User arr_user[22];
        Task arr_task[30];

        void userInput(){
            for(int i=0; i<noOfUsers; i++){
                string nam;
                cout << "Enter the name of User " << i+1 << ": ";
                getline(cin, nam);
                arr_user[i].name = nam;
            }
        }


        void taskInput(){
            for(int i=0; i<noOfTasks; i++){
                string task;
                cout << "Description => Task[" << i+1 << "]: ";
                getline(cin, task);
                arr_task[i] = task;
            }
        }

        string ID;
        string name;
        string deadLine; // Project Description  & status is also added here, inherited from Task class

        void inputAllInfo(){
            getchar();
            cout << "Enter Project ID: "; getline(cin, ID);
            cout << "Enter Project name: "; getline(cin, name);
            cout << "Enter Project Description: "; getline(cin, description);
        }

        void inputDeadLine(){
            cout << endl << "Enter DeadLine for this project:(dd/mm/yyyy) ";
            getline(cin, deadLine);
        }

    };

    class ManageProjects : public Project{

        public:
        Project arr_projects[300];
        int index = 0;


        void createProject(){
            arr_projects[index].inputAllInfo();
            arr_projects[index].userCount(); getchar();
            arr_projects[index].userInput();
            arr_projects[index].taskCount(); getchar();
            arr_projects[index].taskInput();
            arr_projects[index].inputDeadLine();
            index++;
        }

        void Display(){
            printf("%-6s %-25s %-35s %-9s %-9s %-7s\n", "ID", "Name", "Description", "Users", "Tasks", "DeadLine");
            cout << "-------------------------------------------------------------------------------------------------\n";
            for (int i = 0; i < index; i++){
                printf("%-6s %-25s %-35s %-9d %-9d %-7s\n", arr_projects[i].ID.c_str(), arr_projects[i].name.c_str(), arr_projects[i].description.c_str(), arr_projects[i].noOfUsers, arr_projects[i].noOfTasks, arr_projects[i].deadLine.c_str());
            }
        }

        void openProject(){
            string id; int found = 0;
            cout << "Enter ID to open Project: ";
            cin >> id;
            for (int i = 0; i < index; i++){

                if(arr_projects[i].ID == id){

                        found = 1;
                    cout << endl << endl << "Project Details:\n==========================================\n\n";
                    cout << "Project Name: " << arr_projects[i].name << endl;
                    cout << endl << "No. of Members: " << arr_projects[i].noOfUsers << endl;

                    cout << "Members' Names:\n---------------" << endl;
                    for(int j=0; j<arr_projects[i].noOfUsers; j++){
                        cout << "Member[" << j+1 << "]: " << arr_projects[i].arr_user[j].name << endl;


                    }

                    cout << endl << "DeadLine: " << arr_projects[i].deadLine << endl;

                    cout << endl << "No. of Tasks: " << arr_projects[i].noOfTasks << endl << endl;
                    cout << "     \t\t  Tasks\t\t\t\t\t\t\t\tStatus" << endl;
                    cout << "------------------------------------------------- \t\t\t --------------------\n";
                    for (int k = 0; k < arr_projects[i].noOfTasks; k++){
                        string status;
                        if(!arr_projects[i].arr_task[k].completed){
                            status = "NOT Completed";
                        }
                        else{
                            status = "Completed";
                        }
                        // cout << "Task[" << k+1 << "]: "; cout << arr_projects[i].arr_task[k].description << "\t\t\t" << endl;
                        printf("%-72s %s\n", arr_projects[i].arr_task[k].description.c_str(), status.c_str());
                    }


                    int choice, taskNo;
                    cout << endl << "Do you want to mark any Task as Completed:" << endl;
                    cout << "1. Yes\n2. No" << endl;
                    cout << endl << "Enter your Choice: "; cin >> choice;
                    if(choice == 1){
                        cout << "Enter Task No. : "; cin >> taskNo;
                        if(taskNo > arr_projects[i].noOfTasks) cout << "Enter a Valid Task Number. . . !" << endl;
                        else{
                            arr_projects[i].arr_task[taskNo-1].markCompleted();
                            cout << endl << "Task No. " << taskNo << " is Completed . . . !" << endl;
                        }
                    }

                } 
            }
            if(found == 0){
                cout << endl << "Enter a Valid Project ID . . . ! Try Again" << endl;
            }
            
        }

    };


int main(){

    ManageProjects project;
    int choice;
    
    do{

        system("cls");

        cout << "1. Create Project: [Maximum 300 Projects can be Handle through this Program]" << endl;
        cout << "2. Display Projects\n0. Exit\n\n";

            cout << "Enter your choice: ";
        try
        {
            cin >> choice; cout << endl << endl;
            switch(choice){
            case 1:
                project.createProject();
                cout << endl << "Project is Added Successfully . . . !" << endl << endl;
            break;

            case 2:
                project.Display();
            break;

            case 3:
                project.openProject();
            break;

            case 0:
                cout << "================\nAllah Hafiz\n================" << endl;
            break;

            default:
                cout << "Enter correct choice" << endl;

            }
    
            cout << endl << "Press Any key to continue: ";
            getch();
            
        }
        catch(int a)
        {
            cout << "Enter Correct Choice" << a << endl;
        }

    }while(choice != 0);

    return 0;
}