#include "textbrowserstream.h"

TextBrowserStream::TextBrowserStream(QTextBrowser* browser) : textBrowser(browser){}

QString convertAnsiToHtml(const std::string& text) {
    QString html = QString::fromStdString(text);

    // Define regex patterns for different ANSI codes
    QRegularExpression resetPattern("\\033\\[0m");
    QRegularExpression boldPattern("\\033\\[1m");
    QRegularExpression colorPatterns[] = {
        QRegularExpression("\\033\\[30m"), // Black
        QRegularExpression("\\033\\[31m"), // Red
        QRegularExpression("\\033\\[32m"), // Green
        QRegularExpression("\\033\\[33m"), // Yellow
        QRegularExpression("\\033\\[34m"), // Blue
        QRegularExpression("\\033\\[35m"), // Purple
        QRegularExpression("\\033\\[36m"), // Cyan
    };
    QRegularExpression bgColorPatterns[] = {
        QRegularExpression("\\033\\[40m"), // Background Black
        QRegularExpression("\\033\\[47m"), // Background White
    };

    // Replace ANSI codes with HTML tags for colors
    html.replace(colorPatterns[0], "<span style=\"color:black\">");
    html.replace(colorPatterns[1], "<span style=\"color:red\">");
    html.replace(colorPatterns[2], "<span style=\"color:green\">");
    html.replace(colorPatterns[3], "<span style=\"color:yellow\">");
    html.replace(colorPatterns[4], "<span style=\"color:blue\">");
    html.replace(colorPatterns[5], "<span style=\"color:purple\">");
    html.replace(colorPatterns[6], "<span style=\"color:cyan\">");

    // Replace ANSI codes with HTML tags for background colors
    html.replace(bgColorPatterns[0], "<span style=\"background-color:black\">");
    html.replace(bgColorPatterns[1], "<span style=\"background-color:white\">");

    // Replace ANSI codes for reset and bold
    html.replace(resetPattern, "</span>");
    html.replace(boldPattern, "<b>");

    // Close any open <span> tags after the bold formatting
    html.replace(boldPattern, "</b>");

    return html;
}

int TextBrowserStream::overflow(int c) {
    if (c == '\n') {
        // Append the buffered line with HTML formatting to QTextBrowser
        textBrowser->append(convertAnsiToHtml(buffer));
        buffer.clear();
    } else if (c != EOF) {
        buffer += static_cast<char>(c);
    }
    return c;
}

int TextBrowserStream::sync(){
    if (!buffer.empty()) {
        textBrowser->append(convertAnsiToHtml(buffer));
        buffer.clear();
    }
    return 0;
}
