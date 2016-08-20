#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QList>
#include <QVariant>
#include <QByteArray>
#include <QVariantList>
#include <QVariantMap>
#include <QString>
#include <QString>

#include "ChineseFamily.hpp"

class Person : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString Name READ GetName WRITE SetName)
	Q_PROPERTY(qint32 Age READ GetAge WRITE SetAge)
	Q_PROPERTY(QVariantList Children READ GetChildren WRITE SetChildren)
	Q_PROPERTY(QVariantList Cards READ GetCards WRITE SetCards)
	Q_PROPERTY(QVariantMap Family READ GetFamily WRITE SetFamily)
	Q_PROPERTY(QVariantList Upper READ GetUpper WRITE SetUpper)
public:
	Person(QObject* parent=0);
	~Person();
	Person(const Person& _Person);
	Person& operator=(const Person& _Person);

	QString GetName() const;
	void SetName(const QString& _Name);

	qint32 GetAge() const;
	void SetAge(const qint32& _Age);

	QVariantList GetChildren() const;
	void SetChildren(const QVariantList& _Children);

	QVariantList GetCards() const;
	void SetCards(const QVariantList& _Cards);

	QVariantMap GetFamily() const;
	void SetFamily(const QVariantMap& _Family);

	QVariantList GetUpper() const;
	void SetUpper(const QVariantList& _Upper);

	// modifiers
	QString& GetNameRef();
	qint32& GetAgeRef();
	QList<QString>& GetChildrenRef();
	QList<qint32>& GetCardsRef();
	ChineseFamily& GetFamilyRef();
	QList<ChineseFamily>& GetUpperRef();
	//serializer and deserializer
	QByteArray serialize();
	void deserialize(const QByteArray& data);
	bool ok() const;
private:
	QString mName;
	qint32 mAge;
	QList<QString> mChildren;
	QList<qint32> mCards;
	ChineseFamily mFamily;
	QList<ChineseFamily> mUpper;
	bool mOK;
};

#endif // PERSON_H

