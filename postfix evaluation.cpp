#include<iostream>
#include <cstring>
#include <cmath>
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

int Pop()
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
	cout<<"temp--------------------"<<temp<<endl;
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
				cout<<"top	"<<myStack.Top<<endl;
				cout<<"2nd lst		"<<myStack.Array[myStack.Top-1]<<"			lst		"<<myStack.Array[myStack.Top]<<endl;
//				int operand_2 = myStack.Array[myStack.Top];
//				int operand_1 = myStack.Array[myStack.Top-1];
//				Pop();
//				Pop();
				int operand_2 = Pop();
				int operand_1 = Pop();
				Push(operand_1 + operand_2);
				
			}
				break;
			
			case '-' :
			{
				cout<<"enter"<<endl;
				if(isdigit(Equation[currentIndex+1]))
				{
					int number = (Equation[currentIndex+1] - '0') * -1;
					Push(number);
					currentIndex++;
				}
				else
				{
					cout<<"enter2"<<endl;
					int operand_2 = Pop();
					int operand_1 = Pop();
					Push(operand_1 - operand_2);
				}
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
			
			case '%' :
			{
				int operand_2 = Pop();
				int operand_1 = Pop();
				Push(operand_1 % operand_2);
			}
				break;
			case '^' :
			{
				int operand_2 = Pop();
				int operand_1 = Pop();
				Push(pow(operand_1,operand_2));
			}
				break;
			case '#' :
			{
				//ignore spaces
			}
				break;
			case ' ' :
			{
				//ignore spaces
			}
				break;
			default :
			{
//				Push(Equation[currentIndex] - '0');
//				cout<<"Pushed	"<<Equation[currentIndex]<<endl;

				int number = 0;
				while(isdigit(Equation[currentIndex]))
				{
					number = number * 10 + (Equation[currentIndex] - '0');
					currentIndex++;
				}
				Push(number);
				currentIndex--;
			}
				break;
		}
		
		cout<<endl;
		for(int pr = 0 ; pr <=myStack.Top ; pr++)
			cout<<myStack.Array[pr]<<" , ";
		cout<<endl;
	}
	
}

int main()
{
	myStack.Top = -1;
	char i = 0 , Equation[50];
	cout<<"Enter Equation : ";
//	while(cin>>Equation[i])
//		i++;
	cin.getline(Equation , 50);
	
	postfixEvaluation(Equation,strlen(Equation));
	cout<<"top	"<<myStack.Top<<endl;
	cout<<"Evaluation:	"<<myStack.Array[myStack.Top];
}
