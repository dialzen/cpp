#include <iostream>
#include <string>
using namespace std;

/* C++ program to implement basic stack 
operations */
#include <bits/stdc++.h> 

using namespace std; 

#define MAX 1000 

class Stack { 
	int top; 

public: 
	int a[MAX]; // Maximum size of Stack 

	Stack() { top = -1; } 
	bool push(int x); 
	int pop(); 
	int peek(); 
	bool isEmpty();
    int gettop() {
        return top;
    } 
}; 

bool Stack::push(int x) 
{ 
	if (top >= (MAX - 1)) { 
		cout << "Stack Overflow"; 
		return false; 
	} 
	else { 
		a[++top] = x; 
		cout << x << " pushed into stack\n"; 
		return true; 
	} 
} 

int Stack::pop() 
{ 
	if (top < 0) { 
		cout << "Stack Underflow"; 
		return 0; 
	} 
	else { 
		int x = a[top--]; 
		return x; 
	} 
} 
int Stack::peek() 
{ 
	if (top < 0) { 
		cout << "Stack is Empty"; 
		return 0; 
	} 
	else {
		return a[top]; 
	} 
} 

bool Stack::isEmpty() 
{ 
	return (top < 0); 
} 

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
}



string infix_to_postfix(string s)  {
    Stack st;
    st.push('N'); 
    int l = s.length(); 
    string ns; 
    for(int i = 0; i < l; i++) 
    { 
        // If the scanned character is an operand, add it to output string. 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) 
        ns+=s[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(s[i] == '(') 
          
        st.push('('); 
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(s[i] == ')') 
        { 
            while(st.gettop() != 'N' && st.gettop() != '(') 
            { 
                char c = st.gettop(); 
                st.pop(); 
               ns += c; 
            } 
            if(st.gettop() == '(') 
            { 
                char c = st.gettop(); 
                st.pop(); 
            } 
        } 
          
        //If an operator is scanned 
        else{ 
            while(st.gettop() != 'N' && prec(s[i]) <= prec(st.gettop())) 
            { 
                char c = st.gettop(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(s[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.gettop() != 'N') 
    { 
        char c = st.gettop(); 
        st.pop(); 
        ns += c; 
    } 
      
    
    return ns;
}

int main() {
    string exp;
    cout<<"Enter infix: "; cin>>exp;
    string postfix = infix_to_postfix(exp);
    cout << postfix << endl;
    return 0;
}