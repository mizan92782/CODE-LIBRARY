 make_equal_length(one,two);
       int l=one.size();

       int carry=0;
       string str="";

       for(int i=l-1;i>=0;i--)
       {
             int  fb=one[i]-'0';
             int sb=two[i]-'0';

             int sum=(fb^sb^carry);
             carry=(sb & fb) | (sb & carry) | (fb & carry);

             str=char(sum+'0')+str;
       }

       if(carry)
       {
            str="1"+str;

       }