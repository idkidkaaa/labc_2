#include "dll.h"


int test() {

	list_t * list = NULL;

	if (NULL != findel(list, 34567890)) {
		return 1;
	}

	if (NULL != findel(list, 24273459236469)) {
		return 1;
	}

	list = init();
	if (NULL == list) {
		return 1;
	}

	if (NULL == findel(list, 75)) {
		return 1;
	}
	
	if (NULL == addel(list, 11111111111)) {
		return 1;
	};

	if (NULL == findel(list, 11111111111)) {
		return 1;
	}

	if (NULL != delel(list, 2)) {
		return 1;
	}


	return 0;
};

int main(int argc, char** argv) {

	if (argv[1] != NULL) {
		list_t* list = NULL;
		list = init();
		add_from_file(list, argv[1]);
		return 0;
	}

	return test();
}
