//Mary Iwuoha, 9/26/25, network header file :)

#ifndef NETWORK_H
#define NETWORK_H

#include "user.h"
#include "post.h"

class Network{
private:
	std::vector<User*> users_;
	std::vector<std::vector<Post*>>posts_;
	int numMessage;

public:
	Network();
	User* getUser(int id);
	void addUser(User* u);
	int addConnection(std::string s1, std::string s2);
	int deleteConnection(std::string s1, std::string s2);
	int getId(std::string name);
	int numUsers();
	void readUsers(const char* fname);
	void writeUsers(const char* fname);
	std::vector<int>shortestPath(int from, int to);
	std::vector<int>distanceUser(int from, int& to, int distance);
	std::vector<int>suggestFriends(int who, int&score);
	std::vector<std::vector<int>>groups();

	//post-related functions
	void addPost(Post* post);
	std::vector<Post*> getPosts(int id);
	std::string postDisplayString(Post* post);
	std::string getPostsString(int profileId, int howMany);
    std::string getPostsString2(int profileId, int howMany);
    int readPosts(const char* fname);
    int writePosts(const char* fname);


};
#endif

