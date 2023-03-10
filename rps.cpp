#include <iostream>
#include <map>
#include <random>
#include <string>
using namespace std;

bool active = true;
string rps;
string player;
string com;
float wins = 0;
float losses = 0;
float ties = 0;
bool victory = false;
bool failure = false;
bool tiegame = false;
bool error = false;
string victorymessage = "\nYou win!\n";
string failuremessage = "\nSorry, you lost.\n";
string tiemessage = "\nIt's a tie!\n";
random_device seed;

string options[] {"Rock", "Paper", "Scissors", "Error"};

string comChoice()
    {
    mt19937 gen(seed());
    uniform_int_distribution<> distrib(0, 2);
    com = options[distrib(gen)];
    return com;
    }

string userChoice()
    {
    cout << "Make your move...";
    getline(cin, rps);

    if(rps == "r")
        {
        return rps;
        }
    else if(rps == "p")
        {
        return rps;
        }
    else if(rps == "s")
        {
        return rps;
        }
    else if(rps == "h")
        {
        cout << "Enter 'r' for rock, 'p' for paper, 's' for scissors, 'h' to display this message, or 'q' to quit.\n";
        return rps;
        }
    else if(rps == "q")
        {
        return rps;
        }
    else
        {
        cout << "Invalid choice. Enter 'h' for help.\n";
        return rps;
        }
    }

string checkArray()
    {
    if(rps == "r")
        {
        player = options[0];
        return player;
        }
    else if(rps == "p")
        {
        player = options[1];
        return player;
        }
    else if(rps == "s")
        {
        player = options[2];
        return player;
        }
    else
        {
        player = options[3];
        return player;
        }
    }

bool checkWinner()
    {
    if(player == "Rock" && com == "Scissors")
        {
        ++wins;
        victory = true;
        return victory;
        }
    else if(player == "Paper" && com == "Rock")
        {
        ++wins;
        victory = true;
        return victory;
        }
    else if(player == "Scissors" && com == "Paper")
        {
        ++wins;
        victory = true;
        return victory;
        }
    else if(player == "Rock" && com == "Paper")
        {
        ++losses;
        failure = true;
        return failure;
        }
    else if(player == "Paper" && com == "Scissors")
        {
        ++losses;
        failure = true;
        return failure;
        }
    else if(player == "Scissors" && com == "Rock")
        {
        ++losses;
        failure = true;
        return failure;
        }
    else if(player == "Error")
        {
        error = true;
        return error;
        }
    else
        {
        ++ties;
        tiegame = true;
        return tiegame;
        }
    }

int main()
    {
    cout << "Welcome, challenger! Press 'h' for help.\n";
    while(active)
        {
            comChoice();
            userChoice();
            checkArray();
            if(rps == "h")
                {
                userChoice();
                }
            if(rps == "q")
                {
                active = false;
                break;
                }
            checkWinner();
            if(error == true)
                {
                break;
                }
            cout << "\nYou played " << player << "!\n";
            cout << "Your opponent played " << com << "!\n";
            if(victory == true)
                {
                cout << victorymessage;
                }
            if(failure == true)
                {
                cout << failuremessage;
                }
            if(tiegame == true)
                {
                cout << tiemessage;
                }
            cout << "You've won " << wins << " times, lost " << losses << " times, and tied " << ties << " times.\n";
            cout << "You've won " << (wins / (wins + losses + ties)) * 100 << "% of games.\n";
            cout << endl;
            victory = false;
            failure = false;
            tiegame = false;
        }
    cout << "Goodbye!\n";
    return 0;
    }
