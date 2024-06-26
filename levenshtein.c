#include <stdlib.h>

int levenshtein_dist(char *s1, int n1, char *s2, int n2) {
	int *dist_matrix = malloc((n1 + 1) * (n2 + 1) * sizeof(int));
	for (int i = 0; i <= n1; ++i) {
		dist_matrix[n2*i] = i;
	}
	for (int j = 0; j <= n2; ++j) {
		dist_matrix[j] = j;
	}
	for (int i = 1; i <= n1; ++i) {
		char c1 = s1[i-1];
		for (int j = 1; j <= n2; ++j) {
			char c2 = s2[j-1];
			if (c1 == c2) {
				dist_matrix[n2*i+j] = dist_matrix[n2*(i-1)+(j-1)];
			}
			else {
				int del_cost = dist_matrix[n2*(i-1)+j] + 1;
				int ins_cost = dist_matrix[n2*i+(j-1)] + 1;
				int sub_cost = dist_matrix[n2*(i-1)+(j-1)] + 1;
				int min_cost = del_cost;
				if (ins_cost < min_cost) {
					min_cost = ins_cost;
				}
				if (sub_cost < min_cost) {
					min_cost = sub_cost;
				}
				dist_matrix[n2*i+j] = min_cost;
			}
		}
	}
	int distance = dist_matrix[n2*n1+n2];
	free(dist_matrix);
	return distance;
}
