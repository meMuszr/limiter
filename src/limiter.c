#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <getopt.h>

#include "../include/limiter.h"

#define PROGRAM_NAME "limiter"

#define AUTHORS \
  "Mustafa Abdul-Kader"

static int help_flag = 0;

static const struct option long_options[] = {
	{"max", required_argument, 0, true},
	{"min", required_argument, 0, true},
	{"help", no_argument, &help_flag, true},
	{0, 0, 0, 0}
};

int main(int argc, char **argv)
{
	int c;
	static int64_t max_amount = LLONG_MAX;
	static int64_t min_amount = LLONG_MIN;
	while (1) {
		int option_index = 0;
		c = getopt_long(argc, argv, "M:m:h", long_options,
				&option_index);
		if (c < 0) {
			break;
		}
		switch (c) {
		case 1:{
				const char *opt_name =
				    long_options[option_index].name;
				if (strcmp("max", opt_name) == 0) {
					max_amount = atoll(optarg);
				} else if (strcmp("min", opt_name) == 0) {
					min_amount = atoll(optarg);
				}
				break;

			}
		case 'M':
			max_amount = atoll(optarg);
			break;
		case 'm':
			min_amount = atoll(optarg);
			break;
		case 'h':
			help_flag = true;
			break;
		default:	/* '?' */
			fprintf(stderr,
				"Try 'limiter --help' for more information.\n");
			exit(EXIT_FAILURE);
		}
		if (help_flag) {
			printf("\
Usage: limiter [OPTION] <<< [NUMBER]\n\
Prints supplied container nubmers to standard output if they are ISO6346 compliant, otherwise to standard error.\n\n  \
-M, --max NUMBER	  The maximum limit for the supplied number \n  \
-m, --min NUMBER	  The minimum limit for the supplied number\n  \
-h, --help		  Print help dialog\n");
			exit(EXIT_SUCCESS);
		}
	}
	size_t nread;
	size_t len = 0;
	char *line = NULL;
	while ((nread = getline(&line, &len, stdin)) != -1) {
		int64_t number = atoll(line);
		printf("%li\n", apply_limit(&min_amount, &max_amount, &number));

	}
	free(line);
	exit(EXIT_SUCCESS);
}
