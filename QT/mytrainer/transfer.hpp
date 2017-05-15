#ifndef TRANSFER_HPP
#define TRANSFER_HPP

#include <string>
#include <QString>
#include <QTextCodec>

using std::string;

class Transfer {

public:
    static QString gbk2UTF(const string & cstr) {
        QTextCodec* pCodec = QTextCodec::codecForName("gb2312");
        if(!pCodec) return "";
        QString qstr = pCodec->toUnicode(cstr.c_str(), cstr.length());
        return qstr;
    }
};

#endif
