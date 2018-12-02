#ifndef ZONE_H
#define ZONE_H

#include <QObject>

class Zone : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString zone READ zone WRITE setZone NOTIFY zoneChanged)
    Q_PROPERTY(QString index READ index WRITE setIndex NOTIFY indexChanged)
public:
    explicit Zone(QObject *parent = nullptr);
    explicit Zone(QString zone,QString index = "empty", QObject *parent = nullptr);

    QString zone() const;
    void setZone(const QString &zone);

    QString index() const;
    void setIndex(const QString &index);

private:
    QString m_zone;
    QString m_index;
signals:
    void zoneChanged();
    void indexChanged();

public slots:
};

#endif // ZONE_H
