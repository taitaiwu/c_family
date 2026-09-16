# ifndef BUTTON_H
# define BUTTON_H

class Button
{
	private:
		bool light;
		
	public:
		void Button(void);
		void press(void);
		void clear(void);
		bool is_light(void) const;
};

# endif
