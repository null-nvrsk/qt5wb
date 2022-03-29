#include "mylib.h"

MyLib::MyLib()
{
    Q_INIT_RESOURCE(resources);
}

QString MyLib::message()
{
    QString msg;

    QFile file(":/files/data/readme.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        msg = stream.readAll();
        file.close();
    }

    return msg;
}

QString MyLib::test()
{
    QString msg = "This is a test";
    return msg;
}
