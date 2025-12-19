#include "socialnetworkwindow.h"
#include "ui_socialnetworkwindow.h"

SocialNetworkWindow::SocialNetworkWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SocialNetworkWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #F7CAD0;");

    connect(ui->loginButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::loginButtonClick);

    connect(ui->backButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::backButtonClick);

    connect(ui->backButton2,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::backButtonClick);

    connect(ui->addFriendButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::addFriendClick);

    connect(ui->postButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::addPostsClick);

    connect(ui->friendList,
            &QTableWidget::itemClicked,
            this,
            &SocialNetworkWindow::tableClick);

    connect(ui->friendSuggestions,
            &QTableWidget::itemClicked,
            this,
            &SocialNetworkWindow::tableClick);

    connect(ui->accountButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::accountDisplay);

    connect(ui->accountButton2,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::createAccount);

    connect(ui->backLoginButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::loginDisplay);

    connect(ui->logOut,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::loginDisplay);

    connect(ui->storeButton,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::storeDisplay);

    connect(ui->buyButton1,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::buyButton1Click);

    connect(ui->buyButton2,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::buyButton2Click);

    connect(ui->buyButton3,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::buyButton3Click);

    connect(ui->buyButton4,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::buyButton4Click);

    connect(ui->buyButton5,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::buyButton5Click);

    connect(ui->buyButton6,
            &QPushButton::clicked,
            this,
            &SocialNetworkWindow::buyButton6Click);

    ui->errorLabel->hide();
    ui->backButton2->hide();
    ui->iPadLabel->hide();
    ui->macLabel->hide();
    ui->pufferLabel->hide();
    ui->backpackLabel->hide();
    ui->hoodieLabel->hide();
    ui->owalaLabel->hide();
    ui->buyButton1->hide();
    ui->buyButton2->hide();
    ui->buyButton3->hide();
    ui->buyButton4->hide();
    ui->buyButton5->hide();
    ui->buyButton6->hide();
    ui->storeLabel->hide();
    ui->pointCount->hide();
    ui->networkLabel2->hide();
    ui->postsTable->hide();
    ui->postLabel2->hide();
    ui->postsLabel->hide();
    ui->failLabel->hide();
    ui->addFriendButton->hide();
    ui->profileLabel->hide();
    ui->backButton->hide();
    ui->friendList->hide();
    ui->friendSuggestions->hide();
    ui->postInput->hide();
    ui->postButton->hide();
    ui->makeapostlabel->hide();
    ui->postLabel->hide();
    ui->friendsLabel->hide();
    ui->friendSuggestionsLabel->hide();
    ui->accountButton2->hide();
    ui->backLoginButton->hide();
    ui->zipInput->hide();
    ui->zipLabel->hide();
    ui->yearInput->hide();
    ui->yearLabel->hide();
    ui->sucessLabel->hide();
    ui->logOut->hide();
    ui->storeButton->hide();

    ui->nameInput->setStyleSheet("background-color: #FF85A1;");
    ui->zipInput->setStyleSheet("background-color: #FF85A1;");
    ui->yearInput->setStyleSheet("background-color: #FF85A1;");
    ui->backButton2->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->loginButton->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->backLoginButton->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->accountButton->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->accountButton2->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->logOut->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->loginLabel->setStyleSheet("color: #FF85A1");
    ui->errorLabel->setStyleSheet("color: #FF85A1");
    ui->zipLabel->setStyleSheet("color: #FF85A1");
    ui->yearLabel->setStyleSheet("color: #FF85A1");
    ui->networkLabel->setStyleSheet("color: #DE3163");
    ui->networkLabel2->setStyleSheet("color: #DE3163");
    ui->postsTable->setStyleSheet("background-color: #FF85A1;");
    ui->postLabel2->setStyleSheet("color: #FF85A1");

    ui->backButton->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->buyButton1->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->buyButton2->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->buyButton3->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->buyButton4->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->buyButton5->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->buyButton6->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->postButton->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->storeButton->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->addFriendButton->setStyleSheet("color: white; background-color: #FF85A1;");
    ui->makeapostlabel->setStyleSheet("color: #FF85A1");
    ui->postLabel->setStyleSheet("color: #FF85A1");
    ui->postsLabel->setStyleSheet("color: #A3003F");
    ui->friendsLabel->setStyleSheet("color: #FF85A1");
    ui->friendSuggestionsLabel->setStyleSheet("color: #FF85A1");
    ui->postInput->setStyleSheet("background-color: #FF85A1;");
    ui->friendList->setStyleSheet("background-color: #FF85A1;");
    ui->friendSuggestions->setStyleSheet("background-color: #FF85A1;");



    n.readUsers("users.txt");
    n.readPosts("posts.txt");
}

SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

//pre: user is logged in
//post: generates a table of friends
void SocialNetworkWindow::friendTable(){
    std::set<int>friends = profile->getFriends();
    ui->friendList->setRowCount(friends.size());
    ui->friendList->setColumnCount(1);
    ui->friendList->setColumnWidth(0,341);

    int count = 0;
    for(int i : friends){
        User* u = n.getUser(i);
        QTableWidgetItem* person = new QTableWidgetItem(QString::fromStdString(u->getName()));
        ui->friendList->setItem(count,0,person);
        count++;
    }
}

//pre: user is logged in
//post: generates a table of posts
void SocialNetworkWindow::postTable(){
    std::vector<Post*>yay = n.getPosts(profile->getId());
    ui->postsTable->setRowCount(yay.size());
    ui->postsTable->setColumnCount(1);
    ui->postsTable->setColumnWidth(0,341);

    for(int i = 0; i<yay.size(); i++){
        QTableWidgetItem* pos = new QTableWidgetItem(QString::fromStdString(yay[i]->toString()));
        ui->postsTable->setItem(i,0,pos);
    }
    connect(ui->postsTable,
            &QTableWidget::itemClicked,
            this,
            &SocialNetworkWindow::likeButtonClick);
}

//pre: none, post exists maybe
//post: points added, post is liked!
void SocialNetworkWindow::likeButtonClick(QTableWidgetItem* item){
    int r = item->row();
    std::vector<Post*>yay = n.getPosts(profile->getId());
    yay[r]->addLikes(1);
    item->setText(QString("🩷 ") + item->text());
    you->addPoints(10);
    n.writeUsers("users.txt");
}

//pre: user is logged in
//post: shows a table of friend suggestions!
void SocialNetworkWindow::friendSuggestionsTable(){
    int score = 0;
    std::vector<int>f = n.suggestFriends(you->getId(), score);
    ui->friendSuggestions->setRowCount(f.size());
    ui->friendSuggestions->setColumnCount(1);
    ui->friendSuggestions->setColumnWidth(0,341);

    int count = 0;
    for(int i : f){
        User* u = n.getUser(i);
        QTableWidgetItem* person = new QTableWidgetItem(QString::fromStdString(u->getName()));
        ui->friendSuggestions->setItem(count,0,person);
        count++;
    }

}

//pre: none
//post: friend connection is created & users.txt file is updated
void SocialNetworkWindow::addFriendClick(){
    n.addConnection(you->getName(), profile->getName());
    you->addPoints(15);
    n.writeUsers("users.txt");
}

//pre: none
//post: post is added & posts.txt file is updated
void SocialNetworkWindow::addPostsClick(){
    std::string m = ui->postInput->toPlainText().toStdString();
    Post* p = new Post(profile->getId(),you->getId(), m, 0);
    n.addPost(p);
    you->addPoints(20);
    n.writePosts("posts.txt");
    n.writeUsers("users.txt");

}


//pre: posts exist
//post: most popular posts are shown on the profile pages
void SocialNetworkWindow::showPosts(){
    ui->postsLabel->setText(QString::fromStdString(n.getPostsString2(profile->getId(),5)));
    ui->postsLabel->setWordWrap(true);
}


//pre: you're logged in
//post: shows original profile window
void SocialNetworkWindow::maindisplay(){
    ui->loginLabel->hide();
    ui->errorLabel->hide();
    ui->failLabel->hide();
    ui->backButton2->hide();
    ui->iPadLabel->hide();
    ui->macLabel->hide();
    ui->pufferLabel->hide();
    ui->backpackLabel->hide();
    ui->hoodieLabel->hide();
    ui->owalaLabel->hide();
    ui->buyButton1->hide();
    ui->buyButton2->hide();
    ui->buyButton3->hide();
    ui->buyButton4->hide();
    ui->buyButton5->hide();
    ui->buyButton6->hide();
    ui->storeLabel->hide();
    ui->pointCount->hide();
    ui->nameInput->hide();
    ui->accountButton->hide();
    ui->networkLabel->hide();
    ui->networkLabel2->show();
    ui->loginButton->hide();
    ui->postsTable->hide();
    ui->postLabel2->hide();
    ui->errorLabel->hide();
    ui->postsLabel->show();
    ui->profileLabel->show();
    ui->backButton->hide();
    ui->friendList->show();
    ui->friendSuggestions->show();
    ui->addFriendButton->hide();
    ui->postInput->show();
    ui->postButton->show();
    ui->makeapostlabel->show();
    ui->logOut->show();
    ui->postLabel->show();
    ui->storeButton->show();
    ui->friendsLabel->show();
    ui->friendSuggestionsLabel->show();
    ui->profileLabel->setText(QString::fromStdString("Hi, " + profile->getName() + "!"));
}

//pre: none
//post: this is what is called when you click create an account on login page
void SocialNetworkWindow::accountDisplay(){
    ui->accountButton2->show();
    ui->backLoginButton->show();
    ui->zipInput->show();
    ui->zipLabel->show();
    ui->yearInput->show();
    ui->yearLabel->show();
    ui->nameInput->show();
    ui->networkLabel->show();
    ui->loginButton->hide();
    ui->accountButton->hide();
    ui->errorLabel->hide();
}

//pre: none
//post: displays the login page
void SocialNetworkWindow::loginDisplay(){
    ui->loginButton->show();
    ui->accountButton->show();
    ui->loginLabel->show();
    ui->nameInput->show();
    ui->networkLabel->show();
    ui->errorLabel->hide();
    ui->accountButton->show();
    ui->storeButton->hide();
    ui->accountButton2->hide();
    ui->backLoginButton->hide();
    ui->zipInput->hide();
    ui->zipLabel->hide();
    ui->yearInput->hide();
    ui->yearLabel->hide();
    ui->sucessLabel->hide();
    ui->postLabel->hide();
    ui->friendsLabel->hide();
    ui->friendSuggestionsLabel->hide();
    ui->networkLabel2->hide();
    ui->postInput->hide();
    ui->postButton->hide();
    ui->makeapostlabel->hide();
    ui->logOut->hide();
    ui->postsLabel->hide();
    ui->profileLabel->hide();
    ui->friendList->hide();
    ui->friendSuggestions->hide();
}

//pre: you're logged in
//post: this is called when you click on another persons profile
void SocialNetworkWindow::otherProfileDisplay(){
    maindisplay();
    ui->backButton->show();
    ui->friendSuggestions->hide();
    ui->friendSuggestionsLabel->hide();
    ui->addFriendButton->show();
    ui->postsTable->show();
    ui->postLabel2->show();
    ui->logOut->hide();
    ui->storeButton->hide();
    ui->profileLabel->setText(QString::fromStdString(profile->getName() + "'s Profile"));
    friendTable();
    postTable();
    showPosts();

}

//pre: you're logged in
//post: this is called when you click on the store
void SocialNetworkWindow::storeDisplay(){
    ui->errorLabel->show();
    ui->iPadLabel->show();
    ui->macLabel->show();
    ui->pufferLabel->show();
    ui->backpackLabel->show();
    ui->hoodieLabel->show();
    ui->owalaLabel->show();
    ui->buyButton1->show();
    ui->buyButton2->show();
    ui->buyButton3->show();
    ui->buyButton4->show();
    ui->buyButton5->show();
    ui->buyButton6->show();
    ui->storeLabel->show();
    ui->pointCount->show();
    ui->pointCount->setText(QString::fromStdString("You have " + std::to_string(you->getPoints()) + " points."));
    ui->friendList->hide();
    ui->friendSuggestions->hide();
    ui->postInput->hide();
    ui->postButton->hide();
    ui->makeapostlabel->hide();
    ui->logOut->hide();
    ui->errorLabel->hide();
    ui->postLabel->hide();
    ui->postsLabel->hide();
    ui->storeButton->hide();
    ui->friendsLabel->hide();
    ui->friendSuggestionsLabel->hide();
    ui->backButton2->show();
}

void SocialNetworkWindow::createAccount(){
    std::string n1 = ui->nameInput->toPlainText().toStdString();
    int y = ui->yearInput->toPlainText().toInt();
    int z = ui->zipInput->toPlainText().toInt();

    User *u = new User(n.numUsers(), n1, y, z, std::set<int>());
    n.addUser(u);
    n.writeUsers("users.txt");

    ui->sucessLabel->show();
}


//pre: none (network initailized)
//post: button is clicked, user is either logged in or shown an error message
void SocialNetworkWindow::loginButtonClick(){
    std::string name = ui->nameInput->toPlainText().toStdString();
    if(n.getId(name)==-1){
        ui->errorLabel->show();
    }

    else{
        you = n.getUser(n.getId(name));
        profile = you;
        maindisplay();
        friendTable();
        friendSuggestionsTable();
        showPosts();

    }
}

//pre: your user has friends
//post: goes the user's profile page
void SocialNetworkWindow::tableClick(QTableWidgetItem* item){
    profile = n.getUser(n.getId(item->text().toStdString()));
    otherProfileDisplay();
}

//pre: you are on a different profile
//post: returns to the original display
void SocialNetworkWindow::backButtonClick(){
    profile = you;
    ui->profileLabel->setText(QString::fromStdString("Hi, " + profile->getName() + "!"));
    maindisplay();
    friendTable();
    friendSuggestionsTable();
    showPosts();

}

//pre: none
//post: the item is bought!!
void SocialNetworkWindow::buyButton1Click(){
    if(you->getPoints()-500<0){
        ui->failLabel->setText(QString::fromStdString("You do not have enough points to purchase this item."));
        ui->failLabel->show();
    }

    else{
        you->deletePoints(500);
        ui->failLabel->setText(QString::fromStdString("Yay, you have purchased this item. Enjoy!!!"));
        ui->failLabel->show();
        n.writeUsers("users.txt");
    }
}

//pre: none
//post: the item is bought!!
void SocialNetworkWindow::buyButton2Click(){
    if(you->getPoints()-25<0){
        ui->failLabel->setText(QString::fromStdString("You do not have enough points to purchase this item."));
        ui->failLabel->show();
    }

    else{
        you->deletePoints(25);
        ui->failLabel->setText(QString::fromStdString("Yay, you have purchased this item. Enjoy!!!"));
        ui->failLabel->show();
        n.writeUsers("users.txt");
    }
}

//pre: none
//post: the item is bought!!
void SocialNetworkWindow::buyButton3Click(){
    if(you->getPoints()-100<0){
        ui->failLabel->setText(QString::fromStdString("You do not have enough points to purchase this item."));
        ui->failLabel->show();
    }

    else{
    you->deletePoints(100);
    ui->failLabel->setText(QString::fromStdString("Yay, you have purchased this item. Enjoy!!!"));
    ui->failLabel->show();
    n.writeUsers("users.txt");
    }
}

//pre: none
//post: the item is bought!!
void SocialNetworkWindow::buyButton4Click(){
    if(you->getPoints()-50<0){
        ui->failLabel->setText(QString::fromStdString("You do not have enough points to purchase this item."));
        ui->failLabel->show();
    }

    else{
        you->deletePoints(50);
        ui->failLabel->setText(QString::fromStdString("Yay, you have purchased this item. Enjoy!!!"));
        ui->failLabel->show();
        n.writeUsers("users.txt");
    }
}

//pre: none
//post: the item is bought!!
void SocialNetworkWindow::buyButton5Click(){
    if(you->getPoints()-250<0){
        ui->failLabel->setText(QString::fromStdString("You do not have enough points to purchase this item."));
        ui->failLabel->show();
    }

    else{
        you->deletePoints(250);
        ui->failLabel->setText(QString::fromStdString("Yay, you have purchased this item. Enjoy!!!"));
        ui->failLabel->show();
        n.writeUsers("users.txt");
    }
}

//pre: none
//post: the item is bought!!
void SocialNetworkWindow::buyButton6Click(){
    if(you->getPoints()-1000<0){
         ui->failLabel->setText(QString::fromStdString("You do not have enough points to purchase this item."));
        ui->failLabel->show();
    }

    else{
        you->deletePoints(1000);
        ui->failLabel->setText(QString::fromStdString("Yay, you have purchased this item. Enjoy!!!"));
        ui->failLabel->show();
        n.writeUsers("users.txt");
    }
}
