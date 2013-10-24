#include "readinfo.h"
#include <QFile>
#include <QTextStream>
//#include <iostream>
#include <QStringList>

readinfo::readinfo()
{
}



void readinfo::readContent()
{

}

void splitValue(hinfo &item, QString src)
{
    QList<QString> itemList = src.split(",");
    if(itemList.size() >= 26)
    {
        item.name = itemList.at(0);
        item.cardno = itemList.at(1);
        item.Descriot = itemList.at(2);
        item.ctftp = itemList.at(3);
        item.ctfid = itemList.at(4);
        item.sex = itemList.at(5);
        item.bd = itemList.at(6);
        item.address = itemList.at(7);
        item.zip = itemList.at(8);
        item.dirty = itemList.at(9);
        item.district1 = itemList.at(10);
        item.district2 = itemList.at(11);
        item.district3 = itemList.at(12);
        item.district4 = itemList.at(13);
        item.district5 = itemList.at(14);
        item.district6 = itemList.at(15);
        item.mobile = itemList.at(19);
        item.tel = itemList.at(20);
        item.email = itemList.at(22);
        item.nation = itemList.at(23);
        item.company = itemList.at(26);
    }

}

void readinfo::searchInfoByKey(QList<hinfo>* res, QString name, QString uid, QString bd, QString phone, QString address)
{
//    std::cout<<"Enter readinfo\n";
    QList<QString> fileList;
    fileList.append("1-200W.csv");
    fileList.append("1000W-1200W.csv");
    fileList.append("1200W-1400W.csv");
    fileList.append("1400W-1600W.csv");
    fileList.append("1600w-1800w.csv");
    fileList.append("1800w-2000w.csv");
    fileList.append("200W-400W.csv");
    fileList.append("400W-600W.csv");
    fileList.append("600W-800W.csv");
    fileList.append("800W-1000W.csv");
    fileList.append("最后5000.csv");

    for(int q = 0; q < fileList.size(); q++)
    {
    QFile tmp(fileList.at(q));
    if(tmp.open(QIODevice::ReadOnly))
    {
        QTextStream content(&tmp);
        QString line;
        int n = 0;
        while(!content.atEnd())
        {
            line = tmp.readLine();
            if(line.indexOf(name) != -1 && line.indexOf(uid) != -1 && line.indexOf(bd) != -1 && line.indexOf(phone) != -1 && line.indexOf(address) != -1)
            {
                hinfo item;
                splitValue(item, line);
//                std::cout<<item.name.toStdString();
                res->append(item);
            }
            //std::cout<<"helllo"<<std::endl;
            n++;
        }
    }

    else
    {
//        std::cout<<"No Such File\n";
    }
     tmp.close();
    }
//    std::cout<<res->size();
}
