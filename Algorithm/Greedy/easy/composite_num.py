#https://www.geeksforgeeks.org/dsa/split-n-maximum-composite-numbers/
def max_composite_count(n:int)->int:
    
    # if n less than 4 no composite
    if n<4:
        return -1
        
    # if divided by 4
    if n%4==0:
        return n//4
        
        
    # if have reminder
    rem = n%4
    
    # if reminder ==1:
    '''if  9 : 4*0 + 9'''
    if rem==1:
        if n<9:
            return -1
        return (n-9)//4+1
        
        
    # if rem =2
    if rem==2:
        return ((n-6)//4)+1
    
        
    #if rem ==3
    if rem ==3:
        if n<15:
            return -1
        
        return (n-15)//4+2
        
        
        
result=max_composite_count(143)
print(result)

        
# #================================
# if __name__== '__main__':
#     max_composite_count(23)
