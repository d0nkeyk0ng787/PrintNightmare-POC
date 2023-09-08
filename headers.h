#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <windows.h>
#include <Rpc.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <Shlwapi.h>

#pragma comment(lib, "rpcrt4.lib")
#pragma comment(lib, "Shlwapi.lib")

#define okay(msg, ...) printf("[+] " msg "\n", ##__VA_ARGS__)
#define info(msg, ...) printf("[i] " msg "\n", ##__VA_ARGS__)
#define warn(msg, ...) printf("[!] " msg "\n", ##__VA_ARGS__)

#endif