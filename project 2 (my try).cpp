
#include <iostream>
using namespace std;
enum enQuestionLevel { easy = 1, med = 2, hard = 3, mix = 4 };
enum enOperationType { add = 1, sub = 2, mul = 3, divv = 4, mixx = 5 };

struct stQuestion
{
	int num1;
	int num2;
	enOperationType opreatin;
	int answer;
	string WrongOrRight = "";
};
struct stFinalResults
{
	short NumberOfQuestions;
	string QuestionLevel = "";
	string OpType="";
	short NumberOfRight = 0;
	short NumberOfWrong = 0;
	string PassOrNot = "";
};
short ReadHowManyQuestions()
{
	short n = 1;
	do
	{
		cout << "How many questions you want to answer : ";
		cin >> n;
	} while (n <= 0 || n > 10);
	return n;
}
int Random(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void ResetScreen()
{
	system("cls");
	system("color 0F");
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

string OperationName(enOperationType op)
{
	switch (op)
	{
	case enOperationType::add:
		return "+";
	case enOperationType::sub:
		return "-";
	case enOperationType::mul:
		return "x";
	case enOperationType::divv:
		return "/";
	default:
		return "Mix";
	}
}
enOperationType GetRandomOperation()
{
	return (enOperationType)Random(1, 4);
}
enQuestionLevel GetRandomLevel()
{
	return (enQuestionLevel)Random(1, 5);
}
enOperationType GetOperation()
{
	short n;
	do
	{
		cout << "enter type of operation add[1] ,sub[2], mul[3], div[4],mix[5] :";
		cin >> n;
	} while (n < 1 || n>5);
	return (enOperationType)n;
}
enQuestionLevel GetLevel()
{
	short n;
	cout << "What the level you want Easy[1],mid[2],hard[3],mix[4] : ";
	cin >> n;
	cout << "\n";
	return (enQuestionLevel)n;
}
string NameQuestionLevel(enQuestionLevel questionLevel)
{
	string arrLevels [4] = { "Easy","Medium","Hard","Mixed" };
	return arrLevels [questionLevel - 1];
}
int EasyMidHard(short NumberOfQuestion,short NumberOfAllQuestions,enOperationType op,int &answer ,int from , int to)
{
	
	stQuestion Q;
	cout << "Question [" << NumberOfQuestion << "/" << NumberOfAllQuestions << "]\n";
	short n1 = Q.num1 = Random(from, to);
	short n2 = Q.num2 = Random(from, to);
	string opName = OperationName(op);
	cout << n1 << endl;
	cout << "   " << opName << endl;
	cout << n2<<endl;
	cout << "--------------------\n";
	cin >> answer;

	switch (op)
	{
	case (enOperationType::add):
		return n1 + n2;
	case(enOperationType::divv):
		return n1 / n2;
	case (enOperationType::mul):
		return n1 * n2;
	case (enOperationType::sub):
		return n1 - n2;
	}
}

stFinalResults Start(short numberOfQuestions, enQuestionLevel level, enOperationType op)
{
	int answer;
	stFinalResults f;
	f.NumberOfQuestions = numberOfQuestions;
	if (op == enOperationType::mixx)
		f.OpType = "Mix";
	else
		f.OpType = OperationName(op);

	if (level == enQuestionLevel::mix)
		f.QuestionLevel = "Mix";
	else
		f.QuestionLevel = NameQuestionLevel(level);


	for (int i = 1; i <= numberOfQuestions; i++)
	{
		enQuestionLevel l;
		if (level == enQuestionLevel::mix)
			l = GetRandomLevel();  
		else
			l = level;   
		enOperationType o;
		if (op == enOperationType::mixx)
			o = GetRandomOperation();
		else
			o = op;


		int correctAnswer;

		if (l == enQuestionLevel::easy)
			correctAnswer = EasyMidHard(i, numberOfQuestions, o, answer, 0, 10);
		else if (l == enQuestionLevel::med)
			correctAnswer = EasyMidHard(i, numberOfQuestions, o, answer, 11, 100);
		else
			correctAnswer = EasyMidHard(i, numberOfQuestions, o, answer, 100, 500);

		if (answer == correctAnswer)
		{
			system("color 2F");
			cout << "its correct answer :-)\n\n";
			f.NumberOfRight++;
		}
		else
		{
			system("color 4F");
			cout << "its not correct answer :-(\n"
				<< "correct answer is : " << correctAnswer << "\n\n";
			f.NumberOfWrong++;
		}
	}

	return f;
}
bool Pass(stFinalResults f)
{
	return (f.NumberOfRight > f.NumberOfWrong);
}
void FinalResult(stFinalResults f,bool Pass)
{
	cout << "-----------------------------------\n";
	if (Pass)
	{
		cout << "Final Reasult Is Pass :-)\n";
		f.PassOrNot = "Pass";
	}
	else
	{
		cout << "Final Reasult Is Fail :-(\n";
		f.PassOrNot = "Fail";
	}
		
	
	cout << "-----------------------------------\n";
	cout << "Number of Questions : " << f.NumberOfQuestions<<endl;
	cout << "Question level : " << f.QuestionLevel << endl;
	cout << "OP type : " << f.OpType << endl;
	cout << "Number of right answers : " << f.NumberOfRight<< endl;
	cout << "Number Of wrong answers : " << f.NumberOfWrong << endl;
	cout << "-----------------------------------\n";

}
void PlayGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		short numQ = ReadHowManyQuestions();
		stFinalResults f = Start(numQ, GetLevel(), GetOperation());
		FinalResult(f, Pass(f));
		cout << "do you want to play agane Y/N : ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));
	PlayGame();
}
