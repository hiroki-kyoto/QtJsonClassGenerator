#include "ChineseFamily.hpp"
#include <QJson/Parser>
#include <QJson/Serializer>
#include <QJson/QObjectHelper>

ChineseFamily::ChineseFamily(QObject* parent) : QObject(parent){}
ChineseFamily::~ChineseFamily(){}

ChineseFamily::ChineseFamily(const ChineseFamily& _ChineseFamily)
{
	SetMember(_ChineseFamily.GetMember());
	SetSingleParent(_ChineseFamily.GetSingleParent());
	SetAddress(_ChineseFamily.GetAddress());
}

ChineseFamily& ChineseFamily::operator=(const ChineseFamily& _ChineseFamily)
{
	SetMember(_ChineseFamily.GetMember());
	SetSingleParent(_ChineseFamily.GetSingleParent());
	SetAddress(_ChineseFamily.GetAddress());
	return *this;
}

QVariantList ChineseFamily::GetMember() const
{
	QVariantList _Member;
	QList<QString>::const_iterator itr=mMember.begin();
	for(; itr!=mMember.end(); itr++)
		_Member.push_back(*itr);
	return _Member;
}

void ChineseFamily::SetMember(const QVariantList& _Member)
{
	QVariantList::const_iterator itr=_Member.begin();
	mMember.clear();
	for(; itr!=_Member.end(); itr++)
		mMember.push_back((*itr).toString());
}

bool ChineseFamily::GetSingleParent() const
{
	return mSingleParent;
}

void ChineseFamily::SetSingleParent(const bool& _SingleParent)
{
	this->mSingleParent = _SingleParent;
}

QString ChineseFamily::GetAddress() const
{
	return mAddress;
}

void ChineseFamily::SetAddress(const QString& _Address)
{
	this->mAddress = _Address;
}

QList<QString>& ChineseFamily::GetMemberRef()
{
	return mMember;
}

bool& ChineseFamily::GetSingleParentRef()
{
	return mSingleParent;
}

QString& ChineseFamily::GetAddressRef()
{
	return mAddress;
}

QByteArray ChineseFamily::serialize()
{
	QVariantMap map = QJson::QObjectHelper::qobject2qvariant(this);
	QJson::Serializer serializer;
	return serializer.serialize(map, &mOK);
}

void ChineseFamily::deserialize(const QByteArray& data)
{
	QJson::Parser parser;
	QVariant var = parser.parse(data, &mOK);
	QJson::QObjectHelper::qvariant2qobject(var.toMap(), this);
}

bool ChineseFamily::ok() const
{
	return mOK;
}

