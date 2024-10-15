#include <bits/stdc++.h>

using namespace std;

 

int main()

{

 

 int N, Q;

 cin >> N >> Q;

 

 vector<long long int> V(N);

 

 for (int i = 0; i < N; i++) // O(N) 

 {

 cin >> V[i];

 }

 

 

 vector<long long int> prefix_sum(N) ;

 

 prefix_sum[0] = V[0] ; // প্রিফিক্স সাম এরে এর প্রথম ভ্যালুটি হবে এরে এর প্রথম ভ্যালুটি

 

 for(int i =1 ;i<N ;i++){

 prefix_sum[i] = prefix_sum[i-1]+V[i] ;

 }

 

 for (int i = 1; i <= Q; i++) // O(Q) 

 {

 

 int L, R;

 cin >> L >> R;

 L--; R--; // converting the position to array index

 

 long long int SUM = 0;

 

 // for (int j = L; j <= R; j++) // O(N) -> কারণ আমাদের প্রত্যেকবার L এর মান ১ এবং R এর মান N পর্যন্ত দেয়া হতে পারে 

 // {

 

 // SUM += V[j];

 // } // এই লুপটি বাদ দিয়ে এখন আমরা প্রিফিক্স সাম টেকনিক ব্যবহার করবো 

 

 

 if(L==0){

 SUM = prefix_sum[R];

 } // যদি L এর মান ০ হয় তবে L-1 invalid হয়ে যাবে। সেইক্ষেত্রে শুরু থেকে নিয়ে R পর্যন্ত হবে সাম

 else SUM = prefix_sum[R]-prefix_sum[L-1] ; // O(1) 

 

 cout << SUM << endl;

 }

}
