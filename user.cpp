#include "user.h"


//Constructor and Deconstructor
User::User() : friendList(100){ //Initializing data members (friendList) before the body of the constructor executes
};
User::User(std::vector<User*> friendList) : friendList(friendList){ //Constructor for new Users with preexisting friendList
};

//Setters and Getters
void User::setUserName(std::string userName){
    this->userName =userName;
}

void User::setEmail(std::string username){
    this->email = email;
}

std::string User::getUserName(){
    return userName;
}

std::string User::getEmail(){
    return email;
}

//Functions
void User::addFriend(User* newFriend) {
    friendList.push_back(newFriend);
}

void User::removeFriend(std::string userName){
    for(auto it = friendList.begin(); it != friendList.end(); ++it) { //iterate through friendList 
        if ((*it)-> getUserName() == userName){
            friendList.erase(it);
            break; //Exit loop on User removal
        }
    }
}

int User::numFriend(){
    return friendList.size();
}

User* User::getFriendAt(int index){
    if(index >= 0 && index < friendList.size() && friendList[index] != nullptr){ //access user pointer at int index 
        return friendList[index];
    }
}