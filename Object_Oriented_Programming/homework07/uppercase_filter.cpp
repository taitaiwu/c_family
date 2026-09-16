# include <cctype>

# include  "uppercase_filter.h"

char Uppercase_filter::transform (char ch)
{
	return toupper(static_cast<unsigned char>(ch));
}
