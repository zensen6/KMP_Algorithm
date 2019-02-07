#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

char *parent = "acabacdabac";
char *pattern = "abacdab";

int* makeTable(char* pattern) {

	int patternSize = strlen(pattern);
	int *table = (int*)malloc(patternSize*sizeof(int));
	int j = 0; int i = 1;
	memset(table, 0, sizeof(table));
	for (i = 1; i < patternSize; i++) {

		while (j > 0 && pattern[i] != pattern[j]) {

			j = table[j - 1];    // 불일치할경우 j를 마지막으로 일치했던 순간까지 하나씩이동. 이때 j = table[j-1] 이다.

		}

		if (pattern[i] == pattern[j]) {

			table[i] = ++j; // j를 1증가시킨다음에 table[i]는 indexof j라 함

		}


	}

	return table;


}

void KMP_ALGORITHM(char* originaltext, char*pattern) {

	int patternlen = strlen(pattern);
	int textlen = strlen(originaltext);
	int* table = makeTable(pattern);
	int j = 0; int i = 1;
	for (i = 1; i < textlen; i++) {

		while (j > 0 && pattern[j] != originaltext[i]) {

			j = table[j - 1];

		}

		if (originaltext[i] == pattern[j]) {

			if (j == patternlen - 1) {

				printf("인덱스 %d 에서 %d 까지 일치합니다.\n", i - patternlen + 1,i);
				//j = table[j];

			}
			else {

				j++;
			}

		}

	}

}

int main() {

	KMP_ALGORITHM(parent, pattern);
	printf("\n");
	return 0;

}