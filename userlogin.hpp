#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class UserLogin {
private:
    
    unordered_map< string, string > table;
    

public:
    UserLogin(); // default constructor

    void readIn(const string& filename); // add data from file to hash table

    size_t numberOfUsers(); // return the number of users

    string passWordCheck(const string& userName); // returns the passWord of the given user

    size_t wordBucketIdMethod1(const string& userName); // return the bucket number where the given user is located

    size_t wordBucketIdMethod2(const string& userName); // another way to find the bucket number where the given user is located

    bool validateUser(const string& userName); // look up given user

    bool authenticateUser(const string& userName, const string& passWord);// authenticate given user and password
       
};

UserLogin::UserLogin() {
}

// COMPLETE THE FOLLOWING FUNCTIONS

void UserLogin::readIn(const string& filename) {
    
    //varaibles
    string userName;
    string passWord;

    //going to open file
    ifstream myFile(filename);
    //myFile.open(filename);
    if (myFile.is_open()) {
        while (myFile >> userName >> passWord) {
            table.insert(pair<string, string>(userName, passWord));
        }
        myFile.close();
    }
}

size_t UserLogin::numberOfUsers() {
    //WORKSs 
    return table.size();
    
}

string UserLogin::passWordCheck(const string& userName) {

    //  WORKS
    unordered_map<string, string>::iterator search = table.find(userName);
    if (search == table.end()) {
        return "Non-existent User";
    }
    else {
        return search->second;
    }
}

size_t UserLogin::wordBucketIdMethod1(const string& userName) {

    //WORKS
    return table.bucket(userName);

}

size_t UserLogin::wordBucketIdMethod2(const string& userName) {

    //PARTICAL WORKS------------------------------
     /*size_t count = 0;
    for (auto& i : userName) {
        count++;
   }
    return count;*/

    // WORKS but idk if allowed
    if (table.count(userName) != 0) { //if found
        return table.bucket(userName);
    }

     
}

bool UserLogin::validateUser(const string& userName) {
    
    // WORKS
    if (table.find(userName) == table.end()) {
        return false; //can find
    }
    else {
        return true; //not found user
    }
     
}

bool UserLogin::authenticateUser(const string& userName, const string& passWord) { 
    //WORKS

     string pword = table[userName];//the password with the username
    for (auto& x : table) {//go through table
        if (x.second == pword && x.first==userName) { //pass and user match
            return true;
        }
        else if(table.find(userName) == table.end()) { //if exists 
            return false; 
        }
        else {
            return false;
        }
    }
    /*   another way
    unordered_map<string, string>::iterator search = table.find(userName);

    if (search == table.end()) {
        return false;
    }
    else if (userName == search->first && passWord == search->second)
        return true;
    else
        return false;
 }*/
 }

