// http://man7.org/linux/man-pages/man3/getifaddrs.3.html
// http://stackoverflow.com/questions/17169298/af-packet-on-osx
// http://stackoverflow.com/questions/6654526/semantic-warning-on-xcode-4
// http://stackoverflow.com/questions/8434918/find-available-network-interfaces-in-c-c
// http://www.openwall.com/lists/musl/2014/04/08/1

#include "interfaces.h"

int interfaces(void) {
  struct ifaddrs *ifap, *ifa;

  if (getifaddrs(&ifap) == -1) {
    perror("getifaddrs");
    return 1;
  }

  for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
    const char *afstr = "none";
    if (ifa->ifa_addr != NULL) {
      switch (ifa->ifa_addr->sa_family) {
      case AF_INET:
        afstr = "AF_INET";
        break;
      case AF_INET6:
        afstr = "AF_INET6";
        break;
      case PF_PACKET:
        afstr = "PF_PACKET";
        break;
      /*      case AF_LINK:
              afstr = "AF_LINK";
              break;
            case AF_PACKET:
              afstr = "AF_PACKET";
              break;*/
      default:
        afstr = "unknown";
        printf("FAMILY: %d\n", ifa->ifa_addr->sa_family);
      }
    }
    printf("%s: %s\n", ifa->ifa_name, afstr);
  }

  freeifaddrs(ifap);

  return 0;
}
