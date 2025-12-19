//Mary Iwuoha, 9/26/25, my user.cpp file
#include "user.h"
#include <set>

//pre: none
//post: a new empty user is created
User::User(){
	id_=year_=zip_=0;
	friends_ = std::set<int>();
}

//pre: none
//post: a new user with 5 attributes is allocated
User::User(int id, std::string name, int year, int zip, std::set<int>friends){
	id_=id;
	name_=name;
	year_=year;
	zip_=zip;
	friends_=friends;
}
//pre: none
//post: the user's id is returned
int User::getId(){
	return id_;
}

//pre: none
//post: returns the user's name
std::string User::getName(){
	return name_;
}

//pre: none
//post: returns the user's birth year
int User::getYear(){
	return year_;
}

//pre: none
//post: returns the user's zip code
int User::getZip(){
	return zip_;
}

//pre: none
//post returns a list of the user's friends
std::set<int>& User::getFriends(){
	return friends_;
}

//pre: a list of friends has been allocated
//post: a new friend is added to the user
void User::addFriend(int id){
	for(int i : friends_){
		if(i==id){return;}
	}
	friends_.insert(id);
}

//pre: a list of friends has been allocated
//post: a friend is deleted from the user
void User::deleteFriend(int id){
	bool found = false;
	for(int i : friends_){
		if(i==id){
			found = true;
		}
	}
	friends_.erase(id);
	if(found == false){
		return;
	}
}

//pre: none
//post: returns # of points
int User::getPoints(){
	return points;
}

//pre: none
//post: sets/resets point count
void User::setPoints(int p){
	points = p;
}

//pre: none
//post: adds p to points
void User::addPoints(int p){
	points+=p;
}

//pre: none
//post: deletes points if theres enough to delete
int User::deletePoints(int p){
	if(points-p<0){
		return 0;
	}
	else{
		points-=p;
		return 1;
	}
}


