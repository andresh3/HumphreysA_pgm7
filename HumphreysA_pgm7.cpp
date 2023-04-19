#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_PLAYERS = 50;
const string FILE_NAME = "centers_rebs_20_21-1.txt";

bool read_data(ifstream& fs, string player_names[], double rebound_averages[], int& players)
{

	fs.open(FILE_NAME);

	if (!fs.is_open() || fs.bad())
		return false;

	int i = 0;
	while (!fs.eof() && fs.good())
	{
		fs >> player_names[i];
		fs >> rebound_averages[i];
		i++;
	}
	players = i; 


	fs.close();
}

void print_data( const string keys[], const double values[], const int arr_len)
{
	for (int i = 0; i < arr_len; i++)
	{
		cout << left << setw(25) << keys[i] << fixed << setprecision(1) << setw(5) << right << values[i] << endl;
	}
	return;
}
void print_data(const string keys[], const int arr_len)
{
	for (int i = 0; i < arr_len; i++)
	{
		cout << left << setw(25) << keys[i] << endl;
	}
	return;
}

void alphabetize_arr(string sort_arr[], double parrallel_arr[], int arr_size, bool ascending=true)
{
	// "ascending modifier"
	int asc_mod = 1;
	if (!ascending)
		asc_mod = -1;


	// SELECTION SORT
	for (int i = 0; i < arr_size; i++)
	{
		int smallest_val_index = i;
		int smallest_val = sort_arr[i];
		for (int j = i; j++; j < arr_size)
		{
			int curr_val = sort_arr[j];
			if (curr_val * asc_mod < smallest_val)
			{

			}
		}
	}
	cout << "FIX ME: alphabetize_arr(string sort_arr[], double parralel_arr, int arr_size)" << endl;
}

int search_arr(const string search_arr[], const int arr_len, const string key)
{
	cout << "FIX ME: search_arr(const string search_arr[], const int arr_len, const string key)" << endl;
	return -1;
}

int main()
{
	ifstream in_fs;
	string player_names[MAX_PLAYERS];
	double rebound_averages[MAX_PLAYERS];
	int players = 0;

	if (!read_data(in_fs, player_names, rebound_averages, players))
	{
		cout << "FATAL ERROR: Could not read " << FILE_NAME << "." << endl;
		return -1;
	}
	print_data(player_names, rebound_averages, players);
	print_data(player_names, players);

	alphabetize_arr(player_names, rebound_averages, players);
	while (true)
	{
		string player_name;
		int index;
		cin >> player_name;
		index = search_arr(player_names, players, player_name);
		
		if (index == -1)
		{
			cout << "The player cannot be found" << endl;
			break;
		}
		cout << player_names[index] << " had " << rebound_averages[index] << " rebounds per game during the 2020-21 regular season." << endl;

	}
	
}

