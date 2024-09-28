#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/trie-insert-and-search/
// https://www.geeksforgeeks.org/introduction-to-trie-data-structure-and-algorithm-tutorials/
// https://cp-algorithms.com/string/aho_corasick.html

struct node
{

     // flag
     bool endmark;
     int countprefix;
     // childs
     node *next[26 + 1];

     // assing flag and node value
     node()
     {
          // nod string end here
          // also can find how many string have this prefix ;
          endmark = false;
          countprefix = 0;

          // no child initially
          for (int i = 0; i < 26; i++)
          {
               next[i] = NULL;
          }
     }
};

void insert(node *root, string str)
{

     // trie length==str.length
     int len = str.size();

     // making trie fot str

     for (int i = 0; i < len; i++)
     {
          // find child
          int id = str[i] - 'a';

          if (root->next[id] == NULL)
          {
               // if every lenght create next trie node;
               root->next[id] = new node();
          }

          //! then goto this child node for construct for next child
          root = root->next[id];
          // make flage and define prefix
          root->countprefix++;
     }

     // last not whrer trie reach for this string
     root->endmark = true;
}

// !  display full trie;

void DisplayTrieContent(node *root, string str)
{

     //! if a string end here
     if (root->endmark == true && str != "")
     {
          cout << str << endl
               << endl;
     }

     // then check for all child so thar find is there any trie for this node
     // or any string have with this prefix

     for (int i = 0; i < 26; i++)
     {
          if (root->next[i] != NULL)
          {
               // this trie maked this prefix
               // also can see how many string have this prefix

               str = str + char(i + 'a');

               cout << str << " : " << root->next[i]->countprefix << endl;

               // treverse for next trie

               DisplayTrieContent(root->next[i], str);
          }
     }
}







//! =============== search  word   ===========


bool Search_word(node* root,string str)
{
     // * str is searching str


     int len=str.size();
     //* len iterater len time in trie to search this word in tri


     //* checking in trie from str[0] to str[len-1]

     for(int i=0;i<len;i++)
     {
          int id=str[i]-'a';
          
          // trie not find the i character in  trie level
          if(root->next[id]==NULL)
          {
               return false;
          }

          
          //! forwading trie for next level
          root=root->next[id];
     }


     //after iterate for str 0 index to len-1;
     //program reach here means we fing all trie word for str in trie;
     //now we have to check is a word is end here,if true that means this str is find in trie

     return root->endmark;
}









//!  ======================= Delete From Trie ===============

void DeleteString(node* root,string str)
{
      int len=str.size();

      for(int i=0;i<len;i++)
      {
             int id=str[i]-'a';


             // that means this string not exits in trie;
             if(root->next[id]==NULL) return;

             root=root->next[id];
      }


        //if programm come here and endmark==true;
       //that means str exist in trie
       //so so we make endmark==fale as it remove

       root->endmark=false;
}














//! =================== Suggest string / Prefix string ===========
// this programm will print all string with this prefix
 void SuggestPrefixString(node* root,string prefix){
              
          //if this is string
          if(root->endmark)
          {
               cout<<prefix<<endl;
          }


          for(int i=0;i<26;i++)
          {
                 // that means ther is prefix string
                 if(root->next[i]!=NULL){
                  
                    SuggestPrefixString(root->next[i],prefix+char(i+'a'));
                 }
          }
 }

void PrintAllPrefixString(node* root,string prefix)
{
        int len=prefix.size();

        for(int i=0;i<len;i++)
        {
               int id=prefix[i]-'a';

               //* that means this prefix to in trie;
               if(root->next[id]==NULL){
                 return ;
               }


               root=root->next[id];
        }

         

        //* programm comes here means we find this prefix

        SuggestPrefixString(root,prefix);




}



int main()
{

     // make trie
     node *root = new node();
     vector<string> arr = {"app", "banana", "orange", "bangladesh", "apple", "apply"};
     int n = arr.size();
     for (int i = 0; i < n; i++)
     {
          insert(root, arr[i]);
     }

     // trie
     DisplayTrieContent(root, "");



     if(Search_word(root,"app"))
     {
        cout<<"Find the word"<<endl;
     }else{ 
          
          cout<<"not find"<<endl;
     }




     if(Search_word(root,"appo"))
     {
        cout<<"Find the word"<<endl;
     }else{ 
          
          cout<<"not find"<<endl;
     }




     //! delete app

   //  DeleteString(root,"app");




      if(Search_word(root,"app"))
     {
        cout<<"Find the word"<<endl;
     }else{ 
          
          cout<<"not find"<<endl;
     }




  


     //! suggest string

      PrintAllPrefixString(root,"app");




     return 0;
}