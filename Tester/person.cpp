#include "person.h"
#include <QJson/Parser>
#include <QJson/Serializer>
#include <QJson/QObjectHelper>
#include <QVariantMap>

Person::Person(QObject * parent) : QObject(parent)
{
    // do nothing
}

Person::~Person()
{
    // do nothing
}

Person::Person(const Person & person)
{
    setAge(person.age());
    setName(person.name());
    setCards(person.cards());
    setChildren(person.children());
    setFamily(person.family());
}
Person & Person::operator = (const Person & person)
{
    setAge(person.age());
    setName(person.name());
    setCards(person.cards());
    setChildren(person.children());
    setFamily(person.family());
    
    return *this;
}

QString Person::name() const
{
    return m_name;
}

void Person::setName(const QString& _name)
{
    this->m_name = _name;
}

int Person::age() const
{
    return m_age;
}

void Person::setAge(const int & _age)
{
    this->m_age = _age;
}

QVariantList Person::children() const
{
    QVariantList ret;
    QList<QString>::const_iterator itr = m_children.begin();
    for(; itr!=m_children.end(); itr++)
        ret.push_back(*itr);
    return ret;
}

void Person::setChildren(const QVariantList & _children)
{
    QVariantList::const_iterator itr = _children.begin();
    m_children.clear();
    for(; itr!=_children.end(); itr++)
        m_children.push_back((*itr).toString());
}

QVariantList Person::cards() const
{
    QVariantList ret;
    QList<int>::const_iterator itr = m_cards.begin();
    for(; itr!=m_cards.end(); itr++)
        ret.push_back(*itr);
    return ret;
}

void Person::setCards(const QVariantList & _cards)
{
    QVariantList::const_iterator itr = _cards.begin();
    m_cards.clear();
    for(; itr!=_cards.end(); itr++)
        m_cards.push_back((*itr).toInt());
}

QVariantMap Person::family() const
{
    return QJson::QObjectHelper::qobject2qvariant(&m_family);
}

void Person::setFamily(const QVariantMap & _family)
{
    QJson::QObjectHelper::qvariant2qobject(_family, &m_family);
}

QVariantList Person::upper() const
{
    QVariantList _upper;
    QList<Family>::const_iterator itr = m_upper.begin();
    for(; itr!=m_upper.end(); itr++)
    {
        Family _f = *itr;
        _upper.push_back(QJson::QObjectHelper::qobject2qvariant(&_f));
    }
    return _upper;
}

void Person::setUpper(const QVariantList &_upper)
{
    m_upper.clear();
    QVariantList::const_iterator itr = _upper.begin();
    for(; itr!=_upper.end(); itr++)
    {
        Family _f;
        QJson::QObjectHelper::qvariant2qobject((*itr).toMap(), &_f);
        m_upper.push_back(_f);
    }
}

// modifiers
QString & Person::getNameRef()
{
    return m_name;
}

int & Person::getAgeRef()
{
    return m_age;
}

QList<QString> & Person::getChildrenRef()
{
    return m_children;
}

QList<int>& Person::getCardsRef()
{
    return m_cards;
}

Family& Person::getFamilyRef()
{
    return m_family;
}

QList<Family> & Person::getUpperRef()
{
    return m_upper;
}

QByteArray Person::serialize()
{
    QVariantMap map = QJson::QObjectHelper::qobject2qvariant(this);
    QJson::Serializer serialzer;
    return serialzer.serialize(map, &m_ok);
}

void Person::deserialize(const QByteArray & data)
{
    QJson::Parser parser;
    QVariant var = parser.parse(data, &m_ok);
    QJson::QObjectHelper::qvariant2qobject(var.toMap(), this);
}

bool Person::ok() const
{
    return m_ok;    
}

