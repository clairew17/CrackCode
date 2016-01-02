//PostFixEvaluation.cc
#include<iostream>
#include<cctype>
#include<stack>
using namespace std;

int eval(int op1, int op2, char op){
   switch(op){
      case('+'):return op1+op2;
      case('-'):return op1-op2;
      case('*'):return op1*op2;
      case('/'):return op1/op2;
      default: return 0;
   }
}

int evalPostfix(char arr[], int sz){
   int res = 0;
   char ch;int op1,op2;
   stack<int>m_stack;
   for(int i=0;i<sz;i++){
      ch = arr[i];
      if(isdigit(ch)){
         m_stack.push(ch-'0');
      }else{
         if(m_stack.size()<2){
            cout << "Missing operands!\n";
            return 0;
         }

         op1 = m_stack.top();m_stack.pop();
         op2 = m_stack.top();m_stack.pop();

         res += eval(op1,op2,ch);
      }
   }
   if(!m_stack.empty()){
      cout <<"Missing Operators\n";
      return 0;
   }
   return res;
}


// main
int main() {
   char postfix[] = {'5','6','8','+','*','2','/'};
   int size = sizeof(postfix);
   int val = evalPostfix(postfix, size);
   cout<<"\nExpression evaluates to "<<val;
   cout<<endl;
   return 0;
}