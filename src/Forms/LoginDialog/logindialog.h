#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

namespace Luna {

    class LoginDialog : public QDialog
    {
        Q_OBJECT
    public:
        explicit LoginDialog(QWidget *parent = nullptr);
        ~LoginDialog();

        // Getters
        QPushButton *loginBtn() const;
		QPushButton *quitBtn() const;

        QLineEdit *userEdit() const;
        QLineEdit *passEdit() const;

    private:
        QLabel *m_userLabel, *m_passLabel, *m_logo;
        QLineEdit *m_userEdit, *m_passEdit;
        QPushButton *m_loginBtn, *m_quitBtn;
    };

} // namespace Luna

#endif // LOGINDIALOG_H
