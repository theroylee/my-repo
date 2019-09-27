/***********************************************************************
* Header:
*    INFIX      
* Summary:
*    This will contain just the prototype for the convertInfixToPostfix()
*    function
* Author
*    <your names here>
************************************************************************/

#ifndef INFIX_H
#define INFIX_H

#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
#include <cctype>

int getStackNumber(char symbol);


std::string convertInfixToPostfix(const std::string & infix);


/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix();

string convertPostfixToAssembly(const string & postfix);

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly();

#endif // INFIX_H

