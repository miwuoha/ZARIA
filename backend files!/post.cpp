//Mary Iwuoha, 10/21/25, my post.cpp file!
#include "post.h"

//my implmentations for the post class!! :)

//pre: none
//post: creates new empty post
Post::Post(){
	profileId_= authorId_= likes_= 0;
	messageId_= -1;
	message_ = "";
}

//pre: none 
//post: creates new post with specified paramenters
Post::Post(int profileId, int authorId, std::string message, int likes){
	profileId_= profileId;
	authorId_= authorId;
	message_= message;
	messageId_ = -1;
	likes_= likes;
}

//pre: none
//post: gets message id
int Post::getMessageId(){
	return messageId_;
}

//pre: none 
//post: sets message id
void Post::setMessageId(int id){
	messageId_ = id;
}

//pre: none 
//post: gets profile id
int Post::getProfileId(){
	return profileId_;
}

//pre: none
//post: gets author id 
int Post::getAuthorId(){
	return authorId_;
}

//pre: none 
//post: gets the message
std::string Post::getMessage(){
	return message_;
}

//pre: none 
//post: gets # of likes
int Post::getLikes(){
	return likes_;
}

//pre: none
//post: # of likes is added
void Post::addLikes(int i){
	likes_+=i;
}

//pre: none
//post: returns empty string (URL)
std::string Post::getURL(){
	return "";
}


//pre: none
//post: returns a string with message and its # of likes
std::string Post::toString(){
	std::string l = std::to_string(likes_);
	return message_ + " (" + l + " likes)";
}


//my implementations for the linkPost class!! hehe :)

//pre: none
//post: creates an empty linkPost object 
LinkPost::LinkPost() : Post(){
	url_ = "";
}

//pre: none
//post: creates new Linkpost with specified paramenters
LinkPost::LinkPost(int profileId, int authorId, std::string message, int likes, std::string url) : Post(profileId, authorId, message, likes){
	url_= url;
}

//pre: none
//post: returns url
std::string LinkPost::getURL(){
	return url_;
}

//pre: none
//post: returns a string with a message, url, and # of likes
std::string LinkPost::toString(){
	std::string k = std::to_string(getLikes());
	return getMessage() + " (url: " + url_ + ")" + " (" + k + " likes)";
}

