#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern char **environ;

int main(int argc, char *argv[]) {
	char buffer[40];
	int i;

	setreuid(geteuid(), geteuid());
	if (argc > 2) {
		printf("use argv\n");
		exit(0);
	}

	for (i = 0; environ[i]; i++) {
		memset(environ[i], 0, strlen(environ[i]));
	}

	if (strlen(argv[1]) > 56) {
		printf("argv too long\n");
		exit(0);
	}
	strcpy(buffer, argv[1]);
	printf("%s\n", buffer);

	return 0;
}
