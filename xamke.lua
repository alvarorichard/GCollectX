-- set the compiler
set_toolchains("clang")

-- define a target
target("gc")

    -- set kind
    set_kind("binary")

    -- add files
    add_files("main.c")
