#ifndef BLINK_BREAKPOINT_H_
#define BLINK_BREAKPOINT_H_
#include <stdbool.h>
#include <stddef.h>
#include "blink/types.h"
#include <sys/types.h>

struct Breakpoint {
  i64 addr;
#if BLINK16
  u16 seg;
#endif
  const char *symbol;
  bool disable;
  bool oneshot;
};

struct Breakpoints {
  int i, n;
  struct Breakpoint *p;
};

ssize_t IsAtBreakpoint(struct Breakpoints *, u16, i64);
ssize_t PushBreakpoint(struct Breakpoints *, struct Breakpoint *);
void PopBreakpoint(struct Breakpoints *);

#endif /* BLINK_BREAKPOINT_H_ */
