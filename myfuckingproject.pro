TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += C:\SFML-2.5.1\include
LIBS += C:\SFML-2.5.1\lib\libsfml-system-d.a \
  C:\SFML-2.5.1\lib\libFLAC.a \
  C:\SFML-2.5.1\lib\libfreetype.a \
  C:\SFML-2.5.1\lib\libogg.a \
  C:\SFML-2.5.1\lib\libopenal32.a \
  C:\SFML-2.5.1\lib\libsfml-audio-d.a \
  C:\SFML-2.5.1\lib\libsfml-graphics-d.a \
  C:\SFML-2.5.1\lib\libsfml-main-d.a \
  C:\SFML-2.5.1\lib\libsfml-network-d.a \
  C:\SFML-2.5.1\lib\libsfml-window-d.a \
  C:\SFML-2.5.1\lib\libvorbis.a \
  C:\SFML-2.5.1\lib\libvorbisenc.a \
  C:\SFML-2.5.1\lib\libvorbisfile.a

SOURCES += \
        Bishop.cpp \
        Cell.cpp \
        ChessBoard.cpp \
        Game.cpp \
        King.cpp \
        Knight.cpp \
        Pawn.cpp \
        Player1.cpp \
        Player2.cpp \
        Queen.cpp \
        Rook.cpp \
        chessman.cpp \
        main.cpp

HEADERS += \
    Bishop.h \
    Cell.h \
    ChessBoard.h \
    Game.h \
    King.h \
    Knight.h \
    Pawn.h \
    Player1.h \
    Player2.h \
    Queen.h \
    Rook.h \
    chessman.h
