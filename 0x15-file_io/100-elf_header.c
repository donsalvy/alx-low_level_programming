#ifndef ELF_HEADER_H
#define ELF_HEADER_H

#include <elf.h>

#define MY_ELF_NIDENT 16

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * check_elf - This code checks if a file is an ELF file.
 * @e_ident: The pointer to an array containing the ELF magic numbers.
 *
 * Description: When the file is not an ELF file - exit code 98.
 */

void check_elf(unsigned char *e_ident)
{
int annex;

for (annex = 0; annex < 4; annex++)
{
if (e_ident[annex] != 127 &&
e_ident[annex] != 'E' &&
e_ident[annex] != 'L' &&
e_ident[annex] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}
/**
 * print_magic - This code prints the magic numbers of an ELF header.
 * @e_ident: The pointer to array containing the ELF magic numbers.
 *
 * Description: This magic numbers are separated by spaces.
 */

void print_magic(unsigned char *e_ident)
{
int annex;

for (annex = 0; annex < EI_NIDENT; annex++)
{
printf("%02x", e_ident[annex]);

if (annex == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}
/**
 * main - This code displays information contained in the
 * ELF header at the start of ELF file.
 * @argc: Number of arguments supplied to the program.
 * @argv: The  array of pointers to arguments.
 *
 * Return: 0 to be success.
 *
 * Description: When the file is not an ELF File or
 * the function fails - exit code 98.
 */


int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int o, r;

o = open(argv[1], O_RDONLY);
if (o == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf(o);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
r = read(o, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
close_elf(o);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}
check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);
print_class(header->e_ident);
print_data(header->e_ident);
print_version(header->e_ident);
print_osabi(header->e_ident);
print_abi(header->e_ident);
print_type(header->e_type, header->e_ident);
print_entry(header->e_entry, header->e_ident);

free(header);
close_elf(o);
return (0);
}

