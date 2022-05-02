#ifndef TILI_H
#define TILI_H

#include <QObject>

class tili : public QObject
{
    Q_OBJECT
public:
    tili(QObject *parent = nullptr);
    ~tili();

signals:

};

#endif // TILI_H
