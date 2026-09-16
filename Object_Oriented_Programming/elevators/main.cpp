# include <iostream>
# include <string>
# include <vector>

# include "user_input.h"
# include "simulation.h"
# include "color.h"

using namespace std;

int main(void)
{
	Color color;
	User_input config;
	string config_path = "config.txt";

	if (!config.file_input(config_path))
	{
		config.manual_input();
	}

	while (!config.data_check())
	{
		const vector<string>& errors = config.get_fatal_error();

		for (size_t i = 0; i < errors.size(); i++) cout << errors[i] << endl;

		cout << endl << "Please re-enter the settings." << endl;
		config.manual_input();
	}

	config.data_output();

	cout << endl << color.bold(color.green(" Simulation start... ")) << endl;

	Simulation simulation(config);
	simulation.run();
	simulation.print_report();
}
