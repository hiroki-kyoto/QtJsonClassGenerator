#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QList>
#include <QVariant>
#include <QByteArray>

#include "family.h"

// be careful! PROPERTY ONLY RECOGNIZE LIST<QVARIANT> !!!

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(int age READ age WRITE setAge)
    Q_PROPERTY(QVariantList children READ children WRITE setChildren)
    Q_PROPERTY(QVariantList cards READ cards WRITE setCards)
    Q_PROPERTY(QVariantMap family READ family WRITE setFamily)
    Q_PROPERTY(QVariantList upper READ upper WRITE setUpper)
public:
    Person(QObject * parent=0);
    ~Person();
    Person(const Person & person);
    Person & operator = (const Person & person);
    
    QString name() const;
    void setName(const QString & _name);
    
    int age() const;
    void setAge(const int & _age);
    
    QVariantList children() const;
    void setChildren(const QVariantList & _children);
    
    QVariantList cards() const;
    void setCards(const QVariantList & _cards);
    
    QVariantMap family() const;
    void setFamily(const QVariantMap & _family);
    
    QVariantList upper() const;
    void setUpper(const QVariantList & _upper);
    
    // modifiers
    QString & getNameRef();
    int & getAgeRef();
    QList<QString> & getChildrenRef();
    QList<int> & getCardsRef();
    Family & getFamilyRef();
    QList<Family> & getUpperRef();
    
    // serializer and deserialzer
    QByteArray serialize();
    void deserialize(const QByteArray & data);
    bool ok() const;
    
private:
    QString m_name;
    int m_age;
    QList<QString> m_children;
    QList<int> m_cards;
    Family m_family;
    QList<Family> m_upper;
    bool m_ok;
};

#endif // PERSON_H
