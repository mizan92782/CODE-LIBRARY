#include<bits/stdc++.h>
using namespace std;


// trie node
 struct node
{
   bool endmark;
   node* next[26+1];
   node()
   {
     endmark =false;
     for(int i=0;i<26;i++)
     {
      next[i]=NULL;
      }
   
   }
};





//insert trie;

void insert(node* root,string str)
{
      node* cur=root;

      //! construct tree for node
      int len=str.size();
  

  // here len definte ,how many time we should check
  //its not define that ,we travering every index of str
  //bcs if once we get null ,then we termicante the function
  for(int i=0;i<len;i++)
  {
            
            int id=str[i]-'a';
            
            //if 'id' child in empty,then create a child node;
            if(cur->next[id]==NULL)
            {
               cur->next[id]= new node();
            }

            //! then goto this child node for contruct child
            cur=cur->next[id];
      }


      
      //this node  make  a string or here a string
      cur->endmark=true;
}





bool search_node(node* root,string str)
{
  node* cur=root;
  int len=str.size();
  

  // here len definte ,how many time we should check
  //its not define that ,we travering every index of str
  //bcs if once we get null ,then we termicante the function
  for(int i=0;i<len;i++)
  {
      int id=str[i]-'a';

      // if not match
      if(cur->next[id]==NULL)
      {
        return false;
      }

      cur=cur->next[id];
  }

  return cur->endmark;
}


//!delete s string a from trie;

void removestringFromTre(node* root,string str)
{
       node* cur=root;

       int len=str.size();
       for(int i=0;i<len;i++)
       {
           int id=str[i]-'a';

           // if str not exist in trie;
           if(cur->next[id]==NULL){
           return;
           }

           cur=cur->next[id];
        
       }



       //if programm come here and endmark==1 
       //that means str exist in trie
       //so so we make endmark==0 as it remove

       cur->endmark=0;

       
}


//! ++++++++++ Delete trie;
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}










//! ********************* Dispaly the trie value;
//https://www.geeksforgeeks.org/trie-display-content/
void Display_Content(node* root,string str){
 
    //* if its a endmark or string end,then print string;
    if(root->endmark==true)
    {
      cout<<str<<endl;
      
    }


    //loop will check every character of root node;
    //bcs root node stored all string first character
    for(int i=0;i<26;i++)
    {
      
      if(root->next[i])
      {
       
       //this line is very very importang
        Display_Content(root->next[i],str+char(i+'a'));
      }
    }

}









//! *********** auto Seggetion

// suggetion of given node
void suggetionRec(node* root,string prefix)
{
 
     // found a string with given prefix
     if(root->endmark==true)
     {
      cout<<prefix<<endl;
     }


     for(int i=0;i<26;i++)
     {
        if(root->next[i])
        {
            
            suggetionRec(root->next[i],prefix+char(i+'a'));
        }
     }
}



void printSuggetions(node* root,string prefix)
{
       node* cur=root;

       for(char c:prefix)
       {
          int ind=c-'a';
          

          //if we dont find this prefix,then ther is no such prefix  string
          if(cur->next[ind]==NULL)
          {
            cout<<endl<<"thter is no such prefix string\n";
           return;
          }
           
         
          cur=cur->next[ind];
          
       }



       //if programmm comes here,that means we find this prfix string
        
      //check is ther any subtree of prefix node

      bool isanysubtree=false;
      for(int i=0;i<26;i++)
      {
        if(cur->next[i]!=NULL)
        {
          isanysubtree=true;
          break;
        }
      }


      if(isanysubtree==false)
      {
        cout<<"there exit prefix but no any prefix string";
        return;
      }

      // exist prefix string
      cout<<"prefix now :  "<<endl;
      suggetionRec(cur,prefix);
}

int main()
{

        /*
         Shafayat : https://www.shafaetsplanet.com/?p=1679
        */
        node* root= new node();


        vector<string>arr={"app","apple","banana","orange","pinaple","mango","application","applet","apply"};
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
         insert(root,arr[i]);
        }



        if(search_node(root,"apple"))
        {
         cout<<"find"<<endl;
        }else{

        cout<<"not found"<<endl;
        
        }


        if(search_node(root,"banana"))
        {
         cout<<"find"<<endl;
        }else{

        cout<<"not found"<<endl<<endl;
        
        }

        
        cout<<endl;
        cout<<"delete a string: "<<endl;
        removestringFromTre(root,"apple");
        cout<<endl;



         if(search_node(root,"apple"))
        {
         cout<<"find"<<endl;
        }else{

        cout<<"not found"<<endl;
        
        }


        if(search_node(root,"banana"))
        {
         cout<<"find"<<endl;
        }else{

        cout<<"not found"<<endl;
        
        }




        cout<<"\nDispaly content :   \n\n";
        string str="";
        Display_Content(root,str);


        cout<<endl<<endl;


        printSuggetions(root,"app");


    return 0;
}
