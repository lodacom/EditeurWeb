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
    Controllers/completion.h \
    Views/htmltreewidget.h

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
    Controllers/completion.cpp \
    Views/WorkSpaceTree.cpp \
    Views/htmltreewidget.cpp \
    Controllers/Highlighting/PhpHighlighter.cpp \
    Controllers/Highlighting/JavaScriptHighlighter.cpp \
    Controllers/Highlighting/HtmlHighlighter.cpp \
    Controllers/Highlighting/Highlighter.cpp \
    Controllers/Highlighting/CSSHighlighter.cpp

OTHER_FILES += \
    Pics/Folder-icon.png \
    Pics/File-icon.png \
    Resources/PHP.txt \
    Resources/JavaScript.txt \
    Resources/HTML.txt \
    Resources/CSS.txt

RESOURCES += \
    completion.qrc

FORMS += \
    Views/htmltreewidget.ui
