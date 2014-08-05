#include <stdio.h>

int main(int argc, char* argv[]) {

	unsigned int board_size = atoi(argv[1]);

	int result[board_size];

	unsigned int i;
	for (i = 0; i < board_size; i++) {
		result[i] = -1;
	}

	unsigned int curr_queen = 0;	// Horizontal row number
	do {
		unsigned int curr_pos;	// Vertical column number

		for (curr_pos = result[curr_queen]+1; curr_pos < board_size; curr_pos++) {
			result[curr_queen] = curr_pos;
			int ok = check(result, curr_queen);
			if (ok)  {
				if (curr_queen == board_size-1) {
					print_int_array(result, board_size);
				} else {
					curr_queen++;
				}
				break;
			}
		}
		if (curr_pos == board_size) {
			// Could not place the curr_queen
			result[curr_queen] = -1;
			curr_queen--;
		}
	} while (result[0] < board_size);
	return 0;
}

int check(unsigned int* result, unsigned int curr_queen) {
	unsigned int old_queen;
	for (old_queen = 0; old_queen < curr_queen; old_queen++) {
		if (result[old_queen] == result[curr_queen]) return 0; // Vertical allignment

		if (	result[curr_queen] < result[old_queen] && 
			(
				( result[old_queen]-result[curr_queen] ) == (curr_queen - old_queen)
			) 
		) return 0; // Cross Diagonal

		if (
			( result[curr_queen]-result[old_queen] ) == (curr_queen - old_queen)
		) return 0; // Diagonal
	}
	return 1;	// Ok
}
