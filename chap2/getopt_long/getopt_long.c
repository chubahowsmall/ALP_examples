#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>


/*
Short-Form		Long-Form			Purpose
-h				--help				print the help message
-o filename		--output file name	assing the name of output file
-v				--verbose			print verbose message
*/
/*An array describing valid long options */
const struct option long_options[] = {
	{"help", 0, NULL, 'h'},
	{"output", 1, NULL, 'o'},
	{"verbose", 0, NULL, 'v'},
	{NULL, 0, NULL, 0}
};

const char *prog_name;

void print_usage(FILE *stream, int exit_code)
{
	fprintf(stream, "Usage: %s options [ inputfile...]\n", prog_name);
	fprintf(stream,
		"	-h	--help			Display this message\n"
		"	-o	--output		Write output to file\n"
		"	-v	--verbose		Print verbose messages\n");
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	int next_option;

	/* A string listing valid short options letters. */
	const char * const short_options = "ho:v";
	const char * output_filename = NULL;

	/* Whether to display verbose message. */
	int verbose = 0;

	prog_name = argv[0];

	do{
		next_option = getopt_long(argc, 
									argv, 
									short_options,
									long_options, 
									NULL);
		switch(next_option)
		{
			case 'h':
				print_usage(stdout, 0);
				break;
			case 'o':
				output_filename = optarg;
				printf("Output file name is %s\n", output_filename);
				break;
			case 'v':
				verbose = 1;
				break;
			case '?':
				print_usage(stderr, 1);
				break;
			case -1:
				printf("No more options!\n");
				break;
		}

	}while(next_option != -1);

	if(verbose == 1)
	{
		int i = 0;
		for(i = 0; i < argc; i++)
			printf("argv[%d] = %s\n", i, argv[i]);
	}





	return 0;
}
