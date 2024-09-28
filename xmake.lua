target("luajit-decompiler")
  set_kind("static")
  set_languages("cxx20")

  add_includedirs("./ast", "./bytecode", "./lua", "./")
  add_files("lib.cpp", "./ast/*.cpp", "./bytecode/*.cpp", "./lua/*.cpp", {force={cxflags="/J"}})

  set_symbols("debug")

target_end()

target("test")
  set_symbols("debug")
  set_languages("cxx20")
  add_files("test.cpp")
  add_deps("luajit-decompiler")
  add_includedirs("./ast", "./bytecode", "./lua", "./")
target_end()