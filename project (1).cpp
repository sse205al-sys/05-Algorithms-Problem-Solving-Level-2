#include <iostream>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults
{
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

short RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

short ReadHowManyRounds()
{
    short GameRounds = 1;
    do
    {
        cout << "how many round you want to play from 1  to 10 :  ";
        cin >> GameRounds;

    } while (GameRounds > 10 || GameRounds < 1); 
    return GameRounds;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enGameChoice ReadPlayerChoice()
{
    short Choice;
    do
    {
        cout << "\nYour Choice : [1] : Stone, [2] : Paper, [3] : Scissors ? ";
        cin >> Choice;
    } while (Choice > 3 || Choice < 1);
    return (enGameChoice)Choice;
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.ComputerChoice == RoundInfo.PlayerChoice)
        return enWinner::Draw;

    switch (RoundInfo.ComputerChoice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.PlayerChoice == enGameChoice::Scissors)
            return enWinner::computer;
        break;
    case enGameChoice::Paper:
        if (RoundInfo.PlayerChoice == enGameChoice::Stone)
            return enWinner::computer;
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.PlayerChoice == enGameChoice::Paper)
            return enWinner::computer;
        break;
    }
    return enWinner::Player;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player", "Computer", "No Winner (Draw)" };
    return arrWinnerName[Winner - 1];
}

string ChoiceName(enGameChoice choice)
{
    string arrChoice[3] = { "Stone" , "Paper", "Scissors" };
    return arrChoice[choice - 1];
}

void SetWinnerScreen(enWinner winner)
{
    if (winner == enWinner::Player)
        system("color 2F"); 
    else if (winner == enWinner::computer)
        system("color 4F"); 
    else
        system("color 6F"); 
}

void PrintRoundResults(stRoundInfo round)
{
    cout << "\n____________ Round [" << round.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(round.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(round.ComputerChoice) << endl;
    cout << "Round Winner   : [" << round.WinnerName << "]\n";
    cout << "_________________________________________\n" << endl;
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
    if (PlayerWinTimes > ComputerWinTimes)
        return enWinner::Player;
    else if (ComputerWinTimes > PlayerWinTimes)
        return enWinner::computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(int GameRounds, short PlayerWinTime, short ComputerWinTime, short DrowTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.PlayerWinTimes = PlayerWinTime;
    GameResults.ComputerWinTimes = ComputerWinTime;
    GameResults.DrawTimes = DrowTimes;
    GameResults.GameWinner = WhoWonTheGame(PlayerWinTime, ComputerWinTime);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);
    return GameResults;
}

stGameResults PlayGame(short howManyGames)
{
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= howManyGames; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

      
        SetWinnerScreen(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player)
            PlayerWinTimes++;
        else if (RoundInfo.Winner == enWinner::computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(howManyGames, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}

void ShowFinalGameResult(stGameResults GameResult)
{
    cout << Tabs(2) << "----------------------------[Game Result]---------------------------\n\n";
    cout << Tabs(2) << "Game Rounds        : " << GameResult.GameRounds << endl;
    cout << Tabs(2) << "player win times   : " << GameResult.PlayerWinTimes << endl;
    cout << Tabs(2) << "computer won times : " << GameResult.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw won times     : " << GameResult.DrawTimes << endl;
    cout << Tabs(2) << "final winner       : " << GameResult.WinnerName << endl;
    cout << Tabs(2) << "--------------------------------------------------------------------\n\n";
}

void ShowGameOver()
{
    cout << Tabs(2) << "-------------------------------------------------------------\n\n";
    cout << Tabs(2) << "                 +++ G a m e O v er +++\n";
    cout << Tabs(2) << "-------------------------------------------------------------\n\n";
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGAme()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOver();
        ShowFinalGameResult(GameResults);

        cout << endl << Tabs(3) << "Do You want to play again? Y/N? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));
    StartGAme();
    return 0;
}
