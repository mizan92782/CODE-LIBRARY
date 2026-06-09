#https://www.geeksforgeeks.org/dsa/assign-cookies/


def greedy_cookies_child(greed:list,cookie:list)->int:
    
    #--- sort greed : sort child according to their deman
    greed.sort()
    #------ sort cookie
    cookie.sort()
    
    
    
    i =0
    j=0
    count=0
    
    while i < len(greed) and j< len(cookie):
        
        # if satisfied
        if greed[i]<=cookie[j]:
            count+=1
            i,j=i+1,j+1
        else:
            j+=1
            
    
    return count
            

if __name__ == "__main__":
    greed = [1, 10, 3]
    cookie = [1, 2,3]
    
    result=f"Satisied child :  { greedy_cookies_child(greed,cookie)}"
    print(result)