#include<bits/stdc++.h>
using namespace std;

//!======= find a substing ==========
void serachSubSting(string str,string s){
   (str.find(s) != string::npos) ? cout<<"find" : cout<<"not find";
}

//! ========== is subsequence ===========
bool isSubsequence(){
   
   string one="subsequence";
   string two ="sen";

   int n=one.size();
   int m=two.size();

   //base case
   if(m>n) return false;

   int mi=0;
   
   //check subsequence
   for(int i=0;i<n;i++){
      if(one[i]==two[mi]){
        mi++;
      }
      
      //if find full sub
      if(mi==m) return true;
   }

  return false;
}


//! ======= two string anagrams or not
bool isAnagram()
{
   string one="geeks";
   string two="gksee";

   if (one.size() != two.size()) return false;

   vector<int> first(26,0);
   vector<int> second(26,0);

   for(int i=0;i<one.size();i++) first[one[i]-'a']++;
   for(int i=0;i<two.size();i++) second[two[i]-'a']++;

   for(int i=0;i<26;i++){
    if(first[i]!=second[i]) return false;
  }

  return true;
}


//! ====== Generate all binary strings from given pattern ('01?1?01")

void GenerateBinaryString(string str,string s,int ind){
   
    if(ind==str.size()){
      cout<<s<<endl;
      return ;
    }

    if(str[ind]=='?'){
    // make it zero first,then zero
    
    GenerateBinaryString(str,s+'0',ind+1);
    GenerateBinaryString(str,s+'1',ind+1);
    }else{
     
      GenerateBinaryString(str,s+str[ind],ind+1);
    }
}




//! ====================== permutation string ===========

void permutation_util(string &str, int index, int end)
{

    if (index == end)
    {
        cout << str << " ";
    }
    else
    {

        for (int i = index; i <= end; i++)
        {

            /*
             * swap a specific index with other index whose right of him
             * every specific index comes by recursive call
             * and return by backtraking
             * its bottom up approach
             */
            swap(str[index], str[i]);

            //  * recursive call until last index
            permutation_util(str, index + 1, end);

            // ** return past string by swapping again
            //** ex : ABC ->>ACB >ABC
            // *this  is brack

            swap(str[index], str[i]);
        }
    }
}



void permutation(string &str)
{
    int end = str.size() - 1;

    // !! for lexicographically print
     // sort(str.begin(),str.end())
     
    //  ** permutation util
    permutation_util(str, 0, end);
}



// !========= next lexigraphical words;
//https://www.geeksforgeeks.org/dsa/lexicographically-next-string/
string nextWord(string s)
{
    // If string is empty.
    if (s == "")
        return "a";

    // Find first character from right 
    // which is not z.
    
    int i = s.length() - 1;
    while (s[i] == 'z' && i >= 0)
        i--;

    // If all characters are 'z', append
    // an 'a' at the end.
    if (i == -1) 
        s = s + 'a';

    // If there are some non-z characters 
    else
        s[i]++;

    return s; 
}




//!=============== KMP-- pattern searching========

vector<int> LPS(string ptr)
{
 int n = ptr.size();
 vector<int>lps(n,0);

 int len=0;
 //staring from index 1
 int i=1;

 while (i<n)
 {
    if(ptr[len]==ptr[i]){
      
      //as find a prefix ,increse length
      len++;
      //set lps
      lps[i]=len;
      //ge for next index
      i++;
    }else{
                                                    // |----|
       //if not match prefix : go to previous lentgh:aaabaaaa ,0,1,2,0,1,2,3,3
       // that mens aaa mach with aaa of aaaa
       //when we increase len 1 but then it match that mens with its first a ,last there a  also match
       if(len!=0){
       len=lps[len-1];
       }else{

       lps[i]=0;
       i++;
       }

       
    }
 }
 

return lps;

}






void KMPSearch(){
 
 string txt = "aabaacaadaabaaba";
 string pat = "aaba";

 int n=txt.size();
 int m=pat.size();
 vector<int>lps=LPS(pat);


 int i=0;
 int j=0;

 while ((n-i)>=(m-j))
 {
    if(txt[i]==pat[j]){
    i++;
    j++;

    //as its find a pattern,
    //tahole dakhte hobe last word er lps kot,that means
    // ata koita prefix contain kore ,jeta lps thake buja abe
    // j k sekhane assing korte hobe
    //supposer: aabaabaa pat:aabaa
    // after find patteren ,we get that j=lps[j-1] =2]
      //so match again (ptr[2]=b )==(str[i]=b)

      //! main kotah:where previous word match
      if(j==m){
      cout<<"found : "<<(i-j)<<endl;
      j=lps[j-1];
      }

    }else{
      
      if(j!=0){
      //! where previous word match
       j=lps[j-1];
      }else{
      i++;
       
      }
    }
    
    
 }
 

 
}



int main(){

  string str="mizanur";
  string s="zan";

  KMPSearch();

 

    //string input = "1?0?"; // Example input
    //GenerateBinaryString(input, "", 0);


}