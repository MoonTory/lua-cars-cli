#ifndef CLIENTMANAGERDIALOG_H
#define CLIENTMANAGERDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>

namespace Luna {

	class ClientManagerDialog : public QDialog
	{
		Q_OBJECT
	public:
		explicit ClientManagerDialog(QWidget *parent = nullptr);
		~ClientManagerDialog();

		// GETTERS
		QLineEdit *username() const;
		QLineEdit *password() const;
		QLineEdit *level() const;
		QPushButton *saveButton() const;
	private:
		QGroupBox *m_insertBox;
		QLabel *m_usernameLabel, *m_passwordLabel, *m_levelLabel;
		QLineEdit *m_usernameLineEdit, *m_passwordLineEdit, *m_levelLineEdit;
		QPushButton *m_saveButton;

		// Private Methods
		void initWidgets();
		void configWidgets();
		void createLayout();

	};

}

#endif // !CLIENTMANAGERDIALOG_H


