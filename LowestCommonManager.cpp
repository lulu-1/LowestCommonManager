//
//  string_manipulation.cpp
//  Test
//
//  Created by oluchi david on 2019-11-02.
//  Copyright © 2019 oluchi david. All rights reserved.
#include <stdio.h>
#include <stdio.h>
using namespace std;
#include <iostream>
#include<vector>
#include <string.h>
#include <array>
#include <stack>
#include <sstream>
#include <map>
// this function tokonizes the string//
vector <string> Breakdownstrings(string str,char delimeter){
       vector <string> words;
       stringstream s(str);
       string word;
       while(getline(s, word, delimeter))
       {
           words.push_back(word);
       }
    return  words;
}
void Insert_Map(multimap<string, string>& myMap, vector <string> pairs){
    
    for (int i =0; i<pairs.size(); i++){
        
        vector <string> mag_emp = Breakdownstrings(pairs[i],'>');
        string temp;
        for (int i=0; i<mag_emp[0].length()-1; i++){
            temp = temp + mag_emp[0][i];
        }
        myMap.emplace(temp,mag_emp[1]);
    }
}

int main()
{
    string str = "Sam->Pete,Pete->Nancy,Sam->Katie,Mary->Bob,Frank->Mary,Frank->Sam,Bob->John,Sam,Pete";
    
    vector <string> pairs = Breakdownstrings(str,',');
   // The last two strings in pairs represents the employees of conflict 1 (emp1) and 2 (emp2)
  string emp1 = pairs.back();
  pairs.pop_back();
 string emp2 = pairs.back();
  pairs.pop_back();
    // created a multimap and inserted keys and values to it.
    multimap <string, string> myMap;
    Insert_Map(myMap,pairs);
//initialized iterators 1 and 2 to check if the employees are also managers
    map <string, string>:: iterator itr = myMap.find(emp1);
    map <string, string>:: iterator itr2 = myMap.find(emp2);
    map <string, string>:: iterator it;

 //if employee 1 isn't a manager then initialize employee's manager to be employee of conflict (new_emp2) // else emp2 remains the employee of conflict.
    string new_emp2;
      string new_emp1;
    if (itr == myMap.end())
    {
        //cout<< "emp1 is not a manager"<<endl;
          for(itr = myMap.begin(); itr != myMap.end(); itr++){
              if (itr->second == emp1)
                {
                    new_emp1 = itr->first;
                    string new_emp1 = itr->first;
                    cout <<endl<<"revised value of emp1 is "<< emp1<<endl;
                    break;
                }
          }
      }
    else {
        new_emp1 = emp1;
        
    }
   //if employee 2 isn't a manager then initialize employee's manager to be employee of conflict (new_emp2) // else emp2 remains the employee of conflict.
  
    if (itr2 == myMap.end())
      {
        //  "emp2 is not a manager"//
          for(itr2 = myMap.begin(); itr2 != myMap.end(); itr2++){
                 if (itr2->second == emp2){
                     new_emp2 = itr2->first;
                     cout <<endl<<"revised value of emp2 is "<< emp2<<endl;
                     break;
                 }
                   }
      }
    else{
        new_emp2 = emp2;
        
    }
       // At this point, both employees in conflict are identified/initialized  to also be managers. check relationship between both managers new_emp1 and new_emp2 . Break if a common manager is found.
    
        string temps;
            while(1){
            cout <<"starting value of emp1" << emp1<<endl;
            cout<<"starting value of emp2" <<emp2<<endl;
        for (itr = myMap.begin(); itr !=myMap.end(); itr++){
        if ((itr->first == new_emp1)&&(itr->second == new_emp2))
        {
            cout<<"emp1 manages emp2 and emp1 could be the lcm"<<endl;
            temps = new_emp1;
        }
            if ((itr->first == new_emp2)&&(itr->second == new_emp1))
                   {
                       cout <<"what is employee 1 "<< emp1<<endl;
                       cout <<"what is employee 2 "<< emp2<<endl;
                       cout<<"emp2 manages emp1 and emp2 could be the lcm"<<endl;
                       temps = new_emp2;
        }
        }
      // break if temps hold a value which means a possible lowest common manager has been found, else continue by initailizing the new_emp1's manager as new_emp1 and new_emp2's manager as new_emp2
        if ((temps == new_emp1)||(temps == new_emp2))
        {
            break;
            
        }
        else{
            for (it = myMap.begin(); it !=myMap.end(); it++){
            if ((it->second == new_emp1))
            {
                new_emp1 = it->first;
              break;
            }
            if ((it->second == new_emp2))
                       {
                           new_emp2 = it->first;
                          break;
                       }
        }
        }
        }
    // code executes after temps has a value, check to make sure temps isn't an employee of conflict(emp_1 or emp_2)//
    if ((temps == emp1)||(temps == emp2)){
        for(itr = myMap.begin(); itr != myMap.end(); itr++){
                  if(itr->second == temps){
                      temps = itr->first;
                  }
              }
              cout <<"The common manager is "<<temps;
          }
    
else {
    cout << "The common manager is" << temps;
    
}
      
       return 0;
    }
   
  



    

