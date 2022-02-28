#pragma once

const int maxstack = 10;
typedef double Stack_entry;

enum Error_code {
        success, fail, utility_range_error, underflow, overflow, fatal,
        not_present, duplicate_error, entry_inserted, entry_found,
        internal_error
};

class Stack {
public:
   Stack();
   Error_code pop();
   Error_code push(const Stack_entry &item);
   Error_code top(Stack_entry &item) const;
   bool empty() const;
   void clear();
   bool full() const ;
   int size() const;
private:
   int count;
   Stack_entry entry[maxstack];
};