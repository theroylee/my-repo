/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include "infix.h"
using namespace std;

/**********************************************
 * stack : getOrderNumber
 * Allows for us to get the order of the operations for the stack
 *
 **********************************************/
int getStackNumber(char symbol)
{
    int number = 0;
    
    switch (symbol)
    {
        case '^':
            number = 3;
            break;
            
        case '*':
        case '/':
        case '%':
            number = 2;
            break;
            
        case '+':
        case '-':
            number = 1;
            break;
    }
    
    return number;
}

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postfix "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
    string postfix;
    postfix += ' ';
    

    stack <char> opStack;
   
    for (int iInfix = 0; iInfix <= infix.size()-1; iInfix++)
    {
        if (isalpha(infix[iInfix]) || isdigit(infix[iInfix]) || infix[iInfix] == '.')
        {
            postfix += infix[iInfix];
        }
        else
        {
            switch (infix[iInfix])
            {
                case '(':
                    opStack.push(infix[iInfix]);
                    break;
                    
                case ')':
                    while (opStack.top() != '(')
                    {
                        //cerr << "IN LAST PARENTHASY\n";
                        postfix += opStack.top();
                        opStack.pop();
                    }
                    opStack.pop();
                    break;
                    
                case '.':
                    postfix += infix[iInfix];
                    break;
                    
                case ' ':
                    postfix += ' ';
                    break;
                    
                default:
                    while (!opStack.empty() &&  getStackNumber(infix[iInfix]) <= getStackNumber(opStack.top()))
                    {
                        postfix += opStack.top();
                        opStack.pop();
                        postfix += ' ';
                    }

                    opStack.push(infix[iInfix]);
                    
                    if (getStackNumber(infix[iInfix]) != 0 && !isalpha(infix[iInfix + 1]) && !isdigit(infix[iInfix + 1]))
                        iInfix++;

                    
                    break;
            }
        }
    }

    postfix += ' ';

    while(!opStack.empty())
    {
        postfix += opStack.top();
        opStack.pop();
        
        if (!opStack.empty())
            postfix += ' ';
    }

    return postfix;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);

      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\tpostfix: " << postfix << endl;
      }
      cout << endl;
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;
    
   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
      
}
