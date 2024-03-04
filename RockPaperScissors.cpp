//Rock,Paper,Scissors Project
//The User choose either Rock Paper Scissors
//The computer uses rng
//The choices are compared then the number of wins are tracked
#include <iostream> //using this library for output to console and collecting input from user

#include <string> //used for getline

#include <random> //c++11 lib used for the computers rng 

#include <cmath> //used to round computers number to a whole number

//chrono and thread are use to delay console output
#include <chrono> 
#include <thread>

char getComputerChoice() {

    std::random_device device;
    std::mt19937 mt(device());
    std::uniform_real_distribution<double> r(1, 3);

    if (round(r(mt)) == 1) {
        return 'r';
    }
    else if (round(r(mt)) == 2) {
        return 'p';
    }
    else if (round(r(mt)) == 3) {
        return 's';
    }
}

int results(const char userChoice, const char comChoice){
    if (userChoice == comChoice) {
        return 2;
    }
    if (userChoice == 'p' && comChoice == 'r') {
        return 1;
    }
    else if (userChoice == 's' && comChoice == 'p') {
        return 1;
    }
    else if (userChoice == 'r' && comChoice == 's') {
        return 1;
    }
    else if (userChoice == 'p' && comChoice == 's') {
        return 0;
    }
    else if (userChoice == 's' && comChoice == 'r') {
        return 0;
    }
    else if (userChoice == 'r' && comChoice == 'p') {
        return 0;
    }
}

int main()
{
    int userWins = 0, comWins = 0;
    int roundNum = 0;
    char userChoice;
    char menuchoice;
    std::string name;

    std::cout << "Welcome to Rock, Paper, Scissors!!!!\n";
    std::cout << "Please enter a name:\n";
    getline(std::cin, name);
    while(true) {
        while (true) {
            std::cout << "\nChoose(Enter a letter) Rock 'r' | Paper 'p' | Scissor 's'\n";
            std::cout << "::";
            std::cin >> userChoice;
            if (userChoice == 'r' || userChoice == 'p' || userChoice == 's') {
                break;
        }
            else {
                std::cout << "\nKeep lowercase and 'r', 'p', or 's'\n";
            }
        }
        
        std::cout << "\nRock...\n";
        //used to delay the output to console 10 nanoseconds 
        std::this_thread::sleep_for (std::chrono::nanoseconds(10));
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));

        std::cout << "\nPaper...\n";
        std::this_thread::sleep_for(std::chrono::nanoseconds(10));
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
        
        std::cout << "\nScissor...\n";
        std::this_thread::sleep_for(std::chrono::nanoseconds(10));
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
        
        std::cout << "\nShoot!!!\n";

        int result = results(userChoice, getComputerChoice()); //storing results into result

        std::cout << "--Results--\n";
        roundNum++;
        std::cout << "Round: " << roundNum << std::endl;
        if (result == 1) {
            std::cout << "\n" << name << " won the match\n";
            userWins++;
        }
        else if(result == 2) {
            std::cout << "\n" << "Its a draw\n";
        }
        else {
            std::cout << "\n" << "computer won the match\n";
            comWins++;
        }

        std::cout << "\n---Score Count---\n";
        std::cout << name << ": " << userWins << "\n";
        std::cout << "Computer: " << comWins << "\n";
        
        std::cout << "\nWanna go again?\n";
        std::cout << "If 'NO' press 'n'\n";
        std::cout << "If 'YES' press another letter\n";
        std::cout << "::";
        std::cin >> menuchoice;
        if (menuchoice == 'n' || menuchoice == 'N') {
            std::cout << "Good Game " << name << "\n";
            break;
        }
        else{
            std::cout << "Beginning next round\n";
        }
    }
    
    return 0;
}

