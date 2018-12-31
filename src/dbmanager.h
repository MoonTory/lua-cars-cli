#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>

#include "Models/user.h"

namespace Luna {

	#define SQL_DRIVER "QSQLITE"

	class DbManager : public QObject
	{
		Q_OBJECT
	public:
		DbManager(const QString &_path, QObject *parent = nullptr);
		~DbManager() { this->close_db(); }

		bool insert_user(const QString & _username, const QString & _password, const QString & _level);
		bool delete_user(const QString &_username);
		bool update_username(const QString &_query, const QString &_username);
		bool update_password(const QString &_query, const QString &_password);
		bool update_level(const QString &_query, const QString &_level);
		User *auth_user(const QString &_username, const QString &_password);
		bool find_user(const QString &_query);

		void print_all_users();

	private:
		QSqlDatabase m_db;

		bool connect_db();
		void close_db();
	};
}

#endif // !DBMANAGER_H
