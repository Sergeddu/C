#include "login.h"


int main() {
	int access = login();
	if (access == 1){
		printf("Access granted\n");
		return 0;
	}
	else {
		return 0;
	}
}