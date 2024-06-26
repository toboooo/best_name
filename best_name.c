#include <stdio.h>
#include "levenshtein.h"

int main() {
	FILE *file_ptr = fopen("names.txt", "r");
	if (!file_ptr) {
		printf("ERROR: names file could not be opened\n");
	}
	char name_buffer[100] = {0};
	int name_len = 0;
	char c;
	while ((c = fgetc(file_ptr)) != EOF) {
		if (c != '\n' && name_len < 99) {
			name_buffer[name_len++] = c;
		}
		else {
			name_buffer[name_len] = '\0';
			int dist = levenshtein_dist("best", 4, name_buffer, name_len);
			printf("%s: %d\n", name_buffer, dist);
			// Move to the end of the line if too long
			if (name_len >= 99 && c != '\n') {
				while ((c = fgetc(file_ptr)) != '\n' && c != EOF);
			}
			name_len = 0;
		}
	}
	fclose(file_ptr);
	return 0;
}
