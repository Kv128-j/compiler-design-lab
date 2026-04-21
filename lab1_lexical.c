#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *word) {
    char *keywords[] = {"int","float","if","else","while","return"};
    for(int i=0;i<6;i++)
        if(strcmp(word, keywords[i])==0) return 1;
    return 0;
}

int main() {
    char str[100], word[50];
    printf("Enter code: ");
    fgets(str,100,stdin);

    int i=0,j=0;
    while(str[i]!='\0') {
        if(isalnum(str[i])) {
            word[j++]=str[i];
        } else {
            if(j>0) {
                word[j]='\0';
                if(isKeyword(word))
                    printf("%s -> Keyword\n",word);
                else
                    printf("%s -> Identifier\n",word);
                j=0;
            }
            if(str[i]=='+'||str[i]=='=')
                printf("%c -> Operator\n",str[i]);
        }
        i++;
    }
}
