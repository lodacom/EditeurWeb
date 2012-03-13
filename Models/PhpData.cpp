#include "PhpData.h"

QRegExp PhpData::fileExtensionRegex("*.php");
QRegExp PhpData::keywordRegex("\\band\\b|\\bE_PARSE\\b|\\bfunction\\b|\\bold_function\\b|\\bE_ERROR\\b|\\bor\\b|\\bas\\b|\\bE_WARNING\\b|\\bparent\\b|\\beval\\b|\\bPHP_OS\\b|\\bbreak\\b|\\bexit\\b|\\bcase\\b|\\bextends\\b|\\bPHP_VERSION\\b|\\bcfunction\\b|\\bFALSE\\b|\\bprint\\b|\\bfor\\b|\\brequire\\b|\\bcontinue\\b|\\bforeach\\b|\\brequire_once\\b|\\bdeclare\\b|\\breturn\\b|\\bdefault\\b|\\bstatic\\b|\\bdo\\b|\\bswitch\\b|\\bdie\\b|\\bstdClass\\b|\\becho\\b|\\belse\\b|\\bTRUE\\b|\\belseif\\b|\\bvar\\b|\\bempty\\b|\\bif\\b|\\bxor\\b|\\benddeclare\\b|\\binclude\\b|\\bvirtual\\b|\\bendfor\\b|\\binclude_once\\b|\\bwhile\\b|\\bendforeach\\b|\\bglobal\\b|\\b__FILE__\\b|\\bendif\\b|\\blist\\b|\\b__LINE__\\b|\\bendswitch\\b|\\bnew\\b|\\b__sleep\\b|\\bendwhile\\b|\\bnot\\b|\\barray\\b|\\b__wakeup\\b|\\bE_ALL\\b|\\bNULL\\b|\\bfinal\\b|\\bphp_user_filter\\b|\\binterface\\b|\\bimplements\\b|\\bpublic\\b|\\bprivate\\b|\\bprotected\\b|\\babstract\\b|\\bclone\\b|\\btry\\b|\\bcatch\\b|\\bthrow\\b|\\bthis\\b|\\buse\\b|\\bnamespace\\b");
QRegExp PhpData::keywordConstantRegex("\\btrue\\b|\\bfalse\\b|\\bnull\\b");
QRegExp PhpData::idRegex("\\$[a-zA-Z_][a-zA-Z0-9_]*");
QRegExp PhpData::numberRegex("[0-9][0-9]*\\.[0-9]+([eE][0-9]+)?[fd]?\\b|\\b0x[0-9a-fA-F]+\\b|\\b[0-9]+");
QRegExp PhpData::quotationRegex("\"[^\"]*\"|\'[^\']*\'");
QRegExp PhpData::multilineCommentStartRegex("/\\*");
QRegExp PhpData::multilineCommentEndRegex("\\*/");
QRegExp PhpData::singleLineCommentRegex("//[^\n]*|\\#.*");
QRegExp PhpData::functionRegex("[A-Za-z0-9_]+(?=\\()");
QRegExp PhpData::startPhpRegex("<\\?php");
QRegExp PhpData::endPhpRegex("\\?>");
