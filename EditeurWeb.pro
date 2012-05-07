QT       += webkit network

HEADERS += \
    Models/JavaScriptData.h \
    Models/HtmlData.h \
    Models/CSSData.h \
    Controllers/Highlighting/JavaScriptHighlighter.h \
    Controllers/Highlighting/Highlighter.h \
    Controllers/Highlighting/HtmlHighlighter.h \
    Controllers/Highlighting/CSSHighlighter.h \
    Views/MainWindow.h \
    Views/WorkSpaceTree.h \
    Controllers/Highlighting/PhpHighlighter.h \
    Models/PhpData.h \
    Models/WorkSpace.h \
    Models/Project.h \
    Models/Folder.h \
    Models/File.h \
    Models/Element.h \
    Controllers/WorkSpaceTreeController.h \
    Views/CentralEditor.h \
    Views/HtmlTreeWidget.h \
    Tools/Tools.h \
    Views/EditorTab.h \
    Models/HtmlIndenter.h \
    Controllers/IndenterController.h \
    Models/AccoladeLanguageIndenter.h \
    Models/PhpIndenter.h \
    Models/JavaScriptIndenter.h \
    Models/CssIndenter.h

SOURCES += \
    Models/HtmlData.cpp \
    Models/CSSData.cpp \
    Models/JavaScriptData.cpp \
    Views/MainWindow.cpp \
    main.cpp \
    Models/PhpData.cpp \
    Models/WorkSpace.cpp \
    Models/Project.cpp \
    Models/Folder.cpp \
    Models/File.cpp \
    Models/Element.cpp \
    Controllers/WorkSpaceTreeController.cpp \
    Views/WorkSpaceTree.cpp \
    Controllers/Highlighting/PhpHighlighter.cpp \
    Controllers/Highlighting/JavaScriptHighlighter.cpp \
    Controllers/Highlighting/HtmlHighlighter.cpp \
    Controllers/Highlighting/Highlighter.cpp \
    Controllers/Highlighting/CSSHighlighter.cpp \
    Views/CentralEditor.cpp \
    Views/HtmlTreeWidget.cpp \
    Tools/Tools.cpp \
    Views/EditorTab.cpp \
    Models/HtmlIndenter.cpp \
    Controllers/IndenterController.cpp \
    Models/AccoladeLanguageIndenter.cpp \
    Models/PhpIndenter.cpp \
    Models/JavaScriptIndenter.cpp \
    Models/CssIndenter.cpp

OTHER_FILES += \
    Pics/Folder-icon.png \
    Pics/File-icon.png \
    Resources/PHP.txt \
    Resources/JavaScript.txt \
    Resources/HTML.txt \
    Resources/CSS.txt \
    Pics/Save.png \
    Pics/Project-icon.png \
    Pics/File-PHP-icon.png \
    Pics/File-JS-icon.png \
    Pics/File-HTML-icon.png \
    Pics/File-CSS-icon.png \
    Pics/Cut.png \
    Pics/App-icon.png \
    Pics/Paste.png \
    Pics/Open.png \
    Pics/save.png \
    Pics/paste.png \
    Pics/open.png \
    Pics/new.png \
    Pics/cut.png \
    Pics/copy.png

RESOURCES += \
    completion.qrc \
    icons.qrc \


FORMS += \
    Views/htmltreewidget.ui
