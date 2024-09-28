#include "main.h"

#include <fstream>

void read_file(const std::string& path, std::vector<char>& out) {
  std::ifstream file(path);
  file.seekg(0, std::ios::end);
  size_t size = file.tellg();
  file.seekg(0, std::ios::beg);
  
  char* buff = new char[size];
  file.read(buff, size);
  file.close();

  out = std::vector<char>(buff, buff + size);
  delete[] buff;
}

int main() {
  std::vector<char> contents;
  read_file("./in.lua", contents);
  Bytecode bc = Bytecode("", contents);
  Ast ast(bc, false, true);
  Lua lua(bc, ast, "./out.lua", true, true, true);

  bc();
  ast();
  lua();

  return 0;
}