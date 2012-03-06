/*
 * Auteur : Abdelhamid
 * Description : liste des mots reconnaissables du JavaScript,
 * utilisable pour colorer et auto-compléter le code.
 */

#include "JavaScriptData.h"

QRegExp JavaScriptData::functionRegex("\\b[A-Za-z0-9_]+(?=\\()");
QRegExp JavaScriptData::fileExtensionRegex("*.js");
QRegExp JavaScriptData::keywordRegex("\\bfor\\b|\\bin\\b\\b|\\b\\bwhile\\b\\b|\\b\\bdo\\b|\\bbreak\\b|\\breturn\\b|\\bcontinue\\b|\\bswitch\\b|\\bcase\\b|\\bdefault\\b|\\bif\\b|\\belse\\b|\\bthrow\\b|\\btry\\b|\\bcatch\\b|\\bfinally\\b|\\bnew\\b|\\bdelete\\b|\\btypeof\\b|\\binstanceof\\b|\\bvoid\\b|\\bthis\\b");
QRegExp JavaScriptData::keywordDeclarationRegex("\\bvar\\b|\\blet\\b|\\bwith\\b|\\bfunction\\b");
QRegExp JavaScriptData::keywordReservedRegex("\\babstract\\b|\\bboolean\\b|\\bbyte\\b|\\bchar\\b|\\bclass\\b|\\bconst\\b|\\bdebugger\\b|\\bdouble\\b|\\benum\\b|\\bexport\\b|\\bextends\\b|\\bfinal\\b|\\bfloat\\b|\\bgoto\\b|\\bimplements\\b|\\bimport\\b|\\bint\\b|\\binterface\\b|\\blong\\b|\\bnative\\b|\\bpackage\\b|\\bprivate\\b|\\bprotected\\b|\\bpublic\\b|\\bshort\\b|\\bstatic\\b|\\bsuper\\b|\\bsynchronized\\b|\\bthrows\\b|\\btransient\\b|\\bvolatile\\b");
QRegExp JavaScriptData::builtInRegex("\\bArray\\b|\\bBoolean\\b|\\bDate\\b|\\bError\\b|\\bFunction\\b|\\bMath\\b|\\bnetscape\\b|\\bNumber\\b|\\bObject\\b|\\bPackages\\b|\\bRegExp\\b|\\bString\\b|\\bsun\\b|\\bdecodeURI\\b|\\bdecodeURIComponent\\b|\\bencodeURI\\b|\\bencodeURIComponent\\b|\\bError\\b|\\beval\\b|\\bisFinite\\b|\\bisNaN\\b|\\bparseFloat\\b|\\bparseInt\\b|\\bdocument\\b|\\bthis\\b|\\bwindow\\b");
QRegExp JavaScriptData::idRegex("[$a-zA-Z_][a-zA-Z0-9_]*");
QRegExp JavaScriptData::numberRegex("[0-9][0-9]*\\.[0-9]+([eE][0-9]+)?[fd]?|0x[0-9a-fA-F]+|[0-9]+");
QRegExp JavaScriptData::quotationRegex("\".*\"|\'.*\'");
QRegExp JavaScriptData::multilineCommentStartRegex("/\\*");
QRegExp JavaScriptData::multilineCommentEndRegex("\\*/");
QRegExp JavaScriptData::singleLineCommentRegex("//[^\n]*");
