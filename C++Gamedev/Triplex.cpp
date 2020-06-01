#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
    {
        //Print Welcome Messages, Intro
    std::cout << "\n\n You're locked outside of a level " << Difficulty;
    std::cout << " bunker full of high-end Tech\n You need to enter the security code on the terminal to unlock the door...\n\n";

    }

bool PlayGame(int Difficulty) // By using this return type, it generates a True or False.
{
    PrintIntroduction(Difficulty);

    //Main numbers for game, generated through a random number generatorbased of Difficulty int.
   const int CodeA = rand() % Difficulty + Difficulty;
   const int CodeB = rand() % Difficulty + Difficulty;
   const int CodeC = rand() % Difficulty + Difficulty;
    //Variables for adding and multiplying the codes
   const int CodeSum = CodeA + CodeB + CodeC;
   const int CodeProduct = CodeA * CodeB * CodeC;
    
    //Print sum and produuct to the terminal
    std::cout << "There are 3 numbers in the code";
    std::cout << "\nThe numbers add-up to:  " << CodeSum;
    std::cout << "\nThe numbers multiply to: " << CodeProduct << std::endl;

    // Store Player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nNice, That's one passcode solved";
        return true; // Endpoint for Playgame, returning true if they guess right.
    }
    else
    {
        std::cout << "\nNot quite! Try again.";
        return false; // Endpoint for PlayGame, returning false if they guess wrong.
    }
}

int main()  //Int Main is required in EVERY C++ Program!!!!
{   
    srand(time(NULL)); // Create new randoom sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Will Loop the game until all levels are completed
    {

        bool bLevelComplete = PlayGame(LevelDifficulty); // Booleans help return a value
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete) // Increase level difficulty
        {
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "\nAwesome! The Technology is yours!";
    return 0;
}