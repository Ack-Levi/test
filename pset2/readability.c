#include<stdio.h>
#include<math.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int count_words(char *Text);
int count_sentences(char *Text);
int count_letters(char *Text);
float coleman(float l,float s);
int main (void)
{
    string Text;
    float l,s;
    float result;
    int words;
    Text=get_string("Text:");
    words=count_words(Text);
    s=(count_sentences(Text))/(float)words *100; // converting the total sentences to the sentences per 100 words
    l=(count_letters(Text))/(float)words *100;   // converting the total letters to the letters per 100 words
    result=round(coleman(s,l));         //rounding up the result so that we get the proper grade
    printf("Grade %.2f ",result); // #yesma ali change garnu xa
    return 0;
}
int count_words(char *Text)
{
    int w=0,i=0;
    while(Text[i]!='\0')
        if(Text[i]==' '||Text[i]=='\n'||Text[i]=='\t')
        {
            w++;
        }
        i++;
    return w;
}
int count_sentences(char *Text)
{
    int s=0,i=0;
    while(Text[i]!='\0')
    {
        if(Text[i]=='.'||Text[i]==','||Text[i]=='!'||Text[i]=='?')
        {
            s++;
        }
        i++;
    }
    return s;
}

int count_letters(char *text)
{
    int i=0,l=0;
    while(text[i]!=0)
    {
        if(text[i]>='a'&text[i]<='z'||text[i]<='A'&text[i]<='Z'||text[i]!=' ')
        {
            if(text[i]!=' ')
            {
                l++;
            }
        }
        i++;
    }
    return l;
}

float coleman (float l, float s)
{
    float index;
    index = 0.0588 * l - 0.296 * s - 15.8;
    return index;
}
