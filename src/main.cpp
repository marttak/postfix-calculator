#include <iostream>
#include <limits>
#include "Stack.h"
using namespace std;

char get_command();
bool do_command(char command, Stack &numbers);
void introduction();
void instructions();

// Simple postfix styled calculator that prompts user to give commands.
// Uses class Stack

int main()
{
   Stack stored_numbers;
   
   introduction();
   instructions();
   while(do_command(get_command(), stored_numbers));

   return 0;
}

char get_command()
{
   char command;
   bool waiting = true;

   cout << "Select command and press <Enter>:";

   while (waiting) {

      cin >> command;
      command = tolower(command);

      if (command == '?' || command == '=' || command == '+' ||
          command == '-' || command == '*' || command == '/' ||
          command == 'q' || command == 'x' || command == 's' ||
          command == 'a') waiting = false;


      else {
         cout << endl << endl;
         instructions();
         cout << "Select command and press <Enter>:";
      }
   }
   return command;
}


bool do_command(char command, Stack &numbers)

// The command specified by the first parameter
// has been applied to the Stack of numbers given by the second parameter.
// A result of true is returned unless command == 'q'.

{
   double p, q, sum, avg;
   int count = 0;

   switch (command) {
   case '?':
      //cout << "Enter a real number: " << flush;
      while(cout << "Enter a real number: " && !(cin >> p)){
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid input; please re-enter." << endl;
      }

      if (numbers.push(p) == overflow)
         cout << "Warning: Stack full, lost number" << endl;
      break;

   case '=':
      if (numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else
         cout << p << endl;
      break;

   case '+':
      if (numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q + p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;
   
   case '-':
      if(numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if(numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         } 
         
         else {
            numbers.pop();
            if(numbers.push(q - p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }

      break;
   
   case '*':
      if(numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if(numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         } 
         
         else {
            numbers.pop();
            if(numbers.push(q * p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;
   
   case '/':
      if(numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if(numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         } 
         
         else {
            numbers.pop();
            if(numbers.push(q / p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;

   case 'x':
      if(numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if(numbers.top(q) == underflow){
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         }
         else {
            numbers.pop();
            numbers.push(p);
            numbers.push(q);
         }
      }
      break;
   
   case 's':
      if(numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         while(!numbers.empty()){
            numbers.top(p);
            sum += p;
            numbers.pop();
         }
         numbers.push(sum);
      }
      break;
   
   case 'a':
      if(numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         while(!numbers.empty()){
            numbers.top(p);
            sum += p;
            count++;
            numbers.pop();
         }
         avg = sum / count;
         numbers.push(avg);
      }
      break;

   case 'q':
      cout << "Calculation finished.\n";
      return false;
   }

   return true;
}

void introduction(){
   cout << "Welcome! This is a simple Postfix styled calculator." << endl
        << "Postfix notation is a mathematical notation in which operators follow their operands." << endl
        << "Example: '3 4 +' produces answer 7."
        << endl << endl;
}

void instructions(){
   cout << "Use following commands:"   << endl
              << "[?]push to stack   [=]print top" << endl
              << "e[x]change positions of two topmost numbers" << endl
              << "[s]um of all numbers in stack" << endl
              << "[a]verage of all numbers in stack" << endl
              << "[+] [-] [*] [/]   are arithmetic operations" << endl
              << "[Q]uit." << endl << endl;
}