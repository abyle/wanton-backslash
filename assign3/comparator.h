#ifndef _COMPARATOR_INCLUDED_
#define _COMPARATOR_INCLUDED_

typedef int (*Comparator)(void *,void *);
typedef void (*Printer)(FILE *,void *);

extern int intComparator(void *,void *);
extern int realComparator(void *,void *);
extern int stringComparator(void *,void *);

#endif
