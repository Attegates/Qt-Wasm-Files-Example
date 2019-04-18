HEADERS +=  \
        qhtml5file/qhtml5file.h

# Implementation only for Qt for WebAssembly applications
# Else provides non-functional stub methods just to allow compiling on other platforms.
emscripten {
    SOURCES += qhtml5file/qhtml5file_html5.cpp
} else {
    SOURCES += qhtml5file/qhtml5file.cpp
}
