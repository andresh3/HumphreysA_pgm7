#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
/*
Andrew Humphreys CS2010 12:30
Program 7, HumphreysA_pgm7.cpp 4/23/23
Purpose: Make looing up data easier.
Input: An input file containing names and scores, and user input selecting a name to lookup.
Processing: sorts input and searches sorted list for a value.
Output: Sorted list with values, without values, and selected players value.
*/

const int MAX_PLAYERS = 50;
const string FILE_NAME = "centers_rebs_20_21-1.txt";

ifstream in_fs;
string player_names[MAX_PLAYERS];
double rebound_averages[MAX_PLAYERS];
int players; // number of players

// Open file, read data, close file
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

// With scores
void print_data( const string keys[], const double values[], const int arr_len)
{
	for (int i = 0; i < arr_len; i++)
	{
		cout << left << setw(25) << keys[i] << fixed << setprecision(1) << setw(5) << right << values[i] << endl;
	}
	return;
}
// Without scores (Just names)
void print_data(const string keys[], const int arr_len)
{
	for (int i = 0; i < arr_len; i++)
	{
		cout << left << setw(25) << keys[i] << endl;
	}
	return;
}

// Sort scores
void alphabetize_arr(string sort_arr[], double parrallel_arr[], int arr_size, bool ascending=true)
{
	// SELECTION SORT
	for (int i = 0; i < arr_size; i++)
	{
		bool do_swap = false; // Avoid time-wasting self-swaps
		int smallest_val_index = i;
		string smallest_val = sort_arr[i];

		// Innerloop, finds the smallest value in the remaining array
		// To put into the position of the outerloop
		for (int j = i; j < arr_size; j++)
		{
			string curr_val = sort_arr[j];
			bool asc_matches, dsc_matches = false;
			asc_matches = ascending && (curr_val < smallest_val);
			dsc_matches = !ascending && (curr_val < smallest_val);

			if ( asc_matches || dsc_matches)
			{
				smallest_val = curr_val;
				smallest_val_index = j;
				do_swap = true;
			}
		}

		// Swap values
		if (do_swap)
		{
			string temp_str;
			double temp_dbl;

			string& start_str = sort_arr[i];
			double& start_dbl = parrallel_arr[i];
			string& last_str = sort_arr[smallest_val_index];
			double& last_dbl = parrallel_arr[smallest_val_index];
			


			temp_str = start_str;
			temp_dbl = start_dbl;

			start_str = last_str;
			start_dbl = last_dbl;
			last_str = temp_str;
			last_dbl = temp_dbl;


		}
	}
}

int search_arr(const string search_arr[], const int arr_len, const string key)
{
	int smallest_index = 0;
	int largest_index = arr_len;
	
	while (true)
	{
		int midpoint = (smallest_index + largest_index) / 2;
		string val = search_arr[midpoint];

		if (val == key)
			return midpoint;

		// If it is not the current value, and there are no more
		// Values to check
		if (smallest_index == largest_index - 1)
			return -1;

		if (val < key)
			smallest_index = midpoint;
		if (val > key)
			largest_index = midpoint;
	}

}

int main()
{

	if (!read_data(in_fs, player_names, rebound_averages, players))
	{
		cout << "FATAL ERROR: Could not read " << FILE_NAME << "." << endl;
		return -1;
	}
	

	alphabetize_arr(player_names, rebound_averages, players);
	print_data(player_names, rebound_averages, players);
	print_data(player_names, players);

	while (true)
	{
		string player_name;
		int index;
		cout << "player > ";
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

