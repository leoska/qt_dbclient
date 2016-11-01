#ifndef INFOREC_H
#define INFOREC_H

#include <QString>

class InfoRec
{
public:
    explicit InfoRec();
    explicit InfoRec(const QString, const QString, const int);
    QString getName(bool flag = true);
    int getId();
private:
    QString fName, lName;
    int id;
};

#endif // INFOREC_H
