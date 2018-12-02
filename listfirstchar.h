#ifndef LISTFIRSTCHAR_H
#define LISTFIRSTCHAR_H

#include <QObject>
#include <QString>
#include <QVariant>

class ListFirstChar : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant cnvList READ cnvList WRITE setCnvList NOTIFY cnvListChanged)
public:
    explicit ListFirstChar(QObject *parent = nullptr);

    QVariant cnvList() const;
    void setCnvList(const QVariant &cnvList);

    QList<QObject *> listOfFirstChar() const;
    void setListOfFirstChar(const QList<QObject *> &listOfFirstChar);

private:
    QVariant m_cnvList;
    QList<QObject*> m_listOfFirstChar;

signals:
    void cnvListChanged();

public slots:
};

#endif // LISTFIRSTCHAR_H
