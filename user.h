#ifndef USER_H
#define USER_H

#include<iostream>
#include<string.h>
#include<vector>

class User {
    private:
        std::string userName;
        std::string email;
        std::vector<User*> friendList;
        
    public:
        //Constructor and Deconstructor
        User::User(); //Creates an empty User object with empty friendList of 100
        User::User(std::vector<User*> friendList); //Creates 
        User::~User();

        //Setters and Getters for UserName and Email
        void User::setUserName(std::string userName);

        void User::setEmail(std::string username);

        std::string User::getUserName();

        std::string User::getEmail();

        //Class Functions
        void User::addFriend(User*); //take a User pointer and add to friendList

        void User::removeFriend(std::string userName); //take username as string and remove from friendList
        
        int User::numFriend(); //return number of friends in friendList
        
        User* User::getFriendAt(int index); //return user pointer when given an index position
};

#endif