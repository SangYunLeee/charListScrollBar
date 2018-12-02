#include "listfirstchar.h"

ListFirstChar::ListFirstChar(QObject *parent) : QObject(parent)
{

}

QVariant ListFirstChar::cnvList() const
{
    return m_cnvList;
}

void ListFirstChar::setCnvList(const QVariant &cnvList)
{
    m_cnvList = cnvList;
}

QList<QObject *> ListFirstChar::listOfFirstChar() const
{
    return m_listOfFirstChar;
}

void ListFirstChar::setListOfFirstChar(const QList<QObject *> &listOfFirstChar)
{
    m_listOfFirstChar = listOfFirstChar;
}

