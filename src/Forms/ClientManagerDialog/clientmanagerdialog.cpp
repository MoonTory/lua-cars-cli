#include <QVBoxLayout>
#include <QHBoxLayout>
#include "clientmanagerdialog.h"
#include "../../log.h"

namespace Luna {

	ClientManagerDialog::ClientManagerDialog(QWidget *parent)
		:QDialog(parent)
	{
		this->initWidgets();
		this->configWidgets();
		this->createLayout();

		this->setAttribute(Qt::WA_QuitOnClose);
	}

	ClientManagerDialog::~ClientManagerDialog() { }

	// GETTERS

	QLineEdit *ClientManagerDialog::username() const
	{
		return m_usernameLineEdit;
	}

	QLineEdit *ClientManagerDialog::password() const
	{
		return m_passwordLineEdit;
	}

	QLineEdit *ClientManagerDialog::level() const
	{
		return m_levelLineEdit;
	}

	QPushButton *ClientManagerDialog::saveButton() const
	{
		return m_saveButton;
	}

	// PRIVATE METHODS

	void ClientManagerDialog::initWidgets()
	{
		this->m_usernameLabel = new QLabel(tr("Username:"));
		this->m_passwordLabel = new QLabel(tr("Password:"));
		this->m_levelLabel = new QLabel(tr("Level:"));
		this->m_usernameLineEdit = new QLineEdit();
		this->m_passwordLineEdit = new QLineEdit();
		this->m_levelLineEdit = new QLineEdit();
		this->m_saveButton = new QPushButton(tr("Save"));
		this->m_insertBox = new QGroupBox(tr("Client Manager Form"));
	}

	void ClientManagerDialog::configWidgets()
	{
		this->setWindowTitle("Customer Manager Dialog");
		this->setWindowIcon(QIcon(":/images/resources/icons/Moon-icon.png"));

		this->m_usernameLabel->setBuddy(this->m_usernameLineEdit);
		this->m_passwordLabel->setBuddy(this->m_passwordLineEdit);
		this->m_levelLabel->setBuddy(this->m_levelLineEdit);
	}

	void ClientManagerDialog::createLayout()
	{
		QVBoxLayout *labelLayout = new QVBoxLayout();
		labelLayout->addWidget(this->m_usernameLabel);
		labelLayout->addWidget(this->m_passwordLabel);
		labelLayout->addWidget(this->m_levelLabel);

		QVBoxLayout *lineEditLayout = new QVBoxLayout();
		lineEditLayout->addWidget(this->m_usernameLineEdit);
		lineEditLayout->addWidget(this->m_passwordLineEdit);
		lineEditLayout->addWidget(this->m_levelLineEdit);

		QHBoxLayout *formLayout = new QHBoxLayout();
		formLayout->addLayout(labelLayout);
		formLayout->addLayout(lineEditLayout);

		QVBoxLayout *groupLayout = new QVBoxLayout();
		groupLayout->addLayout(formLayout);
		groupLayout->addWidget(this->m_saveButton);
		this->m_insertBox->setLayout(groupLayout);

		QHBoxLayout *centralLayout = new QHBoxLayout();
		centralLayout->addWidget(this->m_insertBox);
		this->setLayout(centralLayout);

		this->setFixedSize(centralLayout->sizeHint());
	}

}