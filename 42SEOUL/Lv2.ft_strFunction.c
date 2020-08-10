#include "stdio.h"
#include "stdlib.h"
#include <string.h>
char* ft_strcpy(char *dest, char *src); 
char* ft_strncpy(char* dest, char* src, unsigned int n);
int ft_str_is_alpha(char* str);
int ft_str_is_numeric(char* str);
int ft_str_is_lowercase(char* str);
int ft_str_is_uppercase(char* str);
int ft_str_is_printable(char* str); 
char* ft_strupcase(char* str);
char* ft_strlowcase(char* str);
char* ft_strcapitalize(char* str);
unsigned int ft_strlcpy(char* dest, char* src, unsigned int size);
void ft_putstr_non_pintable(char* str);
void *ft_print_memory(void *addr, unsigned int size);

int main() {

	return 0;
}
char* ft_strcpy(char *dest, char *src) {
	int index = 0;
	while (src[index] != '\0') {
		dest[index] = src[index];
		index++;
	}
	if (dest[index] != '\0') dest[index] = '\0';
	return dest;
}
char* ft_strncpy(char* dest, char* src, unsigned int n) {
	int index = 0;
	while (index < n) {
		if (src[index] == '\0') {
			dest[index] = '\0';
			return dest;
		}
		dest[index] = src[index];
		index++;
	}
	return dest;
}
int ft_str_is_alpha(char* str) {
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] < 'A' || str[index] > 'z') return 0;
		index++;
	}
	return 1;
}
int ft_str_is_numeric(char* str) {
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] < '0' || str[index] > '9') return 0;
		index++;
	}
	return 1;
}


int ft_str_is_lowercase(char* str) {
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] < 'a' || str[index] > 'z') return 0;
		index++;
	}
	return 1;
}
int ft_str_is_uppercase(char* str) {
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] < 'A' || str[index] > 'Z') return 0;
		index++;
	}
	return 1;
}
int ft_str_is_printable(char* str) {
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] < 32 || str[index] == 127) return 0;
		index++;
	}
	return 1;
}
char* ft_strupcase(char* str) {
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] >= 'a' && str[index] <= 'z') {
			str[index] -= 32;
		}
		index++;
	}
	return str;
}
char* ft_strlowcase(char* str) {
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] >= 'A' && str[index] <= 'Z') {
			str[index] += 32;
		}
		index++;
	}
	return str;
}
char* ft_strcapitalize(char* str) {
	if (str[0] == '\0') return str;
	if (str[0] >= 'a' && str[0] <= 'z')  str[0] -= 32;

	int index = 1;
	while (str[index] != '\0') {
		if (( str[index-1]==' ' || str[index-1]=='-' || str[index-1]=='+' )  // 뭐가 더 있는지 모르겠음
			&& (str[index] >= 'a' && str[index] <= 'z')) {
			str[index] -= 32;
		}
		index++;
	}
	return str;
}
unsigned int ft_strlcpy(char* dest, char* src, unsigned int size) {
	int index = 0;
	while (index < size-1) {
		if (src[index] == '\0') {
			dest[index] = '\0';
			return dest;
		}
		dest[index] = src[index];
		index++;
	}
	return size-1;
}
void ft_putstr_non_pintable(char* str) {
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] <32 || str[index]==127) {
			int lastIndex = index;
			while (str[++lastIndex] != '\0');
			while (lastIndex != index) {
				str[lastIndex + 2] = str[lastIndex];
				lastIndex--;
			}
			int num = str[index];
			str[index] = '\\';
			char first_char = num/16+48;
			char last_char = num % 16 < 10 ? num%16+48 : num%16+87;

			str[index + 1] = first_char;
			str[index + 2] = last_char;
		}
		index++;
	}
}
void *ft_print_memory(void *addr, unsigned int size) {
	int a=3;
	printf("%p", &a);
}