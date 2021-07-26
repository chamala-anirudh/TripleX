#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty) {
    cout << "\nYou are a secret agent breaking into a Level " << Difficulty;
    cout << " secure server room. \nYou need to enter the correct codes to continue..." << endl;
}

bool PlayGame(int Difficulty)
{
    int CodeSum, CodeProduct, GuessA, GuessB, GuessC, GuessSum, GuessProduct;
    
    PrintIntroduction(Difficulty);
    
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    CodeSum = CodeA + CodeB + CodeC;
    CodeProduct = CodeA * CodeB * CodeC;

    cout << "" << endl;
    cout << "There are 3 numbers in total" << endl;
    cout << "The codes sum to give: " << CodeSum << endl;
    cout << "The codes multiply to give: " << CodeProduct << endl; 

    cout << "" << endl;
    cin >> GuessA >> GuessB >> GuessC;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    // cout << "The sum of your Guesses: " << GuessSum << endl;
    // cout << "The product of your Guesses: " << GuessProduct << endl;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        cout << "\nWell done agent, you have extracted a file, keep moving." << endl;
        return true;
    }
    else {
        cout << "Careful agent, try again!!" << endl;
        return false;
    }
}

int main() 
{
    srand(time(NULL));
    int DifficultyLevel = 1;
    const int MaxLevel = 5;

    while(DifficultyLevel <= MaxLevel) {
        bool bLevelComplete = PlayGame(DifficultyLevel);
        cin.clear();
        cin.ignore();

        if (bLevelComplete)
        {
            ++DifficultyLevel;
        }
    }
    
    cout << "Congratulations, you passed all levels!!" << endl;
    return 0;
}
