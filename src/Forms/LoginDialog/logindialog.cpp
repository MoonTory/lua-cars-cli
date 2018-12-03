#include "logindialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QDebug>

namespace Luna {

    LoginDialog::LoginDialog(QWidget *parent)
        :QDialog(parent)
    {
        this->setWindowTitle("Login");
        this->setWindowIcon(QIcon(":/images/resources/icons/Moon-icon.png"));
        this->setFixedSize(265, 145);

        this->m_logo = new QLabel();
        this->m_logo->setPixmap(QPixmap(QString(":/images/resources/logo/Luna_Cars_Client_Logo.png")));

        this->m_userLabel = new QLabel(tr("Username:"));
        this->m_passLabel = new QLabel(tr("Password:"));
        this->m_userEdit = new QLineEdit();
        this->m_passEdit = new QLineEdit();
        this->m_loginBtn = new QPushButton(tr("Login"));
        this->m_quitBtn = new QPushButton(tr("Quit"));

        this->m_userLabel->setBuddy(m_userEdit);
        this->m_passLabel->setBuddy(m_passEdit);

        this->m_passEdit->setEchoMode(QLineEdit::Password);

        QVBoxLayout *labelLayout = new QVBoxLayout();
        labelLayout->addWidget(this->m_userLabel);
        labelLayout->addWidget(this->m_passLabel);

        QVBoxLayout *editLayout = new QVBoxLayout();
        editLayout->addWidget(this->m_userEdit);
        editLayout->addWidget(this->m_passEdit);

        QHBoxLayout *loginLayout = new QHBoxLayout();
        loginLayout->addLayout(labelLayout);
        loginLayout->addLayout(editLayout);

        QHBoxLayout *btnLayout = new QHBoxLayout();
        btnLayout->addWidget(this->m_loginBtn);
        btnLayout->addWidget(this->m_quitBtn);

        QVBoxLayout *mainLayout = new QVBoxLayout();
        mainLayout->addWidget(this->m_logo);
        mainLayout->addLayout(loginLayout);
        mainLayout->addLayout(btnLayout);

        this->setLayout(mainLayout);

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
