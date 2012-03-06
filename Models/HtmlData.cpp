#include "HtmlData.h"

QRegExp fileExtensionRegex("*.html|*.htm|*.xhtml|*.xslt");

QRegExp numberRegex("[0-9][0-9]*\\.[0-9]+([eE][0-9]+)?[fd]?|0x[0-9a-fA-F]+|[0-9]+");
QRegExp quotationRegex("\".*\"|\'.*\'");
QRegExp specialCharRegex("\\b&.*;\\b");

static QRegExp multilineCommentStartRegex("<!--");
static QRegExp multilineCommentEndRegex("-->");

static QRegExp scriptTagOpenRegex("<script");
static QRegExp scriptTagCloseRegex("</script>");

static QRegExp styleTagOpenRegex("<style");
static QRegExp styleTagCloseRegex("</style>");

static QRegExp tagOpenRegex("<[A-Za-z0-9_]+");
static QRegExp tagCloseRegex("</[A-Za-z0-9_]>");
static QRegExp tagAttributeRegex;
