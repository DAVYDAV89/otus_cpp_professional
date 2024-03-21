#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "interface.h"

int get_n(int argc, char* argv[])
{
    if (argc != 2) return 0;
    try
    {
      int n = std::stoul(argv[1]);
      return n;
    }
    catch (...)
    {
      return 0;
    }
}

std::string trim(const std::string& s, const char * _whitespaces = " \n\r\t\f\v")
{
    const std::string whitespaces(_whitespaces);
    const std::size_t from = s.find_first_not_of(whitespaces);
    if (from == std::string::npos) return "";
    std::string res = s.substr(from);
    const std::size_t to = res.find_last_not_of(whitespaces);
    if (to == std::string::npos) return "";
    return res.substr(0, to + 1);
}

int main(int argc, char* argv[])
{
  int n = get_n(argc, argv);
  if (n <= 0)
  {
    std::cerr
      << "Usage: bulk <N>" << std::endl
      << "       where N - the number of commands processed at a bulk" << std::endl;
    return EXIT_FAILURE;
  }
  auto bulk_finalizer = [](const std::time_t& t, const std::string& line) {
    std::cout << line << std::endl;
    std::string filename = "bulk" + std::to_string(t) + ".log";
    std::ofstream f(filename);
    f << line << std::endl;
    f.close();
  };

  interface::custom_bulk_t bulk(n, bulk_finalizer);
  std::string cmd;
  while (std::getline(std::cin, cmd))
  {
    cmd = trim(cmd);
    if (cmd.empty())
      break;
    else if (cmd == "{")
      bulk.start_transaction();
    else if (cmd == "}")
      bulk.commit_transaction();
    else
      bulk.prepare(new interface::custom_command_t(cmd));
  }
  return EXIT_SUCCESS;
}
