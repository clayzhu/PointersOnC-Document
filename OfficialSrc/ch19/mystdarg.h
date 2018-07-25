/*
** Replacement for the library stdarg.h macros.
*/

/*
** va_list
**	Define the type for a variable that will  hold a pointer to
**	the variable portion of the argument list.  char * is used
**	because arithmetic on them is not scaled.
*/
typedef	char	*va_list;

/*
** va_start
**	A macro to initialize a va_list variable to point to the
**	first of the variable arguments on the stack.
*/
#define	va_start(arg_ptr,arg)  arg_ptr = (char *)&arg + sizeof( arg )

/*
** va_arg
**	A macro that returns the value of the next variable argument
**	on the stack; it also increments arg_ptr to the next
**	argument.
*/
#define	va_arg(arg_ptr,type)	*((type *)arg_ptr)++

/*
** va_end
**	Called after the last access to variable arguments; nothing
**	needs to be done in this environment.
*/
#define	va_end(arg_ptr)
