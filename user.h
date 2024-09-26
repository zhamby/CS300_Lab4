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
        //Setters and Getters for UserName and Email
        void setUserName(std::string userName);

        void setEmail(std::string username);

        std::string getUserName();

        std::string getEmail();

        void addFriend(User*); //take a user pointer and add to friendList

        void removeFriend(std::string userName); //take username as string and remove from friendList
        
        int numFriend(); //return number of friends in friendList
        
        User* getFriendAt(int index); //return user pointer when given an index position
};

#endif