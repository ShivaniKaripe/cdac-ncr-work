#include <stdio.h>

char* stok(char* teststr, char ch);

int main() {
char mystr[] = "Himy*:name:is:bozo:";
//char mystr[] = ":*&Fight!:the^%:^^&)Man\n";
char *finalstr;
finalstr = stok(mystr, ':');
printf("%s\n", finalstr);
while(finalstr!=NULL){
finalstr = stok(NULL, ':');
if(finalstr) printf("%s\n", finalstr);
}
return 0;
}


char* stok(char* teststr, char ch) {
char *dummystr=NULL;
char *start=NULL;
char *end=NULL;
char nullch = '\0';
char* address_of_null=&nullch;
static char* nexttok;

if(teststr!=NULL) {
dummystr = teststr;
} else {
if(*nexttok=='\0') return NULL;
dummystr = nexttok;
}


while(dummystr!=NULL) {
//empty string
if(*dummystr=='\0') break;
if(*dummystr!=ch){
if(!start) start = dummystr;
dummystr++;
//to handle the case where the delimiter is not at the end of the string.
if(*dummystr=='\0') {
nexttok = dummystr;
break;
}
}else{
if(start) {
end = dummystr;
nexttok = dummystr+1;
*end = *address_of_null;
break;
} else {
dummystr++;
}
}
}
return start;
}