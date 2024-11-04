#ifndef TEXTBROWSERSTREAM_H
#define TEXTBROWSERSTREAM_H

#include <iostream>
#include <streambuf>
#include <QTextBrowser>
#include <QRegularExpression>
#include <regex>

class TextBrowserStream : public std::streambuf
{
public:
    TextBrowserStream(QTextBrowser* browser);
protected:
    int overflow(int c = EOF) override;
    int sync() override;
private:
    QTextBrowser* textBrowser;
    std::string buffer;
};

#endif // TEXTBROWSERSTREAM_H
