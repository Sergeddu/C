#include <stdio.h> //for printf, scanf ecc.
#include <termios.h> //for password input hiding
#include <string.h> //for strcmp 
#include <unistd.h>

int login() {
	char usr[20], pass[20];
	int attempts = 0;;
	while(attempts < 3){
		printf("Username:");
		scanf("%s", usr);
		printf("Password:");
		struct termios oldt, newt;
  		int ch;
  		tcgetattr(STDIN_FILENO, &oldt);
  		newt = oldt;
  		newt.c_lflag &= ~(ICANON | ECHO);
  		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  		scanf("%s", pass);
  		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		int check1 = strcmp(usr, "username");
		int check2 = strcmp(pass, "password");
		if (check1 == 0 && check2 == 0){
			return 1;
		}
		else {
			attempts += 1;
			
			printf("Access denied, %d out of 3 attempts used...\n", attempts);

		}
	}

	
	
	if (attempts >= 3){
		printf("Too many wrong attempts, program will now exit\n");
		return 0;
	}
}