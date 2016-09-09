#include "Directories.h"

// Returns a char* to "/home/username/.abe/" or ".\"
// It does not mean that that directory exists.
char *
getHomeUserAbe()
{

  static char path[PATH_SIZE];
#ifndef WIN32
  struct passwd *pwent;

  pwent = getpwuid(getuid());
  if(NULL == pwent) {
    perror("getpwuid");
    exit(EXIT_FAILURE);
  }

  sprintf(path, "%s%s", pwent->pw_dir, PATH_SEP ".abe" PATH_SEP);
#else
  sprintf(path, xstr(BASE_DIR) PATH_SEP);
#endif

  return path;
}

// MaKe Sure Home User Abe Exists.
// See above getHomeUserAbe() .
// On Windows it does nothing.
void
mkshuae()
{
#ifndef WIN32
  char *hua = getHomeUserAbe();

  if(mkdir(hua, (mode_t) S_IFDIR | S_IRWXU)) {
    perror(hua);
  }
#endif
}
