QT       += webkit network

HEADERS += \
    Models/JavaScriptData.h \
    Models/HtmlData.h \
    Models/CSSData.h \
    Controllers/JavaScriptHighlighter.h \
    Controllers/Highlighter.h \
    Controllers/HtmlHighlighter.h \
    Controllers/CSSHighlighter.h \
    Views/MainWindow.h \
    Views/WorkSpaceTree.h \
    Controllers/PhpHighlighter.h \
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
    Controllers/JavaScriptHighlighter.cpp \
    Controllers/HtmlHighlighter.cpp \
    Controllers/Highlighter.cpp \
    Controllers/CSSHighlighter.cpp \
    Models/JavaScriptData.cpp \
    Views/MainWindow.cpp \
    main.cpp \
    Controllers/PhpHighlighter.cpp \
    Models/PhpData.cpp \
    Models/WorkSpace.cpp \
    Models/Project.cpp \
    Models/Folder.cpp \
    Models/File.cpp \
    Models/Element.cpp \
    Controllers/WorkSpaceTreeController.cpp \
    Controllers/completion.cpp \
    Views/WorkSpaceTree.cpp \
    Views/htmltreewidget.cpp

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
