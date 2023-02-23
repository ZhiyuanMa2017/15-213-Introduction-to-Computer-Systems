#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

struct cache_line
{
    int valid;
    int tag;
    int counter;
};

struct cache_line **cache;
int s, S, E, b;
int v;
char file_name[100];
int hit, miss, eviction;

int init()
{
    cache = (struct cache_line **)malloc(S * sizeof(struct cache_line *));
    for (int i = 0; i < S; i++)
    {
        cache[i] = (struct cache_line *)malloc(E * sizeof(struct cache_line));
        for (int j = 0; j < E; j++)
        {
            cache[i][j].valid = 0;
            cache[i][j].tag = 0;
            cache[i][j].counter = 0;
        }
    }
    return 0;
}

int access_cache(char access_type, unsigned long address, int size)
{
    int set_index = (address >> b) & (S - 1);
    int tag = address >> (s + b);
    int max_counter = 0;
    int max_counter_index = 0;
    for (int j = 0; j < E; j++)
    {
        if (cache[set_index][j].valid == 1 && cache[set_index][j].tag == tag)
        {
            hit++;
            cache[set_index][j].counter = 0;
            return 1;
        }
    }

    miss++;
    for (int j = 0; j < E; j++)
    {
        if (cache[set_index][j].valid == 0)
        {
            cache[set_index][j].valid = 1;
            cache[set_index][j].tag = tag;
            cache[set_index][j].counter = 0;
            return 2;
        }
    }

    eviction++;
    for (int j = 0; j < E; ++j)
    {
        if (cache[set_index][j].counter > max_counter)
        {
            max_counter = cache[set_index][j].counter;
            max_counter_index = j;
        }
    }
    cache[set_index][max_counter_index].tag = tag;
    cache[set_index][max_counter_index].counter = 0;

    return 3;
}

int display(char access_type, unsigned long address, int size, int res1, int res2)
{
    if (v == 1)
    {
        printf("%c %lx,%d ", access_type, address, size);
        switch (res1)
        {
        case 1:
            printf("hit ");
            break;
        case 2:
            printf("miss ");
            break;
        case 3:
            printf("miss eviction ");
            break;
        default:
            break;
        }
        switch (res2)
        {
        case 1:
            printf("hit ");
            break;
        case 2:
            printf("miss ");
            break;
        case 3:
            printf("miss eviction ");
            break;
        default:
            break;
        }
        printf("\n");
    }
    return 0;
}

int read_and_access()
{
    FILE *pFile;
    pFile = fopen(file_name, "r");
    char access_type;
    unsigned long address;
    int size;
    int res1;
    int res2;
    while (fscanf(pFile, " %c %lx,%d", &access_type, &address, &size) > 0)
    {
        res1 = 0;
        res2 = 0;
        switch (access_type)
        {
        case 'I':
            break;
        case 'L':
            res1 = access_cache(access_type, address, size);
            display(access_type, address, size, res1, 0);
            break;
        case 'S':
            res1 = access_cache(access_type, address, size);
            display(access_type, address, size, res1, 0);
            break;
        case 'M':
            res1 = access_cache(access_type, address, size);
            res2 = access_cache(access_type, address, size);
            display(access_type, address, size, res1, res2);
            break;
        default:
            break;
        }

        for (int i = 0; i < S; i++)
        {
            for (int j = 0; j < E; j++)
            {
                cache[i][j].counter++;
            }
        }
    }
    fclose(pFile);
    return 0;
}

int free_cache()
{
    for (int i = 0; i < S; i++)
    {
        free(cache[i]);
    }
    free(cache);
    return 0;
}

int main(int argc, char *argv[])
{
    s = -1;
    S = -1;
    E = -1;
    b = -1;
    hit = 0;
    miss = 0;
    eviction = 0;
    v = 0;
    int o;
    while ((o = getopt(argc, argv, "s:E:b:t:hv")) != -1)
    {
        switch (o)
        {
        case 's':
            s = atoi(optarg);
            S = 1 << s;
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            break;
        case 't':
            strcpy(file_name, optarg);
            break;
        case 'v':
            v = 1;
            break;
        case 'h':
            printf("-h: Optional help flag that prints usage info\n"
                   "-v: Optional verbose flag that displays trace info\n"
                   "-s <s>: Number of set index bits (S = 2s is the number of sets)\n"
                   "-E <E>: Associativity (number of lines per set)\n"
                   "-b <b>: Number of block bits (B = 2b is the block size)\n"
                   "-t <tracefile>: Name of the valgrind trace to replay\n");
            break;
        default:
            printf("./csim [-hv] -s <s> -E <E> -b <b> -t <tracefile>");
        }
    }

    if (s == -1 || S == -1 || E == -1 || b == -1 || strcmp(file_name, "-1") == 0)
    {
        printf("Missing required command line argument\n");
        exit(1);
    }

    init();

    read_and_access();

    free_cache();

    printSummary(hit, miss, eviction);

    return 0;
}
