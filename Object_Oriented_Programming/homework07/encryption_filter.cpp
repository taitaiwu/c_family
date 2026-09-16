# include "encryption_filter.h"

Encryption_filter::Encryption_filter (int key)
{
	this->key = key;
}

char Encryption_filter::transform (char ch)
{
	return ch ^ key;
}
