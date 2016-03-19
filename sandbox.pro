TEMPLATE = app
TARGET = Allegro5Sandbox
CONFIG += desktop c++11
CONFIG += app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/stdafx.cpp
HEADERS += \
    src/stdafx.h

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/out/debug
}
CONFIG(release, debug|release) {
    DESTDIR = $$PWD/out/release
}

Media.files += \
    README

mac {
    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib -lallegro -lallegro_main -lallegro_image -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_audio

    Media.path = Contents/Resources
    QMAKE_BUNDLE_DATA += Media
}

win32 {
    INCLUDEPATH += "D:\projekte\libs\allegro\include"
    LIBS += -L"D:\projekte\libs\allegro\lib" -lallegro -lallegro_main -lallegro_image -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_audio

    Media.path = $$DESTDIR

    DLLFILES.path = $$DESTDIR
    DLLFILES.files += "D:\projekte\libs\allegro\bin\allegro-5.1.dll"
    DLLFILES.files += "D:\projekte\libs\allegro\bin\allegro_image-5.1.dll"
    DLLFILES.files += "D:\projekte\libs\allegro\bin\allegro_primitives-5.1.dll"
    DLLFILES.files += "D:\projekte\libs\allegro\bin\allegro_font-5.1.dll"
    DLLFILES.files += "D:\projekte\libs\allegro\bin\allegro_ttf-5.1.dll"
    INSTALLS += DLLFILES
    INSTALLS += Media
}


