#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <iostream>
#include "readinfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ui->output->setText("正在读取输入信息\n");
    QString name = ui->name->text();
    QString uid = ui->uid->text();
    QString bd = ui->bd->text();
    QString phone = ui->phone->text();
    QString address = ui->address->text();

    if(name.isEmpty() && uid.isEmpty() && bd.isEmpty() && phone.isEmpty() && address.isEmpty())
    {
        ui->output->setText("至少填入一项信息\n");
        return;
    }

    ui->output->setText("读取输入信息成功\n");

    ui->output->setText("正在读取2000w：）\n");
    //read content

    //search info
    ui->output->setText("正在查找内容，请不要捉急.....");


//    for(int i = 0; i < head.size(); i++)
//    {
//        QTableWidgetItem *headItem = new QTableWidgetItem();
//        headItem->setText(head.at(i));
//        ui->tableWidget->setItem(0,i,headItem);
//    }
    readinfo *info = new readinfo();
    QList<hinfo> *res = new QList<hinfo>();
    info->searchInfoByKey(res, name, uid, bd, phone, address);
    if(res != NULL)
    {
        if(res->size() > 0)
        {
            //set row and column by result
            ui->tableWidget->setRowCount(res->size());
//            ui->tableWidget->setRowCount(18);
            ui->tableWidget->setColumnCount(15);

            //set header
            QList<QString> head;
            head.append("姓名");
            head.append("房号");
        //    head.append("descriot");
            head.append("证件类型");
            head.append("证件号码");
            head.append("性别");
            head.append("生日");
            head.append("家庭住址");
            head.append("邮编");
            head.append("dirty");
            head.append("街区");
            head.append("手机号码");
            head.append("座机");
            head.append("Email");
            head.append("民族");
            head.append("公司");

            ui->tableWidget->setHorizontalHeaderLabels(head);
            ui->tableWidget->clearContents();

//            std::cout<<res->at(0).name.toStdString();
//            std::cout<<res->at(0).ctfid.toStdString();

            for(int i = 0; i < res->size(); i++)
            {
                for(int j = 0; j < 15; j++)
                {
                    QTableWidgetItem *item = new QTableWidgetItem();
                    QString text = "";
//                    std::cout<<j;

                    if(j == 0)
                    {
                        text = res->at(i).name;
                    }
                    else if(j == 1)
                    {
                        text = res->at(i).cardno;
                    }
                    else if(j == 2)
                    {
                        text = res->at(i).ctftp;
                    }
                    else if(j == 3)
                    {
                        text = res->at(i).ctfid;
                    }
                    else if(j == 4)
                    {
                        text = res->at(i).sex;
                    }
                    else if(j == 5)
                    {
                        text = res->at(i).bd;
                    }
                    else if(j == 6)
                    {
                        text = res->at(i).address;
                    }
                    else if(j == 7)
                    {
                        text = res->at(i).zip;
                    }
                    else if(j == 8)
                    {
                        text = res->at(i).dirty;
                    }
                    else if(j == 9)
                    {
                        text = res->at(i).district1;
                    }
                    else if(j == 10)
                    {
                        text = res->at(i).mobile;
                    }
                    else if(j == 11)
                    {
                        text = res->at(i).tel;
                    }
                    else if(j == 12)
                    {
                        text = res->at(i).email;
                    }
                    else if(j == 13)
                    {
                        text = res->at(i).nation;
                    }
                    else if(j == 14)
                    {
                        text = res->at(i).company;
                    }
                    else
                    {
                        text = "None";
                    }

                    item->setText(text);
                    ui->tableWidget->setItem(i,j,item);
                }


            }

        }
    }
    ui->lcdNumber->display("12");
    ui->output->setText("查找完成.....");
}
