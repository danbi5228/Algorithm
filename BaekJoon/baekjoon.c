#include <stdio.h>
#include <string.h>
char str[1000000] = { 0, };

int main() {
	int cnt = 0;
	scanf("%s", str);
	

		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == ' ') cnt++;
		}

		printf("%d", cnt + 1);
	
	return 0;
}
