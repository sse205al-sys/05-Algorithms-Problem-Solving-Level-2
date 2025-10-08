#include <iostream>
using namespace std;

enum enSPS { stone = 1, paper = 2, scissors = 3 };

int ReadNumber(string m)
{
    int round;
    do
    {
        cout << m;
        cin >> round;
    } while (round > 10 || round < 1);
    return round;
    cout << "\n";
}

int Random(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void Header(int NumberOfRounds)
{
    cout << "\n\nRound [" << NumberOfRounds << "] begins :\n";
    cout << "----------- Round [" << NumberOfRounds << "] --------------\n";
}

void PlayerComputerChoice(enSPS Player, enSPS Computer)
{
    cout << "Player choice : ";
    if (Player == enSPS::stone)
        cout << "stone";
    else if (Player == enSPS::paper)
        cout << "paper";
    else if (Player == enSPS::scissors)
        cout << "scissors";

    cout << "\nComputer choice : ";
    if (Computer == enSPS::stone)
        cout << "stone";
    else if (Computer == enSPS::paper)
        cout << "paper";
    else if (Computer == enSPS::scissors)
        cout << "scissors";
}

void RoundWinner(enSPS Player, enSPS Computer, int& PlayerCounter, int& ComputerCounter, int& DrawCounter)
{
    if (Player == Computer)
    {
        cout << "\nNo winner\n";
        system("color 6F");
        DrawCounter++;
    }
    else if (Player == enSPS::stone && Computer == enSPS::scissors
        || Player == enSPS::scissors && Computer == enSPS::paper
        || Player == enSPS::paper && Computer == enSPS::stone)
    {
        cout << "\nThe winner is the player\n";
        system("color 2F");
        PlayerCounter++;
    }
    else
    {
        cout << "\nThe winner is the computer\n";
        system("color 4F");
        ComputerCounter++;
    }
}

void Game(int numberOfRounds, enSPS Player)
{
    int PlayerCounter = 0;
    int ComputerCounter = 0;
    int DrawCounter = 0;

    for (int i = 1; i <= numberOfRounds; i++)
    {
        enSPS Computer = (enSPS)Random(1, 3);
        Header(i);
        PlayerComputerChoice(Player, Computer);
        RoundWinner(Player, Computer, PlayerCounter, ComputerCounter, DrawCounter);

        if (i != numberOfRounds)
            Player = (enSPS)ReadNumber("\nYour choice : [1]:Stone, [2]:Paper, [3]:Scissors ? ");
    }

    cout << "                     ------------------------------------------------------------------------------\n";
    cout << "                                            +++ G a m e  O v e r +++\n";
    cout << "                     ------------------------------------------------------------------------------\n";
    cout << "                     ------------------------------ [GAME RESULT] ---------------------------------\n";
    cout << "                                    Game Rounds : " << numberOfRounds << endl;
    cout << "                                    Player won times : " << PlayerCounter << endl;
    cout << "                                    Computer won times : " << ComputerCounter << endl;
    cout << "                                    Draw times : " << DrawCounter << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int numberOfRounds = ReadNumber("Enter number of rounds (1-10): ");
    enSPS Player = (enSPS)ReadNumber("Your choice : [1]:Stone, [2]:Paper, [3]:Scissors ? ");
    enSPS Computer = (enSPS)Random(1, 3);

    Game(numberOfRounds, Player);

    return 0;
}
