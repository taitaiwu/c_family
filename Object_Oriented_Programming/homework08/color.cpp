# include "color.h"

string Color::bold(const string &s)
{
	return "\x1b[1m" + s + "\x1b[0m";
}

string Color::underline(const string &s)
{
	return "\x1b[4m" + s + "\x1b[0m";
}

string Color::shine(const string &s)
{
	return "\x1b[6m" + s + "\x1b[0m";
}

string Color::black(const string &s)
{
	return "\x1b[30m" + s + "\x1b[0m";
}

string Color::red(const string &s)
{
	return "\x1b[31m" + s + "\x1b[0m";
}

string Color::green(const string &s)
{
	return "\x1b[32m" + s + "\x1b[0m";
}

string Color::yellow(const string &s)
{
	return "\x1b[33m" + s + "\x1b[0m";
}

string Color::blue(const string &s)
{
	return "\x1b[34m" + s + "\x1b[0m";
}

string Color::purple(const string &s)
{
	return "\x1b[35m" + s + "\x1b[0m";
}

string Color::teal(const string &s)
{
	return "\x1b[36m" + s + "\x1b[0m";
}

string Color::white(const string &s)
{
	return "\x1b[37m" + s + "\x1b[0m";
}

string Color::black_bg(const string &s)
{
	return "\x1b[40m" + s + "\x1b[0m";
}

string Color::red_bg(const string &s)
{
	return "\x1b[41m" + s + "\x1b[0m";
}

string Color::green_bg(const string &s)
{
	return "\x1b[42m" + s + "\x1b[0m";
}

string Color::yellow_bg(const string &s)
{
	return "\x1b[43m" + s + "\x1b[0m";
}

string Color::blue_bg(const string &s)
{
	return "\x1b[44m" + s + "\x1b[0m";
}

string Color::purple_bg(const string &s)
{
	return "\x1b[45m" + s + "\x1b[0m";
}

string Color::teal_bg(const string &s)
{
	return "\x1b[46m" + s + "\x1b[0m";
}

string Color::white_bg(const string &s)
{
	return "\x1b[47m" + s + "\x1b[0m";
}
