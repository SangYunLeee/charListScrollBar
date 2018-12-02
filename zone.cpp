#include "zone.h"

Zone::Zone(QObject *parent) : QObject(parent)
{

}

Zone::Zone(QString zone,QString index, QObject *parent)
    : QObject (parent), m_zone(zone), m_index(index)
{

}

QString Zone::zone() const
{
    return m_zone;
}

void Zone::setZone(const QString &zone)
{
    m_zone = zone;
    emit zoneChanged();
}

QString Zone::index() const
{
    return m_index;
}

void Zone::setIndex(const QString &index)
{
    m_index = index;
}
