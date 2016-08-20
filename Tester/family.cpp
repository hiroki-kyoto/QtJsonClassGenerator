#include "family.h"

#include <QVariantMap>
#include <QJson/Parser>
#include <QJson/Serializer>
#include <QJson/QObjectHelper>

Family::Family(QObject *parent) : QObject(parent)
{
    
}

Family::~Family()
{
    // nothing to do
}

Family::Family(const Family & _family)
{
    setMembers(_family.members());
    setAddress(_family.address());
    setSingleParent(_family.singleParent());
}

Family& Family::operator = (const Family & _family)
{
    setMembers(_family.members());
    setAddress(_family.address());
    setSingleParent(_family.singleParent());
    return *this;
}

QList<QVariant> Family::members() const
{
    QList<QVariant> _members;
    QList<QString>::const_iterator itr = m_members.begin();
    
    for(; itr!=m_members.end(); itr++)
        _members.push_back(*itr);
    
    return _members;
}

void Family::setMembers(const QList<QVariant> & _members)
{
    m_members.clear();
    QList<QVariant>::const_iterator itr = _members.begin();
    
    for(; itr!=_members.end(); itr++)
        m_members.push_back((*itr).toString());
}

bool Family::singleParent() const
{
    return m_single_parent;
}

void Family::setSingleParent(const bool & _single_parent)
{
    m_single_parent = _single_parent;
}

QString Family::address() const
{
    return m_address;
}

void Family::setAddress(const QString & _address)
{
    m_address = _address;
}

QByteArray Family::serialize()
{
    QVariantMap map = QJson::QObjectHelper::qobject2qvariant(this);
    QJson::Serializer serialzer;
    return serialzer.serialize(map, &m_ok);
}

void Family::deserialize(const QByteArray & data)
{
    QJson::Parser parser;
    QVariant var = parser.parse(data, &m_ok);
    QJson::QObjectHelper::qvariant2qobject(var.toMap(), this);
}

bool Family::ok() const
{
    return m_ok;
}
