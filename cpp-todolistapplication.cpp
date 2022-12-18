#include <iostream>
#include <string>
#include <list> 
#include <iterator>
#include <ctime>
using namespace std;

class todolist{
    private:
    int id;
    string description;
    bool completed;

    public:
    todolist(): id(0), description(" "), completed(false) {}
    ~todolist() = default;

    bool create( string new_description){
        //generate a randam integer between 1 and 100
        id=rand()%100+1;
        description=new_description;
        return true;
    }

    int getid(){
        return id;
    }
    string getdescription(){
        return description;
    } 
    bool iscompleted(){
        return completed;
    }
    void setcompleted(bool val){
        completed=val;
    }

};

int main(){
    string input_option;
    int input_id;
    string input_description;
    string version="v0.1.0";

    list<todolist>todoitems;
    list<todolist>::iterator it; 

    srand(time(NULL));

    todoitems.clear();

    //todolist test;
    //test.create("this is a test");
    //todoitems.push_back(test);

    while(1){
        system("cls");
        cout<<"To Do List Maker version "<<version<<endl;
        cout<<endl;
        for(it = todoitems.begin(); it!=todoitems.end(); it++){

            string completed=it->iscompleted()? "Done":"Not Done";

            cout<<it->getid()<<" | "<<it->getdescription()<<" | "
            <<completed<<endl;
        }

        if (todoitems.empty()){
            cout<<"Add your first Item!"<<endl;
        }
        
        cout<<endl;
        cout<<endl;

        cout<<"[a]dd a new ToDo"<<endl;
        cout<<"[c]omplete a Todo"<<endl;
        cout<<"[q]uit"<<endl;
        cout<<"choice: ";
        cin>>input_option;
        if (input_option == "q"){
            cout<<"Have a great day now! "<<endl;
            break;}

        else if (input_option == "a"){
            cout<<"Enter new description : "<<endl;
            cin.clear();
            cin.ignore();
            getline(cin, input_description);
            todolist newitem;
            newitem.create(input_description);
            todoitems.push_back(newitem);
        }
         
        else if(input_option=="c")
        {
            cout<<"Enter id to mark completed"<<endl;
            cin>>input_id;
            for(it = todoitems.begin(); it!=todoitems.end(); it++){
                if (input_id==it->getid()){
                    it->setcompleted(true);
                    break;
                }
        }
        }
        
    }
return 0;
}