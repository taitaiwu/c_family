# include "line_break_removal_filter.h"

char Line_break_removal_filter::transform (char ch)
{
	return (ch == '\n') ? ' ' : ch;
}
