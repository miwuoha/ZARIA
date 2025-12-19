#ifndef SOCIALNETWORKWINDOW_H
#define SOCIALNETWORKWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "network.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SocialNetworkWindow;
}
QT_END_NAMESPACE

class SocialNetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    SocialNetworkWindow(QWidget *parent = nullptr);
    ~SocialNetworkWindow();
    void loginButtonClick();
    void backButtonClick();
    void tableClick(QTableWidgetItem* item);
    void maindisplay();
    void otherProfileDisplay();
    void accountDisplay();
    void createAccount();
    void loginDisplay();
    void friendTable();
    void friendSuggestionsTable();
    void postTable();
    void likeButtonClick(QTableWidgetItem* item);
    void showPosts();
    void addFriendClick();
    void addPostsClick();
    void storeDisplay();
    void buyButton1Click();
    void buyButton2Click();
    void buyButton3Click();
    void buyButton4Click();
    void buyButton5Click();
    void buyButton6Click();

private:
    Ui::SocialNetworkWindow *ui;
    Network n;
    User* you;
    User* profile;
};
#endif // SOCIALNETWORKWINDOW_H
