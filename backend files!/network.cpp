//Mary Iwuoha, 9/26/25, network cpp file!
#include "network.h"
#include "user.h"
#include <sstream>
#include <fstream>
#include <set>
#include <vector>
#include <queue>
#include <stack>

//pre: none
//post: empty network created
Network::Network(){
	users_ = std::vector<User*>();
	numMessage = 0;
}

//pre: a user exists in the network
//post: a user is found
User* Network::getUser(int id){
	User*p = nullptr;
	for(User* u : users_){
		if(u->getId()==id){
			p = u;
		}
	}

	return p;
}

//pre: none
//post: a user is added to the network
void Network::addUser(User* u){
	users_.push_back(u);
	std::vector<Post*>p;
	posts_.push_back(p);
}

//pre: two users exist in the network
//post: a connection is created between the users
int Network::addConnection(std::string s1, std::string s2){
	bool found1 = false;
	bool found2 = false;
	int id1;
	int id2;
	

	for(User* u : users_){
		if(u->getName()==s1){
			found1 = true;
			id1 = u->getId();
		}
		if(u->getName()==s2){
			found2 = true;
			id2 = u->getId();
		}
	}

	if(found1 == false || found2 == false) {return -1;}

	else {
		for(int i = 0; i<users_.size(); i++){
			if(users_[i]->getName() == s1){
				users_[i]->addFriend(id2);
			}
			if(users_[i]->getName() == s2){
				users_[i]->addFriend(id1);
			}

		}
	}

	return 0;

}
//pre: two users exist in the network
//post: a connection is deleted between the users
int Network::deleteConnection(std::string s1, std::string s2){
	bool found1 = false;
	bool found2 = false;
	int id1;
	int id2;
	

	for(User* u : users_){
		if(u->getName()==s1){
			found1 = true;
			id1 = u->getId();
		}
		if(u->getName()==s2){
			found2 = true;
			id2 = u->getId();
		}
	}

	if(found1 == false || found2 == false) {return -1;}

	else {
		for(int i = 0; i<users_.size(); i++){
			if(users_[i]->getName() == s1){
				users_[i]->deleteFriend(id2);
			}
			if(users_[i]->getName() == s2){
				users_[i]->deleteFriend(id1);
			}

		}
	}

	return 0;

}

//pre: none
//post: the ID of a user is returned
int Network::getId(std::string name){
	for(User* u : users_){
		if(u->getName()==name){
			return u->getId();
		}
	}

	return -1;

}

//pre: none
//post: returns the size/# of users in the network
int Network::numUsers(){
	return users_.size();

}

//pre: a txt file exists
//post: reads the users in a file and adds them to the network
//fix the ordering of the inserts and make sure you get the tab at the beginning
void Network::readUsers(const char* fname){

	std::ifstream marysfile(fname);
	int numUsers;
	marysfile>>numUsers;

	for(int i = 0; i<numUsers; i++){
		int id3;
		marysfile>>id3;

		marysfile.ignore();

		std::string n;
		getline(marysfile, n);
		if(n[0]== '\t'){
			n.erase(0,1);
		}

		int y;
		marysfile>>y;

		int z;
		marysfile>>z;

		marysfile.ignore();

		std::string listFriends;
		getline(marysfile, listFriends);
		if(listFriends[0]== '\t'){
			listFriends.erase(0,1);
		}
		std::stringstream ss(listFriends);

		int friendsIDS;
		std::set<int> f;

		while(ss>>friendsIDS){
			f.insert(friendsIDS);
		}

		User* u = new User(id3, n, y, z, f);
		addUser(u);

	}

	marysfile.close();

}

//pre: a txt file exists
//post: writes the new users from the network to the file
void Network::writeUsers(const char* fname){
	std::ofstream fout(fname);
	fout<<numUsers()<<std::endl;

	for(int i = 0; i<users_.size(); i++){
		fout<<i<<std::endl;
		fout<<'\t'<<users_[i]->getName()<<std::endl;
		fout<<'\t'<<users_[i]->getYear()<<std::endl;
		fout<<'\t'<<users_[i]->getZip()<<std::endl;
		fout<<'\t';
		for(int x : users_[i]->getFriends()){
			fout<<x<<" ";
		}

		fout<<std::endl;

	}

	fout.close();

}

//pre: have a from user and to user
//post: returns a vector of the shortest path between the users
std::vector<int> Network::shortestPath(int from, int to){
	std::queue<int> q;
	std::vector<bool>visited(users_.size(), 0);
	std::vector<int>prev(users_.size(), -1);

	visited[from] = true;
	q.push(from);

	while(q.size()>0){
		int current = q.front();
		q.pop();

		for(int neighbor : users_[current]->getFriends()){
			if(!visited[neighbor]){
				prev[neighbor] = current;
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}

	std::vector<int>output;
	int current = to;

	if(visited[current]==false){
		return output;
	}

	while (current!= -1){
		output.push_back(current);
		current = prev[current];
	}

	reverse(output.begin(), output.end());
	return output;

}


//pre: have a from user and a given distance
//post: finds the user id, assign to 'to' and returns a vector of the shortest path between the users
std::vector<int> Network::distanceUser(int from, int& to, int distance){
	int count = 0;
	std::queue<int> q;
	std::vector<bool>visited(users_.size(), false);

	visited[from] = true;
	q.push(from);

	while(q.size()>0){
		int s = q.size();

		if(count == distance){
			to = q.front();
			return shortestPath(from, to);
		}

		for(int i = 0; i<s; i++){
			int current = q.front();
			q.pop();

			for(int neighbor : users_[current]->getFriends()){
				if(!visited[neighbor]){
					visited[neighbor] = true;
					q.push(neighbor);
				}
			}
		}
		count++;
	}

	return shortestPath(from, to);
}


//pre: user exists
//post: set score (# of mutual friends) to the highest score found, returns vector of friend suggestions
std::vector<int> Network::suggestFriends(int who, int& score){
	score = 0;
	std::queue<int>q;
	std::vector<bool>visited(users_.size(),0);
	std::vector<int>distance(users_.size(),-1);

	q.push(who);
	visited[who]= true;
	distance[who]= 0;

	while(q.size()>0){
		int current = q.front();
		q.pop();
		for(int neighbor : users_[current]->getFriends()){
			if(visited[neighbor]==false){
				visited[neighbor] = true;
				distance[neighbor] = distance[current]+1;
				q.push(neighbor);
			}
		}
	}

	std::vector<int>suggestions;
	for(int i = 0; i<users_.size(); i++){
		if(distance[i]==2){
			suggestions.push_back(i);
			score+=1;
		}
	}

	return suggestions;
	
}


//pre: a connected component exists (like there are people in the network and they are connected)
//post: return a list of lists of users in the connected component
std::vector<std::vector<int>> Network::groups(){
	std::vector<std::vector<int>>group;
	std::vector<bool>visited(users_.size(), 0);

    for(int i = 0; i<users_.size(); i++){
		if(visited[i]==false){
			std::stack<int>s;
			std::vector<int>g;
			visited[i] = true;
			s.push(i);

			while(s.size()>0){
				int current = s.top();
				s.pop();
				g.push_back(current);

				for(int neighbor : users_[current]->getFriends()){
					if(!visited[neighbor]){
						visited[neighbor] = true;
						s.push(neighbor);
					}
				}
	
			}
			group.push_back(g);
		}

	}
	return group;
}

//pre: a post object has been created
//post: a post is added to the network (vector of posts)
void Network::addPost(Post* post){
	post->setMessageId(numMessage++);
	int id1 = post->getProfileId();
	posts_[id1].push_back(post);
}

//pre: a user with an id exists
//post: a vector is returned with all posts in the network
std::vector<Post*> Network::getPosts(int id){
	return posts_[id];
}


//pre: a post object has been created 
//post: returns a string that represents a post 
std::string Network::postDisplayString(Post* post){
	User* p = getUser(post->getAuthorId());
	return p->getName() + " wrote: " + post->toString();
}


//pre: profile id exists and how many count is given
//post: returns the posts up to howMany
std::string Network::getPostsString(int profileId, int howMany){
	int count = 0;
	std::string str;
	std::stack<Post*>s;

	for(Post* p : posts_[profileId]){
		s.push(p);
	}

	while(s.size()>0 && count<howMany){
		str += postDisplayString(s.top()) + "\n\n";
		s.pop();
		count++;
	}

	return str;
}

//pre: profile id exists and how many count is given
//post: returns the posts up to howMany
std::string Network::getPostsString2(int profileId, int howMany){
    int count = 0;
    std::string str;
    std::vector<Post*>po;

    po = posts_[profileId];

    std::sort(po.begin(), po.end(), [] (Post* a, Post* b){
        return a->getLikes() > b->getLikes();
    });

    std::queue<Post*>q;
    for(Post* p : po){
        q.push(p);
    }


    while(q.size()>0 && count<howMany){
        str += postDisplayString(q.front()) + "\n\n";
        q.pop();
        count++;
    }

    return str;
}

//pre: a file name is given
//post: reads posts from the file
int Network::readPosts(const char* fname){
	std::ifstream marysfile2(fname);

	if(!marysfile2.is_open()){return -1;}

	int numPosts;
	marysfile2>>numPosts;
	for(int i = 0; i<numPosts; i++){
		int msgid;
		marysfile2>>msgid;

		marysfile2.ignore();
		std::string msg;
		getline(marysfile2, msg);
		if(msg[0]== '\t'){
			msg.erase(0,1);
		}


		int pid;
		marysfile2>>pid;

		int aid;
		marysfile2>>aid;

		int l;
		marysfile2>>l;

		marysfile2.ignore();
		std::string url;
		getline(marysfile2, url);
		if(url[0]== '\t'){
			url.erase(0,1);
		}


		Post* p;

		if(url.empty()){
			p = new Post(pid,aid,msg,l);
		}
		else{
			p = new LinkPost(pid,aid,msg,l, url);
		}
		addPost(p);

	}

	numMessage=numPosts;
	marysfile2.close();
	return 0;
}

//pre: a file name is given
//post: writes posts into a file
int Network::writePosts(const char* fname){
	std::ofstream fout2(fname);

	if(!fout2.is_open()){return -1;}

	fout2<<numMessage<<std::endl;
	std::vector<Post*>totalPosts;

	for(int i = 0; i<posts_.size(); i++){
		for(int j = 0; j<posts_[i].size(); j++){
			totalPosts.push_back(posts_[i][j]);
		}
	}
	std::sort(totalPosts.begin(),totalPosts.end(), [] (Post* a, Post* b){
		return a->getMessageId() < b->getMessageId();
	});

	for(Post*p : totalPosts){
		fout2<<p->getMessageId()<<std::endl;
		fout2<<'\t'<<p->getMessage()<<std::endl;
		fout2<<'\t'<<p->getProfileId()<<std::endl;
		fout2<<'\t'<<p->getAuthorId()<<std::endl;
		fout2<<'\t'<<p->getLikes()<<std::endl;
		fout2<<'\t'<<p->getURL()<<std::endl;
	}

	fout2.close();
	return 0;

}

