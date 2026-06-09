#https://www.geeksforgeeks.org/dsa/greedy-algorithms/


def Smallest_subset(arr):
    
    #---- sum 
    total = sum(arr)
    
    #---- sort
    arr.sort(reverse=True)
    
    # count until sub_set_sum less then total
    count,sub_sum=0,0
    
    while sub_sum<total:
        count=count+1
        sub_sum+=arr[0]
        total-=sub_sum
     
        arr.pop(0)
        
       
    print(f"Answer : {count}")    
    return count




    
    
if __name__ == "__main__":
    arr =[3, 1, 7, 1]
    Smallest_subset(arr)