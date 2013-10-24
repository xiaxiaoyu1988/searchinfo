#ifndef READINFO_H
#define READINFO_H
#include <QString>

struct hinfo
{
    QString name;
    QString cardno;
    QString Descriot;
    QString ctftp;
    QString ctfid;
    QString sex;
    QString bd;
    QString address;
    QString zip;
    QString dirty;
    QString district1;
    QString district2;
    QString district3;
    QString district4;
    QString district5;
    QString district6;
    QString mobile;
    QString tel;
    QString email;
    QString nation;
    QString company;
};

class readinfo
{
public:
    readinfo();
    void readContent();
    void searchInfoByKey(QList<hinfo>*res, QString name, QString uid, QString bd, QString phone, QString address);
};

#endif // READINFO_H
