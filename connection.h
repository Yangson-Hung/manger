#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QDebug>
#include "qdom.h"

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("easybook-3313b0");
    db.setDatabaseName("data.db");
    db.setUserName("linzhenhong");
    db.setPassword("111111");
    if(!db.open()){
        //提示出错
        return false;
    }

    QSqlQuery query;

    //创建厂家表
    query.exec("create table factory(id varchar primary key,name varchar)");
    query.exec(QString("insert into factory values('0','请选择开发商')"));
    query.exec(QString("insert into factory values('01','中庚')"));
    query.exec(QString("insert into factory values('02','碧桂园')"));
    query.exec(QString("insert into factory values('03','恒大')"));
    query.exec(QString("insert into factory values('04','金辉')"));

    //创建品牌表
    query.exec("create table brand(id varchar primary key,name varchar,factory varchar,price int,sum int,sell int,last int)");
    query.exec(QString("insert into brand values('01','紫金香山','中庚',1.2,5000,1000,4000)"));
    query.exec(QString("insert into brand values('02','融侨城','中庚',1.3,2000,500,1500)"));
    query.exec(QString("insert into brand values('03','香汇融江','中庚',1.0,8000,2000,6000)"));
    query.exec(QString("insert into brand values('04','中联城','中庚',1.1,4000,1500,2500)"));
    query.exec(QString("insert into brand values('05','华榕世纪城','碧桂园',1.0,5000,1500,3500)"));
    query.exec(QString("insert into brand values('06','铂悦府','碧桂园',1.08,6000,1000,5000)"));
    query.exec(QString("insert into brand values('07','融府','碧桂园',1.1,7000,2000,5000)"));
    query.exec(QString("insert into brand values('08','福清恒大城','恒大',1.08,7100,2100,5000)"));
    query.exec(QString("insert into brand values('09','光明城','金辉',1.2,6500,2000,4500)"));
    query.exec(QString("insert into brand values('10','尊域','金辉',1.6,1000,2000,4500)"));
    query.exec(QString("insert into brand values('11','华府','金辉',1,1000,2000,4500)"));

    //创建密码表
    query.exec("create table password(pwd varchar primary key)");
    query.exec("insert into password values('111111')");

    return true;
}

static bool createXml()
{
    QFile file("data.xml");
    if(file.exists())return true;
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return false;
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement(QString("目前预售清单"));
    doc.appendChild(root);
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
    return true;
}

#endif // CONNECTION_H
