#include "Person.hpp"
#include <QJson/Parser>
#include <QJson/Serializer>
#include <QJson/QObjectHelper>

Person::Person(QObject* parent) : QObject(parent){}
Person::~Person(){}

Person::Person(const Person& _Person)
{
	SetName(_Person.GetName());
	SetAge(_Person.GetAge());
	SetChildren(_Person.GetChildren());
	SetCards(_Person.GetCards());
	SetFamily(_Person.GetFamily());
	SetUpper(_Person.GetUpper());
}

Person& Person::operator=(const Person& _Person)
{
	SetName(_Person.GetName());
	SetAge(_Person.GetAge());
	SetChildren(_Person.GetChildren());
	SetCards(_Person.GetCards());
	SetFamily(_Person.GetFamily());
	SetUpper(_Person.GetUpper());
	return *this;
}

QString Person::GetName() const
{
	return mName;
}

void Person::SetName(const QString& _Name)
{
	this->mName = _Name;
}

qint32 Person::GetAge() const
{
	return mAge;
}

void Person::SetAge(const qint32& _Age)
{
	this->mAge = _Age;
}

QVariantList Person::GetChildren() const
{
	QVariantList _Children;
	QList<QString>::const_iterator itr=mChildren.begin();
	for(; itr!=mChildren.end(); itr++)
		_Children.push_back(*itr);
	return _Children;
}

void Person::SetChildren(const QVariantList& _Children)
{
	QVariantList::const_iterator itr=_Children.begin();
	mChildren.clear();
	for(; itr!=_Children.end(); itr++)
		mChildren.push_back((*itr).toString());
}

QVariantList Person::GetCards() const
{
	QVariantList _Cards;
	QList<qint32>::const_iterator itr=mCards.begin();
	for(; itr!=mCards.end(); itr++)
		_Cards.push_back(*itr);
	return _Cards;
}

void Person::SetCards(const QVariantList& _Cards)
{
	QVariantList::const_iterator itr=_Cards.begin();
	mCards.clear();
	for(; itr!=_Cards.end(); itr++)
		mCards.push_back((*itr).toInt());
}

QVariantMap Person::GetFamily() const
{
	return QJson::QObjectHelper::qobject2qvariant(&mFamily);
}

void Person::SetFamily(const QVariantMap& _Family)
{
	QJson::QObjectHelper::qvariant2qobject(_Family, &mFamily);
}

QVariantList Person::GetUpper() const
{
	QVariantList _Upper;
	QList<ChineseFamily>::const_iterator itr=mUpper.begin();
	for(; itr!=mUpper.end(); itr++)
	{
		ChineseFamily _ref = *itr;
		_Upper.push_back(QJson::QObjectHelper::qobject2qvariant(&_ref));
	}
	return _Upper;
}

void Person::SetUpper(const QVariantList& _Upper)
{
	mUpper.clear();
	QVariantList::const_iterator itr=_Upper.begin();
	for(; itr!=_Upper.end(); itr++)
	{
		ChineseFamily _ref;
		QJson::QObjectHelper::qvariant2qobject((*itr).toMap(), &_ref);
		mUpper.push_back(_ref);
	}
}

QString& Person::GetNameRef()
{
	return mName;
}

qint32& Person::GetAgeRef()
{
	return mAge;
}

QList<QString>& Person::GetChildrenRef()
{
	return mChildren;
}

QList<qint32>& Person::GetCardsRef()
{
	return mCards;
}

ChineseFamily& Person::GetFamilyRef()
{
	return mFamily;
}

QList<ChineseFamily>& Person::GetUpperRef()
{
	return mUpper;
}

QByteArray Person::serialize()
{
	QVariantMap map = QJson::QObjectHelper::qobject2qvariant(this);
	QJson::Serializer serializer;
	return serializer.serialize(map, &mOK);
}

void Person::deserialize(const QByteArray& data)
{
	QJson::Parser parser;
	QVariant var = parser.parse(data, &mOK);
	QJson::QObjectHelper::qvariant2qobject(var.toMap(), this);
}

bool Person::ok() const
{
	return mOK;
}

