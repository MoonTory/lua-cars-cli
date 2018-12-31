#include "DbManager.h"
#include <QDebug>

namespace Luna {

	DbManager::DbManager(const QString &_path, QObject *parent)
		:QObject(parent)
	{
		if (QSqlDatabase::isDriverAvailable(SQL_DRIVER))
		{
			this->m_db = QSqlDatabase::addDatabase(SQL_DRIVER);
			this->m_db.setDatabaseName(_path);
		}
	}

	bool DbManager::insert_user(const QString & _username, const QString & _password, const QString & _level)
	{
		bool success = false;

		if (!this->connect_db())
			success = false;
		else {
			QSqlQuery query;
			query.prepare("INSERT INTO users (username, password, level) VALUES (:username, :password, :level)");
			query.bindValue(":username", _username);
			query.bindValue(":password", _password);
			query.bindValue(":level", _level);
			if (query.exec())
			{
				success = true;
			}
			else
			{
				qDebug() << "insert_user error:"
					<< query.lastError();
			}
		}

		this->close_db();
		return success;
	}

	bool DbManager::delete_user(const QString & _username)
	{
		bool success = false;

		if (!this->connect_db())
			success = false;
		else {
			QSqlQuery query;
			query.prepare("DELETE FROM users WHERE username= (:username)");
			query.bindValue(":username", _username);
			if (query.exec())
			{
				success = true;
			}
			else
			{
				qDebug() << "delete_user error:"
					<< query.lastError();
			}
		}

		this->close_db();
		return success;
	}

	bool DbManager::update_username(const QString & _query, const QString & _username)
	{
		bool success = false;

		if (!this->connect_db())
			success = false;
		else {
			QSqlQuery query;
			query.prepare("UPDATE users SET username= (:username) WHERE username= (:query)");
			query.bindValue(":username", _username);
			query.bindValue(":query", _query);
			if (query.exec())
			{
				success = true;
			}
			else
			{
				qDebug() << "insert_user error:"
					<< query.lastError();
			}
		}

		this->close_db();
		return success;
	}

	bool DbManager::update_password(const QString & _query, const QString & _password)
	{
		bool success = false;

		if (!this->connect_db())
			success = false;
		else {
			QSqlQuery query;
			query.prepare("UPDATE users SET password= (:password) WHERE username= (:query)");
			query.bindValue(":password", _password);
			query.bindValue(":query", _query);
			if (query.exec())
			{
				success = true;
			}
			else
			{
				qDebug() << "update_password error:"
					<< query.lastError();
			}
		}

		this->close_db();
		return success;
	}

	bool DbManager::update_level(const QString & _query, const QString & _level)
	{
		bool success = false;

		if (!this->connect_db())
			success = false;
		else {
			QSqlQuery query;
			query.prepare("UPDATE users SET level= (:level) WHERE username= (:query)");
			query.bindValue(":level", _level);
			query.bindValue(":query", _query);
			if (query.exec())
			{
				success = true;
			}
			else
			{
				qDebug() << "update_level error:"
					<< query.lastError();
			}
		}

		this->close_db();
		return success;
	}

	User *DbManager::auth_user(const QString & _username, const QString & _password)
	{
		User *payload = nullptr;

		if (!this->connect_db())
			payload = nullptr;
		else {
			QSqlQuery query;
			query.prepare("SELECT username, password, level FROM users WHERE username= (:username) AND password= (:password)");
			query.bindValue(":username", _username);
			query.bindValue(":password", _password);
			if (query.exec())
			{
				if (query.next())
				{
					payload = new User();
					QString _user = query.value(0).toString();
					QString _pass = query.value(1).toString();
					QString _level = query.value(2).toString();

					payload->setUsername(_user.toStdString());
					payload->setPassword(_pass.toStdString());

					switch (_level.toInt()) { // Verifying User level, and setting payload accordingly
					case 0:
						payload->setLevel(UserLevel::USER_ADMIN);
						break;
					case 1:
						payload->setLevel(UserLevel::USER_CLIENT);
						break;
					case 2:
						payload->setLevel(UserLevel::USER_DEV);
						break;
					}
				}
			}
			else {
				payload = nullptr;
				qDebug() << "auth_user error:" << query.lastError();
			}
		}

		this->close_db();
		return payload;

	}

	bool DbManager::find_user(const QString & _query)
	{
		bool success = false;

		if (!this->connect_db())
			success = false;
		else {
			QSqlQuery query;
			query.prepare("SELECT username FROM users WHERE username= (:username)");
			query.bindValue(":username", _query);
			if (query.exec())
			{
				if (query.next())
				{
					success = true;
					QString payload = query.value(0).toString();
				}
			}
			else {
				success = false;
				qDebug() << "find_user error:" << query.lastError();
			}
		}

		this->close_db();
		return success;
	}

	void DbManager::print_all_users()
	{
		this->connect_db();

		QSqlQuery query("SELECT * FROM users");
		auto index = query.record().indexOf("username");

		while (query.next())
		{
			QString payload = query.value(index).toString();
			qDebug() << payload;
		}

		this->close_db();
	}

	bool DbManager::connect_db()
	{
		if (!this->m_db.open())
		{
			qWarning() << "ERROR:" << this->m_db.lastError();
			return false;
		}
		else {
			qDebug() << "Database: connected...";
			return true;
		}
	}

	void DbManager::close_db()
	{
		this->m_db.close();
		this->m_db = QSqlDatabase();
		this->m_db.removeDatabase(QSqlDatabase::defaultConnection);
	}

}