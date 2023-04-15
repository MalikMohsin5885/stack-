#include<iostream>
using namespace std;

struct Stack
{
	int Array[50];
	int Top;
}myStack;

void Push(int value)
{
	cout<<"to be pushed=>	"<<value<<endl;
	if(myStack.Top == (sizeof(myStack.Array)/sizeof(char)))
		cout<<"Stack Overflow"<<endl;
	else
	{
		myStack.Top++;
		myStack.Array[myStack.Top] = value;
	}
}

char Pop()
{
	int temp = 0;
	if(myStack.Top == -1)
		cout<<"Stack Underflow"<<endl;
	else
	{
		temp = myStack.Array[myStack.Top];
		myStack.Array[myStack.Top] = 0;
		myStack.Top--;
	}
	return temp;
}
void postfixEvaluation(char (&Equation)[50] , int total)
{
	for(int currentIndex = 0; currentIndex < total ; currentIndex++)
	{
		switch(Equation[currentIndex])
		{
			case '+' :
			{
				int operand_2 = Pop();
				int operand_1 = Pop();
				Push(operand_1 + operand_2);
			}
				break;
			
			case '-' :
			{
				int operand_2 = Pop();
				int operand_1 = Pop();
				Push(operand_1 - operand_2);
			}
				break;
			
			case '*' :
			{
				int operand_2 = Pop();
				int operand_1 = Pop();
				Push(operand_1 * operand_2);
			}
				break;
			
			case '/' :
			{
				int operand_2 = Pop();
				int operand_1 = Pop();
				Push(operand_1 / operand_2);
			}
				break;
			
			default :
			{
				Push(Equation[currentIndex] - '0');
				cout<<"Pushed	"<<Equation[currentIndex]<<endl;
			}
				break;

		}
	}
	
}

int main()
{
	myStack.Top = -1;
	char i = 0 , Equation[50];
	cout<<"Enter Equation : ";
	while(cin>>Equation[i])
		i++;
	postfixEvaluation(Equation,i);
	cout<<"top	"<<myStack.Top<<endl;
	cout<<"result	"<<myStack.Array[myStack.Top];
}
