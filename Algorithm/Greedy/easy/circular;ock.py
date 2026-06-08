
def findminimum(number ,lock):
   a = min (abs(lock-number),abs(10-lock+number))
   print(a)
   return a
  

def circularLockBreak(input,unloack):
  
  res=0
  while input != 0:
    input_last_digit = input%10
    unloack_last_digti = unloack%10
    
    #reduce one last digit
    input=int(input/10)
    unloack=int(unloack/10)
    
    #calculate result
    res=res + findminimum(input_last_digit,unloack_last_digti)
  
  return res
    
    

if __name__ == "__main__":
  input = 28756
  unlock_code = 98234
  print(circularLockBreak(input,unlock_code))
  