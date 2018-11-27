#include "logindialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

namespace Luna {

    LoginDialog::LoginDialog(QWidget *parent)
        :QDialog(parent)
    {
        this->setWindowTitle("Login");
        this->m_userLabel = new QLabel("Username:");
        this->m_passLabel = new QLabel("Password:");
        this->m_userEdit = new QLineEdit();
        this->m_passEdit = new QLineEdit();
        this->m_loginBtn = new QPushButton("Login");
        this->m_quitBtn = new QPushButton("Quit");

        this->m_userLabel->setBuddy(m_userEdit);
        this->m_passLabel->setBuddy(m_passEdit);

        this->m_passEdit->setEchoMode(QLineEdit::Password);

        QHBoxLayout *userLayout = new QHBoxLayout();
        userLayout->addWidget(this->m_userLabel);
        userLayout->addWidget(this->m_userEdit);

        QHBoxLayout *passLayout = new QHBoxLayout();
        passLayout->addWidget(this->m_passLabel);
        passLayout->addWidget(this->m_passEdit);

        QHBoxLayout *btnLayout = new QHBoxLayout();
        btnLayout->addWidget(this->m_loginBtn);
        btnLayout->addWidget(this->m_quitBtn);

        QVBoxLayout *mainLayout = new QVBoxLayout();
        mainLayout->addLayout(userLayout);
        mainLayout->addLayout(passLayout);
        mainLayout->addLayout(btnLayout);

        this->setLayout(mainLayout);

        //QObject::connect(this->m_loginBtn, SIGNAL(clicked(bool)), this, SLOT(loginController()));
        QObject::connect(this->m_quitBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
    }

    LoginDialog::~LoginDialog()
    {
        delete this->m_loginBtn;
        delete this->m_quitBtn;
        delete this->m_userEdit;
        delete this->m_userLabel;
        delete this->m_passEdit;
        delete this->m_passLabel;
    }

    QLineEdit *LoginDialog::passEdit() const
    {
        return m_passEdit;
    }

    QLineEdit *LoginDialog::userEdit() const
    {
        return m_userEdit;
    }

    QPushButton *LoginDialog::loginBtn() const
    {
        return m_loginBtn;
    }

}
