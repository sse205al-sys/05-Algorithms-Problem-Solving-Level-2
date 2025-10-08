#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuestionLevel { easy = 1, med = 2, hard = 3, mix = 4 };
enum enOperationType { add = 1, sub = 2, mul = 3, divv = 4, mixx = 5 };

string OperationName(enOperationType op)
{
    switch (op)
    {
    case enOperationType::add: return "+";
    case enOperationType::sub: return "-";
    case enOperationType::mul: return "x";
    case enOperationType::divv: return "/";
    default: return "Mix";
    }
}

string NameQuestionLevel(enQuestionLevel questionLevel)
{
    string arrLevels[4] = { "Easy","Medium","Hard","Mixed" };
    return arrLevels[questionLevel - 1];
}

int Random(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void SetScreenColor(bool Right)
{
    if (Right)
        system("color 2F");
    else
    {
        system("color 4F");
        cout << "\a";
    }
}

short ReadHowManyQuestions()
{
    short n = 1;
    do
    {
        cout << "How many questions you want to answer (1-10): ";
        cin >> n;
    } while (n <= 0 || n > 10);
    return n;
}

enOperationType ReadOperation()
{
    short n;
    do
    {
        cout << "Enter type of operation add[1], sub[2], mul[3], div[4], mix[5]: ";
        cin >> n;
    } while (n < 1 || n>5);
    return (enOperationType)n;
}

enQuestionLevel ReadLevel()
{
    short n;
    do {
        cout << "What level you want Easy[1], Med[2], Hard[3], Mix[4]: ";
        cin >> n;
    } while (n < 1 || n>4);
    return (enQuestionLevel)n;
}

int ReadAnswer()
{
    int n = 0;
    cin >> n;
    return n;
}

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOperationType opreatin;
    enQuestionLevel QuestionLevel;
    int PlayerAnswer;
    int answer;
    bool AnswerResult = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool isPass = false;
};

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

enOperationType GetRandomOperation()
{
    return (enOperationType)Random(1, 4);
}

int SimpleCalculator(int num1, int num2, enOperationType op)
{
    switch (op)
    {
    case (enOperationType::add): return num1 + num2;
    case (enOperationType::divv): return (num2 != 0 ? num1 / num2 : 0);
    case (enOperationType::mul): return num1 * num2;
    case (enOperationType::sub): return num1 - num2;
    }
    return 0;
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType op)
{
    stQuestion Question;
    if (QuestionLevel == enQuestionLevel::mix)
        QuestionLevel = (enQuestionLevel)Random(1, 3);
    if (op == enOperationType::mixx)
        op = GetRandomOperation();
    Question.opreatin = op;

    switch (QuestionLevel)
    {
    case enQuestionLevel::easy:
        Question.Number1 = Random(1, 10);
        Question.Number2 = Random(1, 10);
        break;
    case enQuestionLevel::med:
        Question.Number1 = Random(10, 50);
        Question.Number2 = Random(10, 50);
        break;
    case enQuestionLevel::hard:
        Question.Number1 = Random(50, 100);
        Question.Number2 = Random(50, 100);
        break;
    }

    Question.answer = SimpleCalculator(Question.Number1, Question.Number2, Question.opreatin);
    Question.QuestionLevel = QuestionLevel;

    return Question;
}

void GenerationQuizzQuestion(stQuizz& Quizz)
