#ifndef FAMILY_H
#define FAMILY_H

#include <QObject>
#include <QVariant>
#include <QList>
#include <QString>
#include <QByteArray>

class Family : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QVariant> members READ members WRITE setMembers)
    Q_PROPERTY(bool single_parent READ singleParent WRITE setSingleParent)
    Q_PROPERTY(QString address READ address WRITE setAddress)
public:
    Family(QObject *parent = 0);
    ~Family();
    Family(const Family & _family);
    Family& operator = (const Family & _family);
    
    QList<QVariant> members() const;
    void setMembers(const QList<QVariant> & _members);
    bool singleParent() const;
    void setSingleParent(const bool & _single_parent);
    QString address() const;
    void setAddress(const QString & _address);
    
    // modifying methods
    QList<QString>& getMemberRef();
    bool& getSingleParentRef();
    QString& getAddressRef();
    
    // serializer and deserializer
    QByteArray serialize();
    void deserialize(const QByteArray & data);
    bool ok() const;

private:
    QList<QString> m_members;
    bool m_single_parent;
    QString m_address;
    bool m_ok;
};
Q_DECLARE_METATYPE(Family)

#endif // FAMILY_H
