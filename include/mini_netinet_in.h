#ifndef MINI_NETINET_IN_H
#define MINI_NETINET_IN_H

// Use basic C types (no stdint.h, no stdlib.h, etc.)
typedef unsigned short sa_family_t;
typedef unsigned short in_port_t;
typedef unsigned int in_addr_t;

// IPv4 address (in network byte order)
struct in_addr {
  in_addr_t s_addr; // 32 bits
};

// sockaddr_in for IPv4
struct sockaddr_in {
  sa_family_t sin_family;    // Address family (e.g., AF_INET)
  in_port_t sin_port;        // Port number (network byte order)
  struct in_addr sin_addr;   // IPv4 address
  unsigned char sin_zero[8]; // Padding to match struct sockaddr size
};

// Useful address family and constant macros:
#define AF_INET 2                          // IPv4 protocol
#define INADDR_ANY ((in_addr_t)0x00000000) // Bind to all available interfaces

#endif // MINI_NETINET_IN_H