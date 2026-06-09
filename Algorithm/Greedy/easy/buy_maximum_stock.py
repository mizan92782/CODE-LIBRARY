#https://www.geeksforgeeks.org/dsa/buy-maximum-stocks-stocks-can-bought-th-day/

from typing import List

class DayPrice:
    def __init__(self,day,price):
        self.day = day
        self.price = price



class Solution:
    def buyMaximumProducts(self, k : int, price : List[int]) -> int:
        
        dayprice=[]
        
        for i,v in enumerate(price):
            dayprice.append(DayPrice(day=i+1,price=v))
            
        
        #sort
        dayprice.sort(key=lambda x:x.price)
        
        
        
        stock=0
        
        for x in dayprice:
            
            able = k//x.price
            stock_buy = min(x.day,able)
            stock+=stock_buy
            k=k-stock_buy*x.price
            
            
        return stock
        
               
        