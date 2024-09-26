#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;


// A PROGRAM TO CHECK FOR BALANCING SYMBOLS IN THE PASCAL LANGUAGES......
string areBracketBalanced_pascal(const string &expr) {
    stack<string> stk;
    vector<string> tokens;
    int i = 0;

    // Tokenize the input
    while (i < expr.length()) {
        if (expr.substr(i, 5) == "begin") {
            tokens.push_back("begin");
            i += 5;
        } else if (expr.substr(i, 3) == "end") {
            tokens.push_back("end");
            i += 3;
        } else {
            tokens.push_back(string(1, expr[i]));
            i++;
        }
    }

    // Remove spaces from the tokens
    // List of valid tokens
    vector<string> validTokens = {"begin", "(", "{", "[", "end", ")", "]", "}"};

    // Cleaned tokens vector
    vector<string> cleanedTokens;

    for (int i=0;i<tokens.size();i++){
      string token=tokens[i]; 

      for (int j=0; j<validTokens.size();j++){
        if (token==validTokens[j]){
          cleanedTokens.push_back(token);
          break;
        }
      }
    }
        // Print the cleaned tokens
    cout << "Cleaned tokens: ";
    for (int i = 0; i < cleanedTokens.size(); i++) {
        cout << cleanedTokens[i] << " ";  // Print each token followed by a space
    }
    cout << endl;
     

    // Check the balance of brackets
    for (const string &token : cleanedTokens) {
        if (token == "begin" || token == "(" || token == "{" || token == "[") {
            stk.push(token);
        } else {
            if (stk.empty()) {
                return "Unbalanced";
            }

            string currentChar = stk.top();
            stk.pop();

            if (currentChar == "(" && token != ")") return "Unbalanced";
            if (currentChar == "{" && token != "}") return "Unbalanced";
            if (currentChar == "[" && token != "]") return "Unbalanced";
            if (currentChar == "begin" && token != "end") return "Unbalanced";
        }
    }

    // If stack is not empty, brackets are unbalanced
    if (!stk.empty()) {
        return "Unbalanced";
    }

    return "Balanced";
}



// A PROGRAM TO CHECK FOR BALANCING SYMBOL IN THE C++ LANGUAGES;
string areBracketBalanced_cplusplus(const string &expr) {
    stack<string> stk;
    vector<string> tokens;
    int i = 0;

    // Tokenize the input
    while (i < expr.length()) {
      if (expr.substr(i,2)=="/*"){
          tokens.push_back("/*");
          i+=2;
        } else if (expr.substr(i,2)=="*/"){
          tokens.push_back("*/");
          i+=2;
        }
        else {
            tokens.push_back(string(1, expr[i]));
            i++;
        }
    }

    // Remove spaces from the tokens
    // List of valid tokens
    vector<string> validTokens = {"/*", "(", "{", "[", ")", "]", "}", "*/"};

    // Cleaned tokens vector
    vector<string> cleanedTokens;

    for (int i=0;i<tokens.size();i++){
      string token=tokens[i]; 

      for (int j=0; j<validTokens.size();j++){
        if (token==validTokens[j]){
          cleanedTokens.push_back(token);
          break;
        }
      }
    }


    // Print the cleaned tokens
    cout << "Cleaned tokens: ";
    for (int i = 0; i < cleanedTokens.size(); i++) {
        cout << cleanedTokens[i] << " ";  // Print each token followed by a space
    }
    cout << endl;


    // Check the balance of brackets
    for (const string &token : cleanedTokens) {
        if (token == "/*" || token == "(" || token == "{" || token == "[") {
            stk.push(token);
        } else {
            if (stk.empty()) {
                return "Unbalanced";
            }

            string currentChar = stk.top();
            stk.pop();

            if (currentChar == "(" && token != ")") return "Unbalanced";
            if (currentChar == "{" && token != "}") return "Unbalanced";
            if (currentChar == "[" && token != "]") return "Unbalanced";
            if (currentChar == "/*" && token != "*/") return "Unbalanced";
        }
    }

    // If stack is not empty, brackets are unbalanced
    if (!stk.empty()) {
        return "Unbalanced";
    }

    return "Balanced";
}


int main() {

  cout << "************** ENTER number {1} TO CHECK FOR BALANCING SYMBOLS IN THE PASCAL LANGUAGE **************" << endl;
  cout << "************** ENTER number {2} TO CHECK FOR BALANCING SYMBOLS IN THE C++ LANGUAGE **************" << endl;
    // Example test cases
  
  int PASCAL = 1;
  int CPLUSCPLUS = 2;
  int num;

  cout<<"Enter a Number: ";
  cin >> num; // user enters 1 or 2 

  if (PASCAL==num){
    string expr;
    cout<<"Enter the balancing symbol for PASCAL Language: ";
    cin>>expr; 
    cout<<" The expression entered by user is: "<< expr<<endl;
    cout<<areBracketBalanced_pascal(expr)<<endl;
  }
  else if    (CPLUSCPLUS == num){
    string expr;
    cout<<"Enter the balancing symbol for C++ Language: ";
    cin>>expr;
    cout<<"The expression entered by user is: "<< expr<<endl;
    cout<<areBracketBalanced_cplusplus(expr)<<endl;
  }
  else{
    cout<<"You Entered Invalid Number: Sorry"<<endl;
  }

  return 0;
}
