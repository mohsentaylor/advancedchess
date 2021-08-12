QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    Chessman.cpp \
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
    mainfunctions.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
    SFML/Audio.hpp \
    SFML/Audio/AlResource.hpp \
    SFML/Audio/Export.hpp \
    SFML/Audio/InputSoundFile.hpp \
    SFML/Audio/Listener.hpp \
    SFML/Audio/Music.hpp \
    SFML/Audio/OutputSoundFile.hpp \
    SFML/Audio/Sound.hpp \
    SFML/Audio/SoundBuffer.hpp \
    SFML/Audio/SoundBufferRecorder.hpp \
    SFML/Audio/SoundFileFactory.hpp \
    SFML/Audio/SoundFileFactory.inl \
    SFML/Audio/SoundFileReader.hpp \
    SFML/Audio/SoundFileWriter.hpp \
    SFML/Audio/SoundRecorder.hpp \
    SFML/Audio/SoundSource.hpp \
    SFML/Audio/SoundStream.hpp \
    SFML/Config.hpp \
    SFML/GpuPreference.hpp \
    SFML/Graphics.hpp \
    SFML/Graphics/BlendMode.hpp \
    SFML/Graphics/CircleShape.hpp \
    SFML/Graphics/Color.hpp \
    SFML/Graphics/ConvexShape.hpp \
    SFML/Graphics/Drawable.hpp \
    SFML/Graphics/Export.hpp \
    SFML/Graphics/Font.hpp \
    SFML/Graphics/Glsl.hpp \
    SFML/Graphics/Glsl.inl \
    SFML/Graphics/Glyph.hpp \
    SFML/Graphics/Image.hpp \
    SFML/Graphics/PrimitiveType.hpp \
    SFML/Graphics/Rect.hpp \
    SFML/Graphics/Rect.inl \
    SFML/Graphics/RectangleShape.hpp \
    SFML/Graphics/RenderStates.hpp \
    SFML/Graphics/RenderTarget.hpp \
    SFML/Graphics/RenderTexture.hpp \
    SFML/Graphics/RenderWindow.hpp \
    SFML/Graphics/Shader.hpp \
    SFML/Graphics/Shape.hpp \
    SFML/Graphics/Sprite.hpp \
    SFML/Graphics/Text.hpp \
    SFML/Graphics/Texture.hpp \
    SFML/Graphics/Transform.hpp \
    SFML/Graphics/Transformable.hpp \
    SFML/Graphics/Vertex.hpp \
    SFML/Graphics/VertexArray.hpp \
    SFML/Graphics/VertexBuffer.hpp \
    SFML/Graphics/View.hpp \
    SFML/Main.hpp \
    SFML/Network.hpp \
    SFML/Network/Export.hpp \
    SFML/Network/Ftp.hpp \
    SFML/Network/Http.hpp \
    SFML/Network/IpAddress.hpp \
    SFML/Network/Packet.hpp \
    SFML/Network/Socket.hpp \
    SFML/Network/SocketHandle.hpp \
    SFML/Network/SocketSelector.hpp \
    SFML/Network/TcpListener.hpp \
    SFML/Network/TcpSocket.hpp \
    SFML/Network/UdpSocket.hpp \
    SFML/OpenGL.hpp \
    SFML/System.hpp \
    SFML/System/Clock.hpp \
    SFML/System/Err.hpp \
    SFML/System/Export.hpp \
    SFML/System/FileInputStream.hpp \
    SFML/System/InputStream.hpp \
    SFML/System/Lock.hpp \
    SFML/System/MemoryInputStream.hpp \
    SFML/System/Mutex.hpp \
    SFML/System/NativeActivity.hpp \
    SFML/System/NonCopyable.hpp \
    SFML/System/Sleep.hpp \
    SFML/System/String.hpp \
    SFML/System/String.inl \
    SFML/System/Thread.hpp \
    SFML/System/Thread.inl \
    SFML/System/ThreadLocal.hpp \
    SFML/System/ThreadLocalPtr.hpp \
    SFML/System/ThreadLocalPtr.inl \
    SFML/System/Time.hpp \
    SFML/System/Utf.hpp \
    SFML/System/Utf.inl \
    SFML/System/Vector2.hpp \
    SFML/System/Vector2.inl \
    SFML/System/Vector3.hpp \
    SFML/System/Vector3.inl \
    SFML/Window.hpp \
    SFML/Window/Clipboard.hpp \
    SFML/Window/Context.hpp \
    SFML/Window/ContextSettings.hpp \
    SFML/Window/Cursor.hpp \
    SFML/Window/Event.hpp \
    SFML/Window/Export.hpp \
    SFML/Window/GlResource.hpp \
    SFML/Window/Joystick.hpp \
    SFML/Window/Keyboard.hpp \
    SFML/Window/Mouse.hpp \
    SFML/Window/Sensor.hpp \
    SFML/Window/Touch.hpp \
    SFML/Window/VideoMode.hpp \
    SFML/Window/Window.hpp \
    SFML/Window/WindowHandle.hpp \
    SFML/Window/WindowStyle.hpp \
    SFML/examples/shader/Effect.hpp \
    SFML/Audio.hpp \
    SFML/Audio/AlResource.hpp \
    SFML/Audio/Export.hpp \
    SFML/Audio/InputSoundFile.hpp \
    SFML/Audio/Listener.hpp \
    SFML/Audio/Music.hpp \
    SFML/Audio/OutputSoundFile.hpp \
    SFML/Audio/Sound.hpp \
    SFML/Audio/SoundBuffer.hpp \
    SFML/Audio/SoundBufferRecorder.hpp \
    SFML/Audio/SoundFileFactory.hpp \
    SFML/Audio/SoundFileFactory.inl \
    SFML/Audio/SoundFileReader.hpp \
    SFML/Audio/SoundFileWriter.hpp \
    SFML/Audio/SoundRecorder.hpp \
    SFML/Audio/SoundSource.hpp \
    SFML/Audio/SoundStream.hpp \
    SFML/Config.hpp \
    SFML/GpuPreference.hpp \
    SFML/Graphics.hpp \
    SFML/Graphics/BlendMode.hpp \
    SFML/Graphics/CircleShape.hpp \
    SFML/Graphics/Color.hpp \
    SFML/Graphics/ConvexShape.hpp \
    SFML/Graphics/Drawable.hpp \
    SFML/Graphics/Export.hpp \
    SFML/Graphics/Font.hpp \
    SFML/Graphics/Glsl.hpp \
    SFML/Graphics/Glsl.inl \
    SFML/Graphics/Glyph.hpp \
    SFML/Graphics/Image.hpp \
    SFML/Graphics/PrimitiveType.hpp \
    SFML/Graphics/Rect.hpp \
    SFML/Graphics/Rect.inl \
    SFML/Graphics/RectangleShape.hpp \
    SFML/Graphics/RenderStates.hpp \
    SFML/Graphics/RenderTarget.hpp \
    SFML/Graphics/RenderTexture.hpp \
    SFML/Graphics/RenderWindow.hpp \
    SFML/Graphics/Shader.hpp \
    SFML/Graphics/Shape.hpp \
    SFML/Graphics/Sprite.hpp \
    SFML/Graphics/Text.hpp \
    SFML/Graphics/Texture.hpp \
    SFML/Graphics/Transform.hpp \
    SFML/Graphics/Transformable.hpp \
    SFML/Graphics/Vertex.hpp \
    SFML/Graphics/VertexArray.hpp \
    SFML/Graphics/VertexBuffer.hpp \
    SFML/Graphics/View.hpp \
    SFML/Main.hpp \
    SFML/Network.hpp \
    SFML/Network/Export.hpp \
    SFML/Network/Ftp.hpp \
    SFML/Network/Http.hpp \
    SFML/Network/IpAddress.hpp \
    SFML/Network/Packet.hpp \
    SFML/Network/Socket.hpp \
    SFML/Network/SocketHandle.hpp \
    SFML/Network/SocketSelector.hpp \
    SFML/Network/TcpListener.hpp \
    SFML/Network/TcpSocket.hpp \
    SFML/Network/UdpSocket.hpp \
    SFML/OpenGL.hpp \
    SFML/System.hpp \
    SFML/System/Clock.hpp \
    SFML/System/Err.hpp \
    SFML/System/Export.hpp \
    SFML/System/FileInputStream.hpp \
    SFML/System/InputStream.hpp \
    SFML/System/Lock.hpp \
    SFML/System/MemoryInputStream.hpp \
    SFML/System/Mutex.hpp \
    SFML/System/NativeActivity.hpp \
    SFML/System/NonCopyable.hpp \
    SFML/System/Sleep.hpp \
    SFML/System/String.hpp \
    SFML/System/String.inl \
    SFML/System/Thread.hpp \
    SFML/System/Thread.inl \
    SFML/System/ThreadLocal.hpp \
    SFML/System/ThreadLocalPtr.hpp \
    SFML/System/ThreadLocalPtr.inl \
    SFML/System/Time.hpp \
    SFML/System/Utf.hpp \
    SFML/System/Utf.inl \
    SFML/System/Vector2.hpp \
    SFML/System/Vector2.inl \
    SFML/System/Vector3.hpp \
    SFML/System/Vector3.inl \
    SFML/Window.hpp \
    SFML/Window/Clipboard.hpp \
    SFML/Window/Context.hpp \
    SFML/Window/ContextSettings.hpp \
    SFML/Window/Cursor.hpp \
    SFML/Window/Event.hpp \
    SFML/Window/Export.hpp \
    SFML/Window/GlResource.hpp \
    SFML/Window/Joystick.hpp \
    SFML/Window/Keyboard.hpp \
    SFML/Window/Mouse.hpp \
    SFML/Window/Sensor.hpp \
    SFML/Window/Touch.hpp \
    SFML/Window/VideoMode.hpp \
    SFML/Window/Window.hpp \
    SFML/Window/WindowHandle.hpp \
    SFML/Window/WindowStyle.hpp \
    chessman.h

DISTFILES += \
    ../../files/Black/Frame 10.png \
    ../../files/Black/Frame 11.png \
    ../../files/Black/Frame 12.png \
    ../../files/Black/Frame 13.png \
    ../../files/Black/Frame 14.png \
    ../../files/Black/Frame 15.png \
    ../../files/gamepics/Start again.png \
    Black/Bishop.png \
    Black/King.png \
    Black/Knight.png \
    Black/Pawn.png \
    Black/Queen.png \
    Black/Rook.png \
    Frame 2.png \
    Frame 2.png \
    Frame 2.png \
    Frame 3.png \
    Frame 3.png \
    Frame 3.png \
    Frame 4.png \
    Frame 4.png \
    Frame 4.png \
    Frame 5.png \
    Frame 5.png \
    Frame 5.png \
    Frame 6.png \
    Frame 6.png \
    Frame 6.png \
    Frame 7.png \
    Frame 7.png \
    Frame 7.png \
    Frame 8.png \
    Frame 8.png \
    Frame 8.png \
    White/Bishop.png \
    White/King.png \
    White/Knight.png \
    White/Pawn.png \
    White/Queen.png \
    White/Rook.png \
    gamepics/ChessBoard.jpg.jpg \
    gamepics/Enseraf.png \
    gamepics/Exit.png \
    gamepics/OK.png \
    gamepics/Select1.png \
    gamepics/Select2.png \
    gamepics/Start again.png \
    gamepics/Start.png
