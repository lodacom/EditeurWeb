#include "HtmlData.h"

QRegExp HtmlData::fileExtensionRegex("*.html|*.htm|*.xhtml|*.xslt");

QRegExp HtmlData::quotationRegex("\"[^\"]*\"|\'[^\']*\'");
QRegExp HtmlData::specialCharRegex("&\\w+;");

QRegExp HtmlData::multilineCommentStartRegex("<!--");
QRegExp HtmlData::multilineCommentEndRegex("-->");

QRegExp HtmlData::scriptTagOpenRegex("<script");
QRegExp HtmlData::scriptTagCloseRegex("</script>");

QRegExp HtmlData::styleTagOpenRegex("<style");
QRegExp HtmlData::styleTagCloseRegex("</style>");

QRegExp HtmlData::tagOpenBeginRegex("<\\w+");
QRegExp HtmlData::tagOpenEndRegex(">");
QRegExp HtmlData::singleTagCloseRegex("/>");
QRegExp HtmlData::tagCloseRegex("</\\w+>");
QRegExp HtmlData::tagAttributeRegex("\\w+\\s*=");
