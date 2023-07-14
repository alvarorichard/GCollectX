{
    depfiles_gcc = "build/.objs/gc/linux/x86_64/release/__cpp_main.c.c: main.c\
",
    values = {
        "/usr/bin/clang",
        {
            "-Qunused-arguments",
            "-m64"
        }
    },
    files = {
        "main.c"
    }
}