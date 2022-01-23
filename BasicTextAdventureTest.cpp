#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty){

    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << std::endl;
    std::cout << "Secured server room...\n\nEnter the correct code to continue\n\n";
}

bool PlayGame(int Difficulty){

    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "\n+ The codes add-up to: " << CodeSum << std::endl;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\nYou completed this level";
        return true;
    }
    else {
        std::cout << "\nRetry this level";
        return false;
    }
}

int main () {

    srand(time(NULL)); // create a new random sequence based of the time of the day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty ){ //loop the game until all challenges are completed

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        } 
    }

    std::cout << "\nWell done you finished the game";

    return 0;
}