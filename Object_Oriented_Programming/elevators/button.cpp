# include "button.h"

Button::Button(void): light(false)
{
}

void Button::press(void)
{
	light = true;
}

void Button::clear(void)
{
	light = false;
}

bool Button::is_light(void) const
{
	return light;
}
