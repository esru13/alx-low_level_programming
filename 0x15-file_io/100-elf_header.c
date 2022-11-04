#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * closes_file - Closes a file.
 * @fil: ELF file.
 * Return: none.
 */
void closes_file(int fil)
{
	if (close(fil) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", fil);
		exit(98);
	}
}
/**
 * check_file - Checks if file is ELF.
 * @rem: Remaining file content.
 * Return: none.
 */
void check_file(unsigned char *rem)
{
	int i;

	for (i = 0; i < 4; i++)
		if (rem[i] != 127 && rem[i] != 'E' &&
				rem[i] != 'L' && rem[i] != 'F')
			dprintf(STDERR_FILENO, "Error: Not ELF file\n"),
				exit(98);
}
/**
 * print_magic - Prints magic of ELF file.
 * @magic: ELF magic numbers.
 * Return: none.
 */
void print_magic(unsigned char *magic)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", magic[i]);
		i == EI_NIDENT - 1 ? printf("\n") : printf(" ");
	}
}
/**
 * print_class - Printf ELF class.
 * @class: ELF file.
 * Return: none.
 */
void print_class(unsigned char *class)
{
	printf("  Class:                             ");

	switch (class[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", class[EI_CLASS]);
	}
}
/**
 * print_data - Print ELF data file.
 * @data: ELF file.
 * Return: none.
 */
void print_data(unsigned char *data)
{
	printf("  Data:                              ");

	switch (data[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;

