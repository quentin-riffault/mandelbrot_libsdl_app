TARGET = mandelbrot

HEADERS += include/mandelbrot.h

SOURCES += src/mandelbrot.cpp
SOURCES += src/App.cpp
SOURCES += src/main.cpp


INCLUDEPATH += include
INCLUDEPATH += /usr/include
INCLUDEPATH += -I/usr/local/include/SDL2

LIBS += -L/usr/local/include/SDL2
LIBS += -L/usr/local/lib
LIBS += -L./lib

LIBS += -lsdl_app
LIBS += -lSDL2

QMAKE_CXXFLAGS  += -D_REENTRANT
