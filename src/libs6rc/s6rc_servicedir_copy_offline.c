/* ISC license. */

#include <sys/stat.h>
#include <errno.h>

#include "s6rc-servicedir-internal.h"
#include <s6-rc/s6rc-servicedir.h>

int s6rc_servicedir_copy_offline (char const *src, char const *dst)
{
  s6rc_servicedir_desc_t const *p = s6rc_servicedir_file_list ;
  mode_t m = umask(0) ;
  int r = mkdir(dst, 0755) ;
  umask(m) ;
  if (r < 0 && errno != EEXIST) return 0 ;
  for (; p->name ; p++)
    if (!s6rc_servicedir_copy_one(src, dst, p)) return 0 ;
  return 1 ;
}
