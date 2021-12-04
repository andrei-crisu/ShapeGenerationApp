#include "basic_use.h"

QString html_sized_text(QString str, int fontSize,bool underlined)
{
    QString string ="<p style=\"font-size:";
    string+=QString::number(fontSize);
    string+="px\">";
    string+=str;
    string+="</p>";
    if(underlined)
        string="<u>"+string+"</u>";
    return string;

}
