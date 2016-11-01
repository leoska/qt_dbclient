#include "inforec.h"

InfoRec::InfoRec()
{
    fName = "";
    lName = "";
    id = 0;
}

InfoRec::InfoRec(const QString fnam, const QString lnam, const int i)
{
    fName = fnam;
    lName = lnam;
    id = i;
}

QString InfoRec::getName(bool flag)
{
    return flag ? fName : lName;
}

int InfoRec::getId()
{
    return id;
}

