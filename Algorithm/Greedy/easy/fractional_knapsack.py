

def fractionalKnapsack(val,wt,capacity):
  n =len(val)
  
  # find ratio
  ratio = [ [val[i]/wt[i], i ] for i in range(n)]
  print(ratio)
  
  # sort radio
  ratio.sort(reverse=True)
  print(ratio)

  

  res = 0.0
  
  for i in range(n):
    
    if capacity<=0:
      break
      
    if wt[ ratio[i][1] ] <= capacity:
      capacity -= wt[ ratio[i][1] ]
      res =res + val[ratio[i][1]]
    else:
      res = res + val[ ratio[i][1] ] / wt[ ratio[i][1] ] * capacity
      
      
      
  return res
      
     
      

      
    
  
  
  

if __name__ == "__main__":
  val = [60, 100, 120]
  wt = [10, 20, 30]
  capacity = 50
  print(fractionalKnapsack(val, wt, capacity))
  