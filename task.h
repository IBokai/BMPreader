int checkformat(FILE *file);   // returns 0 if .bmp and INCORRECTFORMAT if not
int printBMP(const char *src); // handles errors NOSUCHFILE and INCORRECTFORMAT and prints BMP file info if no errors occured
