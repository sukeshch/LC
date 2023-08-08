
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void help() {
    printf(
        R"(Options provided for sample :
    --arg1 -> option without argument 
    --arg2 -> option with required argument
    --help -> Prints this help menu
    )");
    exit(0);
}

void ArgumentsHandler(int argc, char** argv) {
    static struct option long_options[] = {
        {"arg1", no_argument, 0, 'a'},
        {"arg2", required_argument, 0, 'b'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}};
    int option_index = 0;
    int c;
    if (argc == 1) {
        help();
    }
    while ((c = getopt_long(argc, argv, "cgderblvhqp:k:t:", long_options,
                            &option_index)) != -1) {
        switch (c) {
            case 'a':
                printf("arg1 recieved\n");
                break;
            case 'b':
                printf("option arg2 recieved with argument %s \n", optarg);
                break;
            case '?':
                printf("Unknown option = %d \n", c);
                help();
                break;
            case 'h':
            default:
                help();
                break;
        }
    }
}

int main (int argc, char **argv)
{
    ArgumentsHandler(argc, argv);
    return 0;
}
