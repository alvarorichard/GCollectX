-- set the compiler
set_toolchains("clang")

-- Add jemalloc as a package dependency
add_requires("jemalloc")

-- define a target
target("gc")

    -- set kind
    set_kind("binary")

    -- add files
    add_files("main.c")

    -- add packages
    add_packages("jemalloc")

    -- Set additional compiler and linker flags
    on_load(function (target)
        target:add("cxxflags", "-ljemalloc", {force = true})
        target:add("ldflags", "-ljemalloc", {force = true})
    end)
