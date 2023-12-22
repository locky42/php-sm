#include "classes/Hosts.h"
#include <string>
#include <iostream>

using namespace std;

void addHostCommand(const string& hostname, const string& ip = "127.0.0.1") {
  Hosts hostsService;
  hostsService.addHost(hostname, ip);
}

void removeHostCommand(const string& hostname) {
  Hosts hostsService;
  hostsService.removeHost(hostname);
}

int main(int argc, char* argv[])
{
  if (argc < 3) {
    cout << "Usage: " << argv[0] << " <command> <hostname> [ip]\n";
    cout << "Commands:\n";
    cout << "  addHost: Add a host\n";
    cout << "  removeHost: Remove a host\n";
    return 1;
  }

  string command = argv[1];
  string hostname = argv[2];
  string ip = (argc > 3) ? argv[3] : "127.0.0.1";

  if (command == "addHost") {
    addHostCommand(hostname, ip);
  } else if (command == "removeHost") {
    removeHostCommand(hostname);
  } else {
    cout << "Unknown command: " << command << "\n";
    return 1;
  }

  return 0;
}
