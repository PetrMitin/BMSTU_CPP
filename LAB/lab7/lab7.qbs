import qbs

CppApplication {
    consoleApplication: true
    install: true
    files: [
        "f.txt",
        "g.txt",
        "main.cpp",
    ]
}
