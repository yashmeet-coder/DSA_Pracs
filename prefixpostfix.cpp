#include <iostream>
#include <stack>
using namespace std;

double prefix(string exp){
  stack<double> stk;
  int size = exp.size() - 1;
  for(int i = size; i >= 0; i--){
    if (isdigit(exp[i])){
      stk.push(int(exp[i])-48);
    }
    else{
      double o1 = stk.top();
      stk.pop();
      double o2 = stk.top();
      stk.pop();
      if (exp[i] == '+'){
        stk.push(o1 + o2);
      }
      else if (exp[i] == '-'){
        stk.push(o1 - o2);
      }
      else if (exp[i] == '*'){
        stk.push(o1 * o2);
      }
      else if (exp[i] == '/'){
        stk.push(o1 / o2);
      }
      else {
        cout << "invalid expression";
        return -1;
      }

    }
  }
  return(stk.top());
}
double postfix(string exp){
  stack<double> stk;
  int size = exp.size() - 1;
  for(int i = 0; i <= size; i++){
    if (isdigit(exp[i])){
      stk.push(int(exp[i])-48);
    }
    else{
      double o1 = stk.top();
      stk.pop();
      double o2 = stk.top();
      stk.pop();
      if (exp[i] == '+'){
        stk.push(o1 + o2);
      }
      else if (exp[i] == '-'){
        stk.push(o1 - o2);
      }
      else if (exp[i] == '*'){
        stk.push(o1 * o2);
      }
      else if (exp[i] == '/'){
        stk.push(o1 / o2);
      }
      else {
        cout << "invalid expression";
        return -1;
      }

    }
  }
  return(stk.top());
}


int main(){
  string exp1 = "*+69-31";
  cout << "result prefix : " << prefix(exp1)<<endl;
  string exp2 = "231*+9-";
  cout << "result postfix : " << postfix(exp2)<<endl;
  return 0;
}