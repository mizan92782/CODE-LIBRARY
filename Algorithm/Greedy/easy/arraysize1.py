#https://www.geeksforgeeks.org/dsa/minimum-cost-make-array-size-1-removing-larger-pairs/


def minimumcost(n,minval):
  return (n-1)*minval
  



if __name__== "__main__":
  
  '''remove al element except minimum bumber and  result wil lbe (n-1)*min_array)'''
  a = [ 4, 3, 2 ]
  n = len(a)
  minval = min(a)
  
  print(minimumcost(n,minval))
   
  