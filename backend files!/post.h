//Mary Iwuoha, 10/21/25, my post header file!
#ifndef POST_H
#define POST_H

#include <iostream>
#include <string>

class Post{
private:
	int messageId_;
	int profileId_;
	int authorId_;
	std::string message_;
	int likes_;

public:
	Post();
	Post(int profileId, int authorId, std::string message, int likes);
	int getMessageId();
	void setMessageId(int id);
	int getProfileId();
	int getAuthorId();
	std::string getMessage();
	int getLikes();
	void addLikes(int i);
	virtual std::string getURL();
	virtual std::string toString();
};

class LinkPost: public Post{
private:
	std::string url_;

public:
	LinkPost();
	LinkPost(int profileId, int authorId, std::string message, int likes, std::string url);
	std::string getURL();
	std::string toString();
};

#endif