#ifndef LISTZONE_H
#define LISTZONE_H

#include <QObject>
#include <QString>
#include <QDirIterator>
#include <QVariant>
#include <zone.h>
#include <listfirstchar.h>
#include <vector>
#include <iostream>

class ListZone : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant convertedList READ convertedList WRITE setConvertedList NOTIFY convertedListChanged)
    Q_PROPERTY(QVariant convertedCharList READ convertedCharList WRITE setConvertedCharList NOTIFY convertedCharListChanged)

public:
    explicit ListZone(QObject *parent = nullptr);

    QVariant convertedList() const;
    void setConvertedList(const QVariant &convertedList);

    QVariant convertedCharList() const;
    void setConvertedCharList(const QVariant &convertedCharList);

private:
    QList<QObject*> m_listForZone;
    QList<QObject*> m_listForChar;
    QVariant m_convertedList;
    QVariant m_convertedCharList;
    QList<QString> chosungList;

signals:
    void convertedListChanged();
    void convertedCharListChanged();
public slots:
    void getListStringFromQml(const QVariant &folderPath );
    void test();
};

#endif // LISTZONE_H
