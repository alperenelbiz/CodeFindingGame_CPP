#include<iostream>
#include<ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a " << Difficulty ;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n" ;
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty ;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "- There are three numbers in the code\n";
    std::cout << "- The codes add-up to: " << CodeSum;
    std::cout << "\n- The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\nWEll done agent! You got the file! Keep going";
        return true;
        
    }

    else
        std::cout << "\nYou died! Try again...";
        return false;

    ++Difficulty;        
}

int main()
{   
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n***Great work agent! You got all the files! Now get out of there...";
    return 0;
}