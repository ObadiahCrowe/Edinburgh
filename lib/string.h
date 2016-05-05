#ifndef STRING_H
#define STRING_H

void write_string( int colour, const char *string )
{
    volatile char *video = (volatile char*) 0xB8000;
    while(*string != 0)
    {
        *video++ = *string++;
        *video++ = colour;
    }
}
#endif
