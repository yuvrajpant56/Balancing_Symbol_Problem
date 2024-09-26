def areBracketBalanced_pascal(expr):
  stack=[]
  tokens=[]
  i=0
  while i<len(expr):
    if expr[i:i+5]=="begin":
      tokens.append("begin")
      i+=5
    elif expr[i:i+3]=="end":
      tokens.append("end")
      i+=3
    else:
      tokens.append(expr[i])
      i+=1
  
 
  tokens = [token for token in tokens if token in ["begin","(","{","[","end",")","]","}"]]

# Output the cleaned list
  print(tokens)

  


  for char in tokens:
    if char in ["begin","(","{","["]:
      stack.append(char)
    else:
      if len(stack)==0:
        return "Unbalanced"
      
      current_char=stack.pop()
      if current_char=='(':
        if char!=")":
          return "Unbalanced"
      
      if current_char=='{':
        if char!="}":
          return "Unbalanced"
      
      if current_char=='[':
        if char!="]":
          return "Unbalanced"
        
      if current_char=='begin':
        if char!="end":
          return "Unbalanced"
        
        
  if len(stack)!=0:
    return "Unbalanced"
  return "Balanced"     

def areBracketBalanced_cplusplus(expr):
  stack=[]
  tokens=[]
  i=0
  while i<len(expr):
    if expr[i:i+2]=="/*":
      tokens.append("/*")
      i+=2
    elif expr[i:i+2]=="*/":
      tokens.append("*/")
      i+=2
    else:
      tokens.append(expr[i])
      i+=1
  
 
  tokens = [token for token in tokens if token in ["/*","(","{","[","*/",")","]","}"]]

# Output the cleaned list
  print(tokens)

  


  for char in tokens:
    if char in ["/*","(","{","["]:
      stack.append(char)
    else:
      if len(stack)==0:
        return "Unbalanced"
      
      current_char=stack.pop()
      if current_char=='(':
        if char!=")":
          return "Unbalanced"
      
      if current_char=='{':
        if char!="}":
          return "Unbalanced"
      
      if current_char=='[':
        if char!="]":
          return "Unbalanced"
        
      if current_char=='/*':
        if char!="*/":
          return "Unbalanced"
        
  if len(stack)!=0:
    return "Unbalanced"
  return "Balanced"     
      
  
if __name__=="__main__":
# Example test cases
  print("************** ENTER number {1} TO CHECK FOR BALANCING SYMBOLS IN THE PASCAL LANGUAGE**********")

  print("************** ENTER NUMBER {2} TO CHECK FOR BALANCING SYMBOLS IN THE C++ LANGUAGE**********")
  PASCAL=1;
  CPLUSCPLUS=2;
  num=int(input('enter a number:'))

  if PASCAL==num:
    expr=input("Enter the balancing symbol for PASCAL Language:")
    print("the expression enter by user is {expr}")
    print(areBracketBalanced_pascal(expr))
  elif CPLUSCPLUS==num:
    expr=input("Enter the balancing symbol for C++:")
    print("the expression enter by user is {expr}")
    print(areBracketBalanced_cplusplus(expr))
  else:
    print("You Entered Invalid Number: Sorry")



  



