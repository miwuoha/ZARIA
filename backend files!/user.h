//Mary Iwuoha, 9/26/25, my user header file!
#ifndef USER_H
#define USER_H

#include <set>

class User{
private: 
	int id_;
	std::string name_;
	int year_;
	int zip_;
	std::set<int>friends_;
	int points;

public:
	User();
	User(int id, std::string name, int year, int zip, std::set<int>friends_);
	int getId();
	std::string getName();
	int getYear();
	int getZip();
	std::set<int>& getFriends();
	void addFriend(int id);
	void deleteFriend(int id);
	int getPoints();
    void setPoints(int p);
	void addPoints(int p);
	int deletePoints(int p);


};

#endif
