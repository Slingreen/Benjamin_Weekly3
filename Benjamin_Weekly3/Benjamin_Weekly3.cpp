/**********************************************************************************************************
 *      Weekly assignment 3
 *
 *      Guess the number game!
 *
 *
 *  @file    Benjamin_Weekly3.CPP
 *  @author  Benjamin A.E. Darici
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

// Different functions used throughout the code
void guessNumber(const int min, const int max);
void writeMenu();
int getNumber(const char* c, const int min, const int max);
char Read_Command(const char* c);

int eHigh = 5, 
    mHigh = 10, 
    hHigh = 30;

// A main code with a switch to let the user choose which task to use, a sort of main menu
int main()
{
    char command;

    writeMenu();
    command = Read_Command("Command");

    while (command != 'Q')
    {
        std::cin.ignore(32767, '\n');
        switch (command)
        {
        case '1': guessNumber(1,5); break;
        case '2': guessNumber(1,10); break;
        case '3': guessNumber(1,30); break;
        default: writeMenu(); break;
        }
        command = Read_Command("Command");
    }
}


//  The actuall game
void guessNumber(const int min, const int max)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    //  Sets number between a max and min chosen by the difficulty
    int secret = std::rand() % max + min,
        input = 0,
        turn = 0;
    //  Do-while game loop
    do
    {   
        input = getNumber("Guess number", min, max);    //  Gets a number from the user
        turn++;                                         //  Counts up the turns
        if (input != secret)    //  Checks if the user has guessed the number, if not, gives a little hint
        {
            std::cout 
                << "Too " 
                << (input < secret ? "low!\n" : "high!\n");
        }
    }while (input != secret);
    std::cout
        << "You guessed the number!\n"
        << "It took you: "
        << turn
        << " turn(s) to get it right!\n";
    if ((max - 10) > 0)                     //  Checks if it was hard difficulty
    {
        std::cout 
            << "High-score for hard difficulty: "
            <<hHigh
            << std::endl;
        if (turn < hHigh)                   //  Checks if the user beat the previous high-score
        {
            hHigh = turn;
            std::cout << "You set a new record!\n";
        }
        else
        {
            std::cout << "Try again to beat it!\n";
        }
    }  
    else if ((max - 10) < 0)                //  Checks if it was easy difficulty
    {
        std::cout 
            << "High-score for easy difficulty: "
            << eHigh
            << std::endl;
        if (turn < eHigh)                   //  Checks if the user beat the previous high-score
        {
            eHigh = turn;
            std::cout << "You set a new record!\n";
        }
        else
        {
            std::cout << "Try again to beat it!\n";
        }
    }
    else                                    //  It is medium difficulty
    {
        std::cout 
            << "High-score for medium difficulty: "
            << mHigh
            << std::endl;
        if (turn < mHigh)                   //  Checks if the user beat the previous high-score
        {
            mHigh = turn;
            std::cout << "You set a new record!\n";
        }
        else 
        {
            std::cout << "Try again to beat it!\n";
        }
    }
}


//  A function that returns numbers within a min and max value
int getNumber(const char* c, const int min, const int max) {
    char input[200] = "";
    int  number = 0;
    bool wrong = false;

    do {
        wrong = false;
        std::cout << c << " (" << min << " - " << max << "):  ";
        std::cin.getline(input, 200);
        number = atoi(input);
        if (number == 0 && input[0] != '0')
        {
            wrong = true;   std::cout << "\nNot a number\n\n";
        }
    } while (wrong || number < min || number > max);

    return number;
}


// A tiny function just to read input commands
char Read_Command(const char* c)
{
    char command;
    std::cout << c << ":  ";
    std::cin >> command;
    return(toupper(command));
}

// A tiny function to write out the choices the switch provides in the main function
void writeMenu()
{
    std::cout << "The following commands are available: \n"
        << "\t 1    Easy difficulty\n"
        << "\t 2    Medium difficulty\n"
        << "\t 3    Hard difficulty\n"
        << "\t Q    Quits program\n";
}