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
    Controllers/CompleterController.h \
    Views/HtmlTreeWidget.h \
    Models/SyntaxTreeItem.h \
    Models/SyntaxTree.h \
    Tools/Tools.h \
    Views/EditorTab.h

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
    Controllers/CompleterController.cpp \
    Views/HtmlTreeWidget.cpp \
    Models/SyntaxTreeItem.cpp \
    Models/SyntaxTree.cpp \
    Tools/Tools.cpp \
    Views/EditorTab.cpp

OTHER_FILES += \
    Pics/Folder-icon.png \
    Pics/File-icon.png \
    Resources/PHP.txt \
    Resources/JavaScript.txt \
    Resources/HTML.txt \
    Resources/CSS.txt

RESOURCES += \
    completion.qrc \
    examples.qrc

FORMS += \
    Views/htmltreewidget.ui
