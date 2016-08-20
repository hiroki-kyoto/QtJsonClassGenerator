#ifndef CHINESEFAMILY_H
#define CHINESEFAMILY_H

#include <QObject>
#include <QString>
#include <QList>
#include <QVariant>
#include <QByteArray>
#include <QVariantList>
#include <QVariantMap>
#include <QString>
#include <QString>


class ChineseFamily : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QVariantList Member READ GetMember WRITE SetMember)
	Q_PROPERTY(bool SingleParent READ GetSingleParent WRITE SetSingleParent)
	Q_PROPERTY(QString Address READ GetAddress WRITE SetAddress)
public:
	ChineseFamily(QObject* parent=0);
	~ChineseFamily();
	ChineseFamily(const ChineseFamily& _ChineseFamily);
	ChineseFamily& operator=(const ChineseFamily& _ChineseFamily);

	QVariantList GetMember() const;
	void SetMember(const QVariantList& _Member);

	bool GetSingleParent() const;
	void SetSingleParent(const bool& _SingleParent);

	QString GetAddress() const;
	void SetAddress(const QString& _Address);

	// modifiers
	QList<QString>& GetMemberRef();
	bool& GetSingleParentRef();
	QString& GetAddressRef();
	//serializer and deserializer
	QByteArray serialize();
	void deserialize(const QByteArray& data);
	bool ok() const;
private:
	QList<QString> mMember;
	bool mSingleParent;
	QString mAddress;
	bool mOK;
};

#endif // CHINESEFAMILY_H

