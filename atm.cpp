#include <iostream>
using namespace std;

void showmenu(){
    cout<<"********MENU********"<<endl;
    cout<<"1. Check Balance"<<endl;
    cout<<"2. Money Deposit"<<endl;
    cout<<"3. Money Withdraw"<<endl;
    cout<<"4. Exit ATM"<<endl;
    cout<<"********************"<<endl;
}

int main(){
    int option;
    double balance=500;
    do{
    showmenu();
    cout<<"Option: ";
    cin>>option;
    system("cls");
    
    double depositamount;
    double withdrawamount;
    switch(option){
        case 1: cout<<"Balance: "<<balance<<" Rs"<<endl;
        break;
        case 2: cout<<"Deposit Amount: ";
            cin>> depositamount;
            balance=balance + depositamount;
            break;
        case 3: cout<<"Withdraw Amount: ";
            cin>>withdrawamount;
            if (withdrawamount<=balance)
                balance-=withdrawamount;
            else{
                cout<<"Not Enough Money Available"<<endl;;
            }
            break;
    }
    }
    while(option!=4);
    
}