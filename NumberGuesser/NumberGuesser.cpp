#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
void rules();
int main(){
    string name;
    int bal;
    int bet;
    int guess;
    int dice;
    char choice;
    
    srand(time(0));

    cout<<"Welcome To NUMBER GUESSER\n\n"<<endl;
    cout<<"Please enter your name: ";
    getline(cin,name);
    cout<<"Please enter your starting balance: ";
    cin>>bal;
    do
    {
        system("cls");
        rules();
        cout<<"Your current balance is "<<bal<<endl;
        do
        {
            cout<<"Please Enter Amount to bet: ";
            cin>>bet;
            if(bet>bal){
                cout<<"Bet cannot be more than Balance\n"<<"\nPlease re-enter bet --> ";
            }
        }while(bet>bal);
        do
        {
            cout << "Guess any betting number between 1 & 10: ";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if(dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won " << bet * 10;
            bal = bal + bet * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost "<< bet <<"\n";
            bal = bal - bet;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<name<<", You have balance of $ " << bal << "\n";
        if(bal == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << bal << "\n\n";
    return 0;
}
    
void rules(){
    cout<<"Welcome to Number Guesser"<<endl;
    cout<<"_________________________"<<endl;
    cout<<"Rules of this game are simple"<<endl;
    cout<<"Choose a number between 1 to 10. If your chosen number matches the one chosen by the machine, YOU WIN!"<<endl;
    cout<<"Winner gets 10 times the amount they bet"<<endl;
    cout<<"Losers lose all!"<<endl;
}