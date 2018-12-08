#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
static int test;
typedef struct trie_node trie_node_t;
struct trie_node
{
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};
typedef struct trie trie_t;
struct trie
{
    trie_node_t *root;
    int count;
};
trie_node_t *getNode()
{
    trie_node_t *pNode = NULL;
    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));
    if(!pNode)
    {
        printf("\n\nMemory allocation failed!!");
        return NULL;
    }
    if( pNode )
    {
        int i;
        pNode->value = 0;
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
    return pNode;
}
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}

void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
    pTrie->count++;
    pCrawl = pTrie->root;
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
        {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->value = pTrie->count;
}
int search(trie_t *pTrie, char key[])
{
    int level,i;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
    pCrawl = pTrie->root;
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);

        if( !pCrawl->children[index] )
        {
            return 0;
        }
        pCrawl = pCrawl->children[index];
    }
    return (0 != pCrawl && pCrawl->value);
}
void traverse(trie_node_t *pCrawl, char key[],int index)
{
   int i;
   char *temp;
   if(!pCrawl)
   {
       return ;
   }
   if(pCrawl->value!=0&&pCrawl!=NULL)
   {
       printf("%s\n",key);
   }
   for(i=0;i<26;i++)
   {
       temp=(char *)malloc(sizeof(char)*strlen(key)+2);
       strcpy(temp,key);
       temp[strlen(key)]=(char)(97+i);
       temp[strlen(key)+1]='\0';
       if(pCrawl->children[i]!=NULL)
       traverse(pCrawl->children[i], temp,i);
       free(temp);
   }
}
int suggestions(trie_t *pTrie, char key[])
{
    int level,i;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
    pCrawl = pTrie->root;
    if(strcmp(key,"")==0)
    {
        printf("The input is NULL!!");
        return 0;
    }
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] )
        {
            printf("Prefix is not present");
                return 0;
        }
        pCrawl = pCrawl->children[index];
    }
    traverse(pCrawl, key,index);
}
int check(char key[])
{
    int i,status;
    i=0;
    status=-1;
    while(key[i]!='\0')
	{
		if(!(key[i]<='z'&&key[i]>='a'))
		{
		    status=0;
			return status;
		}
		i++;
	}
    status =1;
    return 1;
}

int main()
{

    int i,status,ans=1;
    char inputString[30];
    trie_t trie;
    initialize(&trie);
    while(ans!=4)
    {
        printf("\n1. insert a string\n2. to look for suggestions\n3. to search a string\n4. to exit\nSelect Choice ");
        scanf("%d",&ans);
    switch(ans)
    {
        case 1 :
            printf("\nEnter the string\n");
            scanf("%s",inputString);
		    if(strcmp(inputString,"")==0)
			{
				printf("Empty strings are not allowed");
				break;
			}
            if(check(inputString)==0)
			{
				printf("\nOnly lower case alphabets are allowed !!\n");
				break;
			}
            insert(&trie, inputString);
            strcpy(inputString,"");
            break;
        case 2 :
            printf("\nEnter the pattern\n");
            scanf("%s",inputString);
		    if(strcmp(inputString,"")==0)
			{
				printf("Empty strings are not allowed");
				break;
			}
		    if(check(inputString)==0)
			{
				printf("\nOnly lower case alphabets are allowed !!\n");
				break;
			}
            printf("\nThe patterns are ::\n");
            suggestions(&trie,inputString);
            strcpy(inputString,"");
            break;
        case 3 :
            printf("\nPlease enter the string to be searched\n");
            scanf("%s",inputString);
		    if(strcmp(inputString,"")==0)
			{
				printf("Empty strings are not allowed");
				break;
			}
		    if(check(inputString)==0)
			{
				printf("\nOnly lower case alphabets are allowed !!\n");
				break;
			}
            status=search(&trie,inputString);
            strcpy(inputString,"");
			if(status==0)
				printf("\nThe string is not present\n");
			else
				printf("\nThe string is present\n");
            break;
        case 4 :
            return 0;
        default:
            printf("Invalid option !\n");
                 break;
        }
    }
    return 0;
}
