/*
MIT License

Copyright (C) 2023 MingHui

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "EditString.h"

//--------------------------------------------------------------------
// Char index
//--------------------------------------------------------------------
ind_t charindex(char *dest,char c)
{
    ind_t char_i = -1;
    char *dest_c = dest;
    while(*dest_c != 0x00)
    {
        if(*dest_c == c)
        {
            char_i = dest_c - dest;
            break;
        }
        dest_c ++;
    }
    return char_i;
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// Char index (Last)
//--------------------------------------------------------------------
ind_t charindex_last(char *dest,char c)
{
    ind_t char_i = -1;
    char *dest_c = dest;
    while(*dest_c != 0x00)
    {
        if(*dest_c == c)
        {
            char_i = dest_c - dest;
        }
        dest_c ++;
    }
    return char_i;
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// String index
//--------------------------------------------------------------------
ind_t strindex(char *dest,char *str)
{
    ind_t str_i = -1;
    char *dest_c = dest;
    char *dest_cc = dest_c;
    char *str_c = str;
    if(*str == 0x00)
    {
        return str_i;
    }
    while(*dest_c != 0x00)
    {
        while(*str_c != 0x00)
        {
            if(*dest_cc != *str_c)
            {
                break;
            }
            dest_cc ++;
            str_c ++;
        }
        if(*str_c == 0x00)
        {
            str_i = dest_c - dest;
            break;
        }
        dest_c ++;
        str_c = str;
        dest_cc = dest_c;
    }
    return str_i;
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// String index (Last)
//--------------------------------------------------------------------
ind_t strindex_last(char *dest,char *str)
{
    ind_t str_i = -1;
    char *dest_c = dest;
    char *dest_cc = dest_c;
    char *str_c = str;
    if(*str == 0x00)
    {
        return str_i;
    }
    while(*dest_c != 0x00)
    {
        while(*str_c != 0x00)
        {
            if(*dest_cc != *str_c)
            {
                break;
            }
            dest_cc ++;
            str_c ++;
        }
        if(*str_c == 0x00)
        {
            str_i = dest_c - dest;
        }
        dest_c ++;
        str_c = str;
        dest_cc = dest_c;
    }
    return str_i;
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// String clear
//--------------------------------------------------------------------
void strclear(char *dest)
{
    *dest = 0x00;
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// String slice
//--------------------------------------------------------------------
void strslice(char *dest,char *sour,ind_t slis,ind_t slie)
{
    char *sour_c = sour + slis;
    char *sour_e = sour + slie;
    while(sour_c < sour_e)
    {
        *dest = *sour_c;
        dest ++;
        sour_c ++;
    }
    *dest = 0x00;
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// String replace
//--------------------------------------------------------------------
void strreplace(char *dest,char *repstr,char *str)
{
    size_t reps_l = strlen(repstr);
    size_t str_l = strlen(str);
    ind_t reps_i = strindex(dest,repstr);
    size_t char_m;
    char *char_mc;
    char *char_me;
    char temp_c;
    if(reps_i == -1)
    {
        return;
    }
    if(*str != 0x00)
    {
        if(str_l > reps_l)
        {
            char_m = str_l - reps_l;
            char_me = dest + reps_i + reps_l;
            char_mc = char_me;
            while(*char_mc != 0x00)
            {
                char_mc ++;
            }
            *(char_mc+char_m) = 0x00;
            char_mc --;
            while(char_mc >= char_me)
            {
                temp_c = *char_mc;
                *(char_mc+char_m) = temp_c;
                char_mc --;
            }
            dest += reps_i;
            while(*str != 0x00)
            {
                *dest = *str;
                str ++;
                dest ++;
            }
        }
        if(str_l < reps_l)
        {
            char_m = reps_l - str_l;
            char_mc = dest + reps_i + str_l + char_m;
            while(*char_mc != 0x00)
            {
                temp_c = *char_mc;
                *(char_mc-char_m) = temp_c;
                char_mc ++;
            }
            *(char_mc-char_m) = 0x00;
            dest += reps_i;
            while(*str != 0x00)
            {
                *dest = *str;
                str ++;
                dest ++;
            }
        }
        if(str_l == reps_l)
        {
            dest += reps_i;
            while(*str != 0x00)
            {
                *dest = *str;
                str ++;
                dest ++;
            }
        }
    }
    else
    {
        char_mc = dest + reps_i + reps_l;
        while(*char_mc != 0x00)
        {
            temp_c = *char_mc;
            *(char_mc-reps_l) = temp_c;
            char_mc ++;
        }
        *(char_mc-reps_l) = 0x00;
    }
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// String insert
//--------------------------------------------------------------------
void strinsert(char *dest,ind_t insi,char *sour)
{
    size_t sour_l = strlen(sour);
    char *char_me = dest + insi;
    char *char_mc = char_me;
    char temp_c;
    while(*char_mc != 0x00)
    {
        char_mc ++;
    }
    *(char_mc+sour_l) = 0x00;
    char_mc --;
    while(char_mc >= char_me)
    {
        temp_c = *char_mc;
        *(char_mc+sour_l) = temp_c;
        char_mc --;
    }
    dest += insi;
    while(*sour != 0x00)
    {
        *dest = *sour;
        sour ++;
        dest ++;
    }
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// String trim
//--------------------------------------------------------------------
void strtrim(char *dest,ind_t trii,ind_t tril)
{
    char *char_mc = dest + trii + tril;
    char temp_c;
    while(*char_mc != 0x00)
    {
        temp_c = *char_mc;
        *(char_mc-tril) = temp_c;
        char_mc ++;
    }
    *(char_mc-tril) = 0x00;
}
//--------------------------------------------------------------------