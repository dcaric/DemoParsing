//
//  main.cpp
//  DemoParsing
//
//  Created by Dario Caric on 20.05.2024..
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/**
 Evo fajle slicne onojnod jucer pa provaj napravit pro koji parsira, sprema u vektor i onda
 1) nadji max za valu1
 2) min za value2
 3) spremi u novu fajlu ali tako da svaki podatak bude odvojen sa ; i tako da ima samo 1 value koji je value=value1 + value2 - value3

 Takodjer na dnu fajle dodaj grad za koji je taj novi value MAX
 */

//2 Los Angeles,2019:12:22;33
//2 Los Angeles,2019::22;33
//2 Los Angeles,2019


struct Data {
  
    int index;
    string city;
    int year;
    int val1, val2,val3;
    
};




int main() {
    
    ifstream file ("/Users/dcaric/Library/Mobile Documents/com~apple~CloudDocs/MYPROJECTS/C++/DemoParsing/data.txt");
    
    if (!file) {
        cout << "file cannot open" << endl;
        return 1;
    }
    
    
    string line;
    getline(file,line);  //header
    vector <Data> v;
    
    
    while ( getline(file,line)){
        
        stringstream ss;
        ss << line;
        
        
        Data tempData;
        
        string tempIndex;
        getline(ss, tempIndex,' ');
        tempData.index = stoi(tempIndex);
        
    
        getline(ss, tempData.city,',');
        
        string tempYear;
        getline(ss, tempYear,':');
        tempData.year = stoi(tempYear);
        
 
        
        //val 1
        string tempVal1;
        getline(ss, tempVal1,':');
        if(tempVal1 == "" ){
            tempData.val1 = 0;
            
        }else if (tempVal1 == "\n"){
            tempData.val1 = 0;
            tempData.val2 = 0;
            tempData.val3 = 0;
        }else tempData.val1 = stoi(tempVal1);
        
        
        //val2
        string tempVal2;
        getline(ss, tempVal2,';');
        if(tempVal2 == "" ){
            tempData.val2 = 0;
        }else if (tempVal2 == "\n"){
            tempData.val2 = 0;
            tempData.val3 = 0;
        }else tempData.val2 = stoi(tempVal2);
        
        
        
        //val3
        string tempVal3;
        getline(ss, tempVal3);
        if(tempVal3 == "" || tempVal3 == "\n"){
            tempData.val3 = 0;
            
        }else tempData.val3 = stoi(tempVal3);
        
        
        v.push_back(tempData);
        
        
        
        
        
        
    }
    
    
    
    
    
    

    return 0;
}
