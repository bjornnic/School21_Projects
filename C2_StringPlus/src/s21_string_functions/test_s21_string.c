#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memcmp_t1_equal_str) {
  char s1[] = "test";
  char s2[] = "test";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_t2_diff_str) {
  char s1[] = "abc";
  char s2[] = "xyz";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_t3_partial_match) {
  char s1[] = "im super groot";
  char s2[] = "im super aboba";
  s21_size_t n = 9;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_t4_zero_length) {
  char s1[] = "text";
  char s2[] = "text";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_t5_diff_length) {
  char s1[] = "short";
  char s2[] = "shorter";
  s21_size_t n = 6;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_t6_with_null) {
  char s1[] = "abc\0def";
  char s2[] = "abc\0xyz";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_t7_empty_str) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_t8_large) {
  char s1[1000];
  char s2[1000];
  memset(s1, 'x', 1000);
  memset(s2, 'x', 1000);
  s21_size_t n = 1000;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcmp_t9_single) {
  char s1[] = "a";
  char s2[] = "b";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_memcmp(s1, s2, n), memcmp(s1, s2, n));
}
END_TEST

START_TEST(memcpy_t1_standart) {
  char src[] = "text";
  char dest[5] = {0};
  char exp[5] = {0};
  s21_size_t n = 4;
  s21_memcpy(dest, src, n);
  memcpy(exp, src, n);
  ck_assert_mem_eq(dest, exp, n);
}
END_TEST

START_TEST(memcpy_t2_zero_n) {
  char src[] = "text";
  char dest[5] = {0};
  char exp[5] = {0};
  s21_size_t n = 0;
  s21_memcpy(dest, src, n);
  memcpy(exp, src, n);
  ck_assert_mem_eq(dest, exp, 5);
}
END_TEST

START_TEST(memcpy_t3_partial_copy) {
  char src[] = "text for copy";
  char dest[10] = {0};
  char exp[10] = {0};
  s21_size_t n = 8;
  s21_memcpy(dest, src, n);
  memcpy(exp, src, n);
  ck_assert_mem_eq(dest, exp, n);
}
END_TEST

START_TEST(memcpy_t4_large) {
  char src[1000];
  char dest[1000] = {0};
  char exp[1000] = {0};
  s21_size_t n = 1000;
  memset(src, 'x', 1000);
  s21_memcpy(dest, src, n);
  memcpy(exp, src, n);
  ck_assert_mem_eq(dest, exp, n);
}
END_TEST

START_TEST(memcpy_t5_with_null) {
  char src[] = "abc\0def";
  char dest[10] = {0};
  char exp[10] = {0};
  s21_size_t n = 8;
  s21_memcpy(dest, src, n);
  memcpy(exp, src, n);
  ck_assert_mem_eq(dest, exp, 8);
}
END_TEST

START_TEST(memcpy_t6_overlapping) {
  char src[] = "1234567890";
  char dest[20] = {0};
  char exp[20] = {0};
  s21_size_t n = 5;
  strcpy(dest, src);
  strcpy(exp, src);
  s21_memcpy(dest + 2, src, n);
  memcpy(exp + 2, src, n);
  ck_assert_mem_eq(dest, exp, 10);
}
END_TEST

START_TEST(memcpy_t7_empty_str) {
  char src[] = "";
  char dest[5] = {0};
  char exp[5] = {0};
  s21_size_t n = 1;
  s21_memcpy(dest, src, n);
  memcpy(exp, src, n);
  ck_assert_mem_eq(dest, exp, n);
}
END_TEST

START_TEST(memcpy_t8_single) {
  char src[] = "a";
  char dest[1] = {0};
  char exp[1] = {0};
  s21_size_t n = 1;
  s21_memcpy(dest, src, n);
  memcpy(exp, src, n);
  ck_assert_mem_eq(dest, exp, n);
}
END_TEST

START_TEST(memchr_t1_basic) {
  char s[] = "text";
  int x = 'e';
  s21_size_t n = 4;
  ck_assert_ptr_eq(s21_memchr(s, x, n), memchr(s, x, n));
}
END_TEST

START_TEST(memchr_t2_not_found) {
  char s[] = "text";
  int x = 'z';
  s21_size_t n = 4;
  ck_assert_ptr_eq(s21_memchr(s, x, n), memchr(s, x, n));
}
END_TEST

START_TEST(memchr_t3_multiple) {
  char s[] = "banana";
  int x = 'a';
  s21_size_t n = 6;
  ck_assert_ptr_eq(s21_memchr(s, x, n), memchr(s, x, n));
}
END_TEST

START_TEST(memchr_t4_with_null) {
  char s[] = "abc\0def";
  int x = '\0';
  s21_size_t n = 8;
  ck_assert_ptr_eq(s21_memchr(s, x, n), memchr(s, x, n));
}
END_TEST

START_TEST(memchr_t5_empty) {
  char s[] = "";
  int x = 'x';
  s21_size_t n = 1;
  ck_assert_ptr_eq(s21_memchr(s, x, n), memchr(s, x, n));
}
END_TEST

START_TEST(memchr_t6_single) {
  char s[] = "a";
  int x = 'a';
  s21_size_t n = 1;
  ck_assert_ptr_eq(s21_memchr(s, x, n), memchr(s, x, n));
}
END_TEST

START_TEST(memset_t1_basic) {
  char res[] = "text";
  char exp[] = "text";
  int x = 'x';
  s21_size_t n = 2;
  s21_memset(res, x, n);
  memset(exp, x, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(memset_t2_full) {
  char res[] = "text";
  char exp[] = "text";
  int x = 'x';
  s21_size_t n = 4;
  s21_memset(res, x, n);
  memset(exp, x, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(memset_t3_zero_fill) {
  char res[] = "text";
  char exp[] = "text";
  int x = 0;
  s21_size_t n = 4;
  s21_memset(res, x, n);
  memset(exp, x, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(memset_t4_zero_n) {
  char res[] = "text";
  char exp[] = "text";
  int x = 'x';
  s21_size_t n = 0;
  s21_memset(res, x, n);
  memset(exp, x, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(memset_t5_large) {
  char res[1000] = {0};
  char exp[1000] = {0};
  int x = 'x';
  s21_size_t n = 999;
  s21_memset(res, x, n);
  memset(exp, x, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(memset_t6_single) {
  char res[] = "a";
  char exp[] = "a";
  int x = 'x';
  s21_size_t n = 1;
  s21_memset(res, x, n);
  memset(exp, x, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncat_t1_basic) {
  char res[20] = "text";
  char exp[20] = "text";
  char src[] = " privet";
  s21_size_t n = 7;
  s21_strncat(res, src, n);
  strncat(exp, src, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncat_t2_partial_copy) {
  char res[20] = "text";
  char exp[20] = "text";
  char src[] = " privet";
  s21_size_t n = 4;
  s21_strncat(res, src, n);
  strncat(exp, src, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncat_t3_empty) {
  char res[10] = "";
  char exp[10] = "";
  char src[] = "text";
  s21_size_t n = 4;
  s21_strncat(res, src, n);
  strncat(exp, src, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncat_t4_empty_src) {
  char res[] = "text";
  char exp[] = "text";
  char src[] = "";
  s21_size_t n = 4;
  s21_strncat(res, src, n);
  strncat(exp, src, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncat_t5_zero_n) {
  char res[] = "text";
  char exp[] = "text";
  char src[] = " privet";
  s21_size_t n = 0;
  s21_strncat(res, src, n);
  strncat(exp, src, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncat_t6_big_n) {
  char res[100] = "text";
  char exp[100] = "text";
  char src[] = " privet vam vsem rebyata";
  s21_size_t n = 50;
  s21_strncat(res, src, n);
  strncat(exp, src, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncat_t7_big_dest) {
  char res[100] = "text privet vam vsem";
  char exp[100] = "text privet vam vsem";
  char src[] = " rebyata";
  s21_size_t n = 8;
  s21_strncat(res, src, n);
  strncat(exp, src, n);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strchr_t1_basic) {
  char str[] = "test text";
  int c = 's';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_t2_first) {
  char str[] = "test text";
  int c = 't';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_t3_last) {
  char str[] = "test textr";
  int c = 'r';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_t4_not_found) {
  char str[] = "test text";
  int c = 'z';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_t5_null) {
  char str[] = "test text";
  int c = '\0';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_t6_empty_str) {
  char str[] = "";
  int c = 'x';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_t7_multiple) {
  char str[] = "banana";
  int c = 'a';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_t8_not_found_large) {
  char str[1000];
  memset(str, 'x', 999);
  str[999] = '\0';
  int c = 's';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strncmp_t1_basic) {
  char s1[] = "hello";
  char s2[] = "hello";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_t2_diff_str) {
  char s1[] = "hello";
  char s2[] = "world";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_t3_partial_match) {
  char s1[] = "hello";
  char s2[] = "helium";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_t4_empty_str) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_t5_empty_first_str) {
  char s1[] = "";
  char s2[] = "hello";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_t6_empty_second_str) {
  char s1[] = "hello";
  char s2[] = "";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_t7_zero_n) {
  char s1[] = "hello";
  char s2[] = "world";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_t8_diff_length) {
  char s1[] = "short";
  char s2[] = "shorter";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncmp_t9_big_n) {
  const char *s1 = "short";
  const char *s2 = "shorter";
  s21_size_t n = 50;
  n = (n > strlen(s1)) ? strlen(s1) : n;
  ck_assert_int_eq(s21_strncmp(s1, s2, n), strncmp(s1, s2, n));
}
END_TEST

START_TEST(strncpy_t1_basic) {
  char src[] = "hello";
  char res[10] = {0};
  char exp[10] = {0};
  s21_size_t n = 5;
  s21_strncpy(res, src, n);
  strncpy(exp, src, n);
  ck_assert_str_eq(res, exp);
  ;
}
END_TEST

START_TEST(strncpy_t2_partial) {
  char src[] = "hello";
  char res[10] = {0};
  char exp[10] = {0};
  s21_size_t n = 3;
  s21_strncpy(res, src, n);
  strncpy(exp, src, n);
  ck_assert_str_eq(res, exp);
  ;
}
END_TEST

START_TEST(strncpy_t3_with_null) {
  char src[] = "hello";
  char res[10] = {0};
  char exp[10] = {0};
  s21_size_t n = 8;
  s21_strncpy(res, src, n);
  strncpy(exp, src, n);
  ck_assert_str_eq(res, exp);
  ;
}
END_TEST

START_TEST(strncpy_t4_epmty_str) {
  char src[] = "";
  char res[10] = {0};
  char exp[10] = {0};
  s21_size_t n = 5;
  s21_strncpy(res, src, n);
  strncpy(exp, src, n);
  ck_assert_str_eq(res, exp);
  ;
}
END_TEST

START_TEST(strncpy_t5_empty_str_zero_n) {
  char src[] = "";
  char res[10] = {0};
  char exp[10] = {0};
  s21_size_t n = 0;
  s21_strncpy(res, src, n);
  strncpy(exp, src, n);
  ck_assert_str_eq(res, exp);
  ;
}
END_TEST

START_TEST(strncpy_t6_big_n) {
  char src[] = "hello";
  char res[20] = {0};
  char exp[20] = {0};
  s21_size_t n = 20;
  s21_strncpy(res, src, n);
  strncpy(exp, src, n);
  ck_assert_str_eq(res, exp);
  ;
}
END_TEST

START_TEST(strncpy_t7_overwrite) {
  char src[] = "overwrite";
  char res[20] = "initial";
  char exp[20] = "initial";
  s21_size_t n = 9;
  s21_strncpy(res, src, n);
  strncpy(exp, src, n);
  ck_assert_str_eq(res, exp);
  ;
}
END_TEST

START_TEST(strcspn_t1_basic) {
  char s1[] = "hello world";
  char s2[] = " ";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_t2_no_match) {
  char s1[] = "hello";
  char s2[] = "xyz";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_t3_empty_str1) {
  char s1[] = "";
  char s2[] = "z";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_t4_empty_str2) {
  char s1[] = "hello";
  char s2[] = "";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_t5_match_at_end) {
  char s1[] = "hello";
  char s2[] = "o";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_t6_match_at_start) {
  char s1[] = "hello";
  char s2[] = "h";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_t7_multiple) {
  char s1[] = "hello";
  char s2[] = "aeiou";
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_t8_big_str_no_match) {
  char s1[1000];
  char s2[] = "abc";
  memset(s1, 'x', 999);
  s1[999] = '\0';
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_t9_big_str_with_match) {
  char s1[1000];
  char s2[] = "z";
  memset(s1, 'x', 999);
  s1[500] = 'z';
  s1[999] = '\0';
  ck_assert_int_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strerror_t1_valid_codes) {
  for (int i = 1; i < 107; ++i) {
    char *got = s21_strerror(i);
    char *exp = strerror(i);
    ck_assert_str_eq(got, exp);
  }
}
END_TEST

START_TEST(strerror_t2_negative_code) {
  int error_code = -100;
  char *got = s21_strerror(error_code);
  char *exp = strerror(error_code);
  ck_assert_str_eq(got, exp);
}
END_TEST

START_TEST(strerror_t3_big_code) {
  int error_code = 10000;
  char *got = s21_strerror(error_code);
  char *exp = strerror(error_code);
  ck_assert_str_eq(got, exp);
}
END_TEST

START_TEST(strerror_t4_zero_code) {
  int error_code = 0;
  char *got = s21_strerror(error_code);
  char *exp = strerror(error_code);
  ck_assert_str_eq(got, exp);
}
END_TEST

START_TEST(strlen_t1_basic) {
  char str[] = "hello";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_t2_empty) {
  char str[] = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_t3_with_space) {
  char str[] = "hello world";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_t4_with_null) {
  char str[] = "hello\0world";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_t5_big) {
  char str[1000];
  memset(str, 'x', 999);
  str[999] = '\0';
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_t6_with_null) {
  char str[] = "\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_t7_with_special) {
  char str[] = "@#$%^&*()_+";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_t8_russian) {
  char str[] = "Приветик мир";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_t9_numbers) {
  char str[] = "1234567890";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strpbrk_t1_basic) {
  char s1[] = "hello world";
  char s2[] = "ol";
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_t2_no_match) {
  char s1[] = "hello";
  char s2[] = "abc";
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_t3_empty_str1) {
  char s1[] = "";
  char s2[] = "x";
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_t4_empty_str2) {
  char s1[] = "hello";
  char s2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_t5_match_at_start) {
  char s1[] = "hello";
  char s2[] = "h";
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_t6_match_at_end) {
  char s1[] = "hello";
  char s2[] = "o";
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_t7_multiple) {
  char s1[] = "abcdefg";
  char s2[] = "dga";
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_t8_big_str) {
  char s1[1000];
  char s2[] = "z";
  memset(s1, 'x', 999);
  s1[500] = 'z';
  s1[999] = '\0';
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_t9_big_str_no_match) {
  char s1[1000];
  char s2[] = "abc";
  memset(s1, 'x', 999);
  s1[999] = '\0';
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_t10_russian) {
  char s1[] = "Привет мир";
  char s2[] = "т";
  ck_assert_pstr_eq(s21_strpbrk(s1, s2), strpbrk(s1, s2));
}
END_TEST

START_TEST(strrchr_t1_basic) {
  char str[] = "hello world";
  char c = 'o';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_t2_no_match) {
  char str[] = "hello world";
  char c = 'z';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_t3_empty_str) {
  char str[] = "";
  char c = 'z';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_t4_null) {
  char str[] = "hello world";
  char c = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_t5_multiple) {
  char str[] = "banana";
  char c = 'a';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_t6_match_at_start) {
  char str[] = "hello";
  char c = 'h';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_t7_match_at_end) {
  char str[] = "hello";
  char c = 'o';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_t8_big_str) {
  char str[1000];
  memset(str, 'x', 999);
  str[998] = 'z';
  str[999] = '\0';
  char c = 'z';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strstr_t1_basic) {
  char h[] = "hello world";
  char n[] = "";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t2_no_match) {
  char h[] = "hello world";
  char n[] = "solar";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t3_empty_h) {
  char h[] = "";
  char n[] = "world";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t4_emty_n) {
  char h[] = "hello world";
  char n[] = "";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t5_full_match) {
  char h[] = "hello";
  char n[] = "hello";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t6_match_at_start) {
  char h[] = "hello world";
  char n[] = "hell";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t7_match_at_end) {
  char h[] = "hello world";
  char n[] = "ld";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t8_big_h) {
  char h[1000];
  memset(h, 'x', 999);
  h[999] = '\0';
  h[500] = 'r';
  h[501] = 'a';
  char n[] = "ra";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t9_big_h_no_match) {
  char h[1000];
  memset(h, 'x', 999);
  h[999] = '\0';
  char n[] = "z";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t10_n_bigger_h) {
  char h[] = "abc";
  char n[] = "abcdef";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strstr_t11_russian) {
  char h[] = "привет мир";
  char n[] = "мир";
  ck_assert_pstr_eq(s21_strstr(h, n), strstr(h, n));
}
END_TEST

START_TEST(strtok_t1_basic) {
  char str[] = "hello world";
  char *delim = " ";

  char *token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "hello");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_str_eq(token, "world");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_ptr_eq(token, s21_NULL);
}
END_TEST

START_TEST(strtok_t2_no_delimiter) {
  char str[] = "helloworld";
  char *delim = " ";

  char *token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "helloworld");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_ptr_eq(token, s21_NULL);
}
END_TEST

START_TEST(strtok_t3_multiple_delimiters) {
  char str[] = "hello,,world,,again";
  char *delim = ",";

  char *token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "hello");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_str_eq(token, "world");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_str_eq(token, "again");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_ptr_eq(token, s21_NULL);
}
END_TEST

START_TEST(strtok_t4_multiple_consecutive_delimiters) {
  char str[] = "hello,,world,,again";
  char *delim = ",";

  char *token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "hello");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_str_eq(token, "world");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_str_eq(token, "again");

  token = s21_strtok(s21_NULL, delim);
  ck_assert_ptr_eq(token, s21_NULL);
}
END_TEST

START_TEST(strtok_t5_empty_string) {
  char str[] = "";
  char *delim = " ";

  char *token = s21_strtok(str, delim);
  ck_assert_ptr_eq(token, s21_NULL);
}
END_TEST

START_TEST(strtok_t6_null_string) {
  char *str = s21_NULL;
  char *delim = " ";

  char *token = s21_strtok(str, delim);
  ck_assert_ptr_eq(token, s21_NULL);
}
END_TEST

START_TEST(sprintf_t1_char_simple) {
  char buffer1[100];
  char buffer2[100];
  char ch = 'A';

  s21_sprintf(buffer1, "%c", ch);
  sprintf(buffer2, "%c", ch);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t2_char_with_width) {
  char buffer1[100];
  char buffer2[100];
  char ch = 'B';

  s21_sprintf(buffer1, "%5c", ch);
  sprintf(buffer2, "%5c", ch);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t3_char_null) {
  char buffer1[100];
  char buffer2[100];
  char ch = '\0';

  s21_sprintf(buffer1, "%c", ch);
  sprintf(buffer2, "%c", ch);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t4_int_positive) {
  char buffer1[100];
  char buffer2[100];
  int value = 123;

  s21_sprintf(buffer1, "%d", value);
  sprintf(buffer2, "%d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t5_int_negative) {
  char buffer1[100];
  char buffer2[100];
  int value = -456;

  s21_sprintf(buffer1, "%d", value);
  sprintf(buffer2, "%d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t6_int_with_width) {
  char buffer1[100];
  char buffer2[100];
  int value = 42;

  s21_sprintf(buffer1, "%5d", value);
  sprintf(buffer2, "%5d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t7_int_with_flags) {
  char buffer1[100];
  char buffer2[100];
  int value = 789;

  s21_sprintf(buffer1, "%+d", value);
  sprintf(buffer2, "%+d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t8_int_zero) {
  char buffer1[100];
  char buffer2[100];
  int value = 0;

  s21_sprintf(buffer1, "%d", value);
  sprintf(buffer2, "%d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t9_int_min) {
  char buffer1[100];
  char buffer2[100];
  int value = INT_MIN;

  s21_sprintf(buffer1, "%d", value);
  sprintf(buffer2, "%d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t10_int_max) {
  char buffer1[100];
  char buffer2[100];
  int value = INT_MAX;

  s21_sprintf(buffer1, "%d", value);
  sprintf(buffer2, "%d", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t11_float_simple) {
  char buffer1[100];
  char buffer2[100];
  double value = 3.14159;

  s21_sprintf(buffer1, "%.2f", value);
  sprintf(buffer2, "%.2f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t12_float_with_width) {
  char buffer1[100];
  char buffer2[100];
  double value = 2.71828;

  s21_sprintf(buffer1, "%10.4f", value);
  sprintf(buffer2, "%10.4f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t13_float_zero) {
  char buffer1[100];
  char buffer2[100];
  double value = 0.0;

  s21_sprintf(buffer1, "%.1f", value);
  sprintf(buffer2, "%.1f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t14_float_negative) {
  char buffer1[100];
  char buffer2[100];
  double value = -123.456;

  s21_sprintf(buffer1, "%.3f", value);
  sprintf(buffer2, "%.3f", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t15_string_simple) {
  char buffer1[100];
  char buffer2[100];
  const char *str = "Hello, world!";

  s21_sprintf(buffer1, "%s", str);
  sprintf(buffer2, "%s", str);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t16_string_with_width) {
  char buffer1[100];
  char buffer2[100];
  const char *str = "Hi";

  s21_sprintf(buffer1, "%10s", str);
  sprintf(buffer2, "%10s", str);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t17_string_with_precision) {
  char buffer1[100];
  char buffer2[100];
  const char *str = "Truncated";

  s21_sprintf(buffer1, "%-6.4s", str);
  sprintf(buffer2, "%-6.4s", str);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t18_string_empty) {
  char buffer1[100];
  char buffer2[100];
  const char *str = "";

  s21_sprintf(buffer1, "%s", str);
  sprintf(buffer2, "%s", str);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t19_unsigned_simple) {
  char buffer1[100];
  char buffer2[100];
  unsigned int value = 4294967295U;

  s21_sprintf(buffer1, "%u", value);
  sprintf(buffer2, "%u", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t20_unsigned_zero) {
  char buffer1[100];
  char buffer2[100];
  unsigned int value = 0;

  s21_sprintf(buffer1, "%u", value);
  sprintf(buffer2, "%u", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t21_unsigned_max) {
  char buffer1[100];
  char buffer2[100];
  unsigned int value = UINT_MAX;

  s21_sprintf(buffer1, "%u", value);
  sprintf(buffer2, "%u", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t22_percent) {
  char buffer1[100];
  char buffer2[100];

  s21_sprintf(buffer1, "%%");
  sprintf(buffer2, "%%");

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t23_percent_repeated) {
  char buffer1[100];
  char buffer2[100];

  s21_sprintf(buffer1, "%%%%%%");
  sprintf(buffer2, "%%%%%%");

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t24_short_int) {
  char buffer1[100];
  char buffer2[100];
  short unsigned value = 123;

  s21_sprintf(buffer1, "%hd", value);
  sprintf(buffer2, "%hd", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t25_long_int) {
  char buffer1[100];
  char buffer2[100];
  long value = 123456789L;

  s21_sprintf(buffer1, "%ld", value);
  sprintf(buffer2, "%ld", value);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t26_x_with_flag_hash) {
  char buffer1[128];
  char buffer2[128];
  unsigned int num = 255;

  s21_sprintf(buffer1, "%#x", num);
  sprintf(buffer2, "%#x", num);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t27_X_with_flag_hash) {
  char buffer1[128];
  char buffer2[128];
  unsigned int num = 4096;

  s21_sprintf(buffer1, "%#X", num);
  sprintf(buffer2, "%#X", num);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t28_o_with_flag_hash) {
  char buffer1[128];
  char buffer2[128];
  unsigned int num = 511;

  s21_sprintf(buffer1, "%#o", num);
  sprintf(buffer2, "%#o", num);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t29_flag_zero_negative_number) {
  char buffer1[128];
  char buffer2[128];
  int num = -42;

  s21_sprintf(buffer1, "%05d", num);
  sprintf(buffer2, "%05d", num);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(sprintf_t30_length_L_precision) {
  char buffer1[128];
  char buffer2[128];
  long double num = 12345.6789L;

  s21_sprintf(buffer1, "%.2Lf", num);
  sprintf(buffer2, "%.2Lf", num);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(insert_t1_simple_case) {
  const char *src = "Hello, world!";
  const char *str = "beautiful ";
  s21_size_t start_index = 7;

  char *result = s21_insert(src, str, start_index);
  const char *expected = "Hello, beautiful world!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(insert_t2_beginning) {
  const char *src = "world!";
  const char *str = "Hello, ";
  s21_size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  const char *expected = "Hello, world!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(insert_t3_end) {
  const char *src = "Hello, ";
  const char *str = "world!";
  s21_size_t start_index = s21_strlen(src);

  char *result = s21_insert(src, str, start_index);
  const char *expected = "Hello, world!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(insert_t4_empty_src) {
  const char *src = "";
  const char *str = "Hello, world!";
  s21_size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  const char *expected = "Hello, world!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(insert_t5_empty_str) {
  const char *src = "Hello, world!";
  const char *str = "";
  s21_size_t start_index = 5;

  char *result = s21_insert(src, str, start_index);
  const char *expected = "Hello, world!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(insert_t6_empty_both) {
  const char *src = "";
  const char *str = "";
  s21_size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  const char *expected = "";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(insert_t7_null_src) {
  const char *src = s21_NULL;
  const char *str = "Hello, world!";
  s21_size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(insert_t8_null_str) {
  const char *src = "Hello, world!";
  const char *str = s21_NULL;
  s21_size_t start_index = 5;

  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(insert_t9_out_of_bounds) {
  const char *src = "Hello, world!";
  const char *str = "test";
  s21_size_t start_index = 50;

  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(trim_t1_simple_case) {
  const char src[] = "  Hello, world!  ";
  const char trim_chars[] = " ";

  char *result = s21_trim(src, trim_chars);
  const char expected[] = "Hello, world!";

  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(trim_t2_multiple_chars) {
  const char *src = "!!Hello, world!!!";
  const char *trim_chars = "*!";

  char *result = s21_trim(src, trim_chars);
  const char *expected = "Hello, world";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(trim_t3_empty_string) {
  const char *src = "      ";
  const char *trim_chars = " ";

  char *result = s21_trim(src, trim_chars);
  const char *expected = "";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(trim_t4_no_trim) {
  const char *src = "Hello, world!";
  const char *trim_chars = " ";

  char *result = s21_trim(src, trim_chars);
  const char *expected = "Hello, world!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(trim_t5_empty_src) {
  const char *src = "";
  const char *trim_chars = " ";

  char *result = s21_trim(src, trim_chars);
  const char *expected = "";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(trim_t6_empty_trim_chars) {
  const char *src = "Hello, world!";
  const char *trim_chars = "";

  char *result = s21_trim(src, trim_chars);
  const char *expected = "Hello, world!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(trim_t7_null_src) {
  const char *src = s21_NULL;
  const char *trim_chars = " ";

  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(trim_t8_null_trim_chars) {
  const char *src = "Hello, world!";
  const char *trim_chars = s21_NULL;

  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(trim_t9_invalid_trim_chars) {
  const char *src = "Hello, world!";
  const char *trim_chars = s21_NULL;

  char *result = s21_trim(src, trim_chars);
  ck_assert_ptr_null(result);
}
END_TEST

START_TEST(trim_t10_all_chars) {
  const char *src = "*****";
  const char *trim_chars = "*";

  char *result = s21_trim(src, trim_chars);
  const char *expected = "";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(trim_t11_trim_multiple_chars) {
  const char *src = "abcabcabc";
  const char *trim_chars = "abc";

  char *result = s21_trim(src, trim_chars);
  const char *expected = "";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(trim_t12_trim_partial_match) {
  const char *src = "abcxyzabc";
  const char *trim_chars = "abc";

  char *result = s21_trim(src, trim_chars);
  const char *expected = "xyz";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_lower_t1_simple) {
  const char *src = "Hello, World!";
  char *result = s21_to_lower(src);
  const char *expected = "hello, world!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_lower_t2_all_upper) {
  const char *src = "HELLO";
  char *result = s21_to_lower(src);
  const char *expected = "hello";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_lower_t3_mixed) {
  const char *src = "HeLLo WoRLD";
  char *result = s21_to_lower(src);
  const char *expected = "hello world";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_lower_t4_no_change) {
  const char *src = "hello, world!";
  char *result = s21_to_lower(src);
  const char *expected = "hello, world!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_lower_t5_empty_str) {
  const char *src = "";
  char *result = s21_to_lower(src);
  const char *expected = "";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_lower_t6_special_characters) {
  const char *src = "12345!@#$5%^&*()";
  char *result = s21_to_lower(src);
  const char *expected = "12345!@#$5%^&*()";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_upper_t1_simple) {
  const char *src = "hello, world!";
  char *result = s21_to_upper(src);
  const char *expected = "HELLO, WORLD!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_upper_t2_all_lower) {
  const char *src = "hello";
  char *result = s21_to_upper(src);
  const char *expected = "HELLO";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_upper_t3_mixed) {
  const char *src = "HeLLo WoRLD";
  char *result = s21_to_upper(src);
  const char *expected = "HELLO WORLD";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_upper_t4_no_change) {
  const char *src = "HELLO, WORLD!";
  char *result = s21_to_upper(src);
  const char *expected = "HELLO, WORLD!";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_upper_t5_empty_string) {
  const char *src = "";
  char *result = s21_to_upper(src);
  const char *expected = "";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

START_TEST(to_upper_t6_special_characters) {
  const char *src = "12345!@#$%^&*()";
  char *result = (char *)s21_to_upper(src);
  const char *expected = "12345!@#$%^&*()";

  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, expected);

  free(result);
}
END_TEST

Suite *suite_string() {
  Suite *s = suite_create("string_suite");
  TCase *tcase_core = tcase_create("string_tcase");

  tcase_add_test(tcase_core, memcmp_t1_equal_str);
  tcase_add_test(tcase_core, memcmp_t2_diff_str);
  tcase_add_test(tcase_core, memcmp_t3_partial_match);
  tcase_add_test(tcase_core, memcmp_t4_zero_length);
  tcase_add_test(tcase_core, memcmp_t5_diff_length);
  tcase_add_test(tcase_core, memcmp_t6_with_null);
  tcase_add_test(tcase_core, memcmp_t7_empty_str);
  tcase_add_test(tcase_core, memcmp_t8_large);
  tcase_add_test(tcase_core, memcmp_t9_single);

  tcase_add_test(tcase_core, memcpy_t1_standart);
  tcase_add_test(tcase_core, memcpy_t2_zero_n);
  tcase_add_test(tcase_core, memcpy_t3_partial_copy);
  tcase_add_test(tcase_core, memcpy_t4_large);
  tcase_add_test(tcase_core, memcpy_t5_with_null);
  tcase_add_test(tcase_core, memcpy_t6_overlapping);
  tcase_add_test(tcase_core, memcpy_t7_empty_str);
  tcase_add_test(tcase_core, memcpy_t8_single);

  tcase_add_test(tcase_core, memchr_t1_basic);
  tcase_add_test(tcase_core, memchr_t2_not_found);
  tcase_add_test(tcase_core, memchr_t3_multiple);
  tcase_add_test(tcase_core, memchr_t4_with_null);
  tcase_add_test(tcase_core, memchr_t5_empty);
  tcase_add_test(tcase_core, memchr_t6_single);

  tcase_add_test(tcase_core, memset_t1_basic);
  tcase_add_test(tcase_core, memset_t2_full);
  tcase_add_test(tcase_core, memset_t3_zero_fill);
  tcase_add_test(tcase_core, memset_t4_zero_n);
  tcase_add_test(tcase_core, memset_t5_large);
  tcase_add_test(tcase_core, memset_t6_single);

  tcase_add_test(tcase_core, strncat_t1_basic);
  tcase_add_test(tcase_core, strncat_t2_partial_copy);
  tcase_add_test(tcase_core, strncat_t3_empty);
  tcase_add_test(tcase_core, strncat_t4_empty_src);
  tcase_add_test(tcase_core, strncat_t5_zero_n);
  tcase_add_test(tcase_core, strncat_t6_big_n);
  tcase_add_test(tcase_core, strncat_t7_big_dest);

  tcase_add_test(tcase_core, strchr_t1_basic);
  tcase_add_test(tcase_core, strchr_t2_first);
  tcase_add_test(tcase_core, strchr_t3_last);
  tcase_add_test(tcase_core, strchr_t4_not_found);
  tcase_add_test(tcase_core, strchr_t5_null);
  tcase_add_test(tcase_core, strchr_t6_empty_str);
  tcase_add_test(tcase_core, strchr_t7_multiple);
  tcase_add_test(tcase_core, strchr_t8_not_found_large);

  tcase_add_test(tcase_core, strncmp_t1_basic);
  tcase_add_test(tcase_core, strncmp_t2_diff_str);
  tcase_add_test(tcase_core, strncmp_t3_partial_match);
  tcase_add_test(tcase_core, strncmp_t4_empty_str);
  tcase_add_test(tcase_core, strncmp_t5_empty_first_str);
  tcase_add_test(tcase_core, strncmp_t6_empty_second_str);
  tcase_add_test(tcase_core, strncmp_t7_zero_n);
  tcase_add_test(tcase_core, strncmp_t8_diff_length);
  tcase_add_test(tcase_core, strncmp_t9_big_n);

  tcase_add_test(tcase_core, strncpy_t1_basic);
  tcase_add_test(tcase_core, strncpy_t2_partial);
  tcase_add_test(tcase_core, strncpy_t3_with_null);
  tcase_add_test(tcase_core, strncpy_t4_epmty_str);
  tcase_add_test(tcase_core, strncpy_t5_empty_str_zero_n);
  tcase_add_test(tcase_core, strncpy_t6_big_n);
  tcase_add_test(tcase_core, strncpy_t7_overwrite);

  tcase_add_test(tcase_core, strcspn_t1_basic);
  tcase_add_test(tcase_core, strcspn_t2_no_match);
  tcase_add_test(tcase_core, strcspn_t3_empty_str1);
  tcase_add_test(tcase_core, strcspn_t4_empty_str2);
  tcase_add_test(tcase_core, strcspn_t5_match_at_end);
  tcase_add_test(tcase_core, strcspn_t6_match_at_start);
  tcase_add_test(tcase_core, strcspn_t7_multiple);
  tcase_add_test(tcase_core, strcspn_t8_big_str_no_match);
  tcase_add_test(tcase_core, strcspn_t9_big_str_with_match);

  tcase_add_test(tcase_core, strerror_t1_valid_codes);
  tcase_add_test(tcase_core, strerror_t2_negative_code);
  tcase_add_test(tcase_core, strerror_t3_big_code);
  tcase_add_test(tcase_core, strerror_t4_zero_code);

  tcase_add_test(tcase_core, strlen_t1_basic);
  tcase_add_test(tcase_core, strlen_t2_empty);
  tcase_add_test(tcase_core, strlen_t3_with_space);
  tcase_add_test(tcase_core, strlen_t4_with_null);
  tcase_add_test(tcase_core, strlen_t5_big);
  tcase_add_test(tcase_core, strlen_t6_with_null);
  tcase_add_test(tcase_core, strlen_t7_with_special);
  tcase_add_test(tcase_core, strlen_t8_russian);
  tcase_add_test(tcase_core, strlen_t9_numbers);

  tcase_add_test(tcase_core, strpbrk_t1_basic);
  tcase_add_test(tcase_core, strpbrk_t2_no_match);
  tcase_add_test(tcase_core, strpbrk_t3_empty_str1);
  tcase_add_test(tcase_core, strpbrk_t4_empty_str2);
  tcase_add_test(tcase_core, strpbrk_t5_match_at_start);
  tcase_add_test(tcase_core, strpbrk_t6_match_at_end);
  tcase_add_test(tcase_core, strpbrk_t7_multiple);
  tcase_add_test(tcase_core, strpbrk_t8_big_str);
  tcase_add_test(tcase_core, strpbrk_t9_big_str_no_match);
  tcase_add_test(tcase_core, strpbrk_t10_russian);

  tcase_add_test(tcase_core, strrchr_t1_basic);
  tcase_add_test(tcase_core, strrchr_t2_no_match);
  tcase_add_test(tcase_core, strrchr_t3_empty_str);
  tcase_add_test(tcase_core, strrchr_t4_null);
  tcase_add_test(tcase_core, strrchr_t5_multiple);
  tcase_add_test(tcase_core, strrchr_t6_match_at_start);
  tcase_add_test(tcase_core, strrchr_t7_match_at_end);
  tcase_add_test(tcase_core, strrchr_t8_big_str);

  tcase_add_test(tcase_core, strstr_t1_basic);
  tcase_add_test(tcase_core, strstr_t2_no_match);
  tcase_add_test(tcase_core, strstr_t3_empty_h);
  tcase_add_test(tcase_core, strstr_t4_emty_n);
  tcase_add_test(tcase_core, strstr_t5_full_match);
  tcase_add_test(tcase_core, strstr_t6_match_at_start);
  tcase_add_test(tcase_core, strstr_t7_match_at_end);
  tcase_add_test(tcase_core, strstr_t8_big_h);
  tcase_add_test(tcase_core, strstr_t9_big_h_no_match);
  tcase_add_test(tcase_core, strstr_t10_n_bigger_h);
  tcase_add_test(tcase_core, strstr_t11_russian);

  tcase_add_test(tcase_core, strtok_t1_basic);
  tcase_add_test(tcase_core, strtok_t2_no_delimiter);
  tcase_add_test(tcase_core, strtok_t3_multiple_delimiters);
  tcase_add_test(tcase_core, strtok_t4_multiple_consecutive_delimiters);
  tcase_add_test(tcase_core, strtok_t5_empty_string);
  tcase_add_test(tcase_core, strtok_t6_null_string);

  tcase_add_test(tcase_core, sprintf_t1_char_simple);
  tcase_add_test(tcase_core, sprintf_t2_char_with_width);
  tcase_add_test(tcase_core, sprintf_t3_char_null);
  tcase_add_test(tcase_core, sprintf_t4_int_positive);
  tcase_add_test(tcase_core, sprintf_t5_int_negative);
  tcase_add_test(tcase_core, sprintf_t6_int_with_width);
  tcase_add_test(tcase_core, sprintf_t7_int_with_flags);
  tcase_add_test(tcase_core, sprintf_t8_int_zero);
  tcase_add_test(tcase_core, sprintf_t9_int_min);
  tcase_add_test(tcase_core, sprintf_t10_int_max);
  tcase_add_test(tcase_core, sprintf_t11_float_simple);
  tcase_add_test(tcase_core, sprintf_t12_float_with_width);
  tcase_add_test(tcase_core, sprintf_t13_float_zero);
  tcase_add_test(tcase_core, sprintf_t14_float_negative);
  tcase_add_test(tcase_core, sprintf_t15_string_simple);
  tcase_add_test(tcase_core, sprintf_t16_string_with_width);
  tcase_add_test(tcase_core, sprintf_t17_string_with_precision);
  tcase_add_test(tcase_core, sprintf_t18_string_empty);
  tcase_add_test(tcase_core, sprintf_t19_unsigned_simple);
  tcase_add_test(tcase_core, sprintf_t20_unsigned_zero);
  tcase_add_test(tcase_core, sprintf_t21_unsigned_max);
  tcase_add_test(tcase_core, sprintf_t22_percent);
  tcase_add_test(tcase_core, sprintf_t23_percent_repeated);
  tcase_add_test(tcase_core, sprintf_t24_short_int);
  tcase_add_test(tcase_core, sprintf_t25_long_int);
  tcase_add_test(tcase_core, sprintf_t26_x_with_flag_hash);
  tcase_add_test(tcase_core, sprintf_t27_X_with_flag_hash);
  tcase_add_test(tcase_core, sprintf_t28_o_with_flag_hash);
  tcase_add_test(tcase_core, sprintf_t29_flag_zero_negative_number);
  tcase_add_test(tcase_core, sprintf_t30_length_L_precision);

  tcase_add_test(tcase_core, insert_t1_simple_case);
  tcase_add_test(tcase_core, insert_t2_beginning);
  tcase_add_test(tcase_core, insert_t3_end);
  tcase_add_test(tcase_core, insert_t4_empty_src);
  tcase_add_test(tcase_core, insert_t5_empty_str);
  tcase_add_test(tcase_core, insert_t6_empty_both);
  tcase_add_test(tcase_core, insert_t7_null_src);
  tcase_add_test(tcase_core, insert_t8_null_str);
  tcase_add_test(tcase_core, insert_t9_out_of_bounds);

  tcase_add_test(tcase_core, trim_t1_simple_case);
  tcase_add_test(tcase_core, trim_t2_multiple_chars);
  tcase_add_test(tcase_core, trim_t3_empty_string);
  tcase_add_test(tcase_core, trim_t4_no_trim);
  tcase_add_test(tcase_core, trim_t5_empty_src);
  tcase_add_test(tcase_core, trim_t6_empty_trim_chars);
  tcase_add_test(tcase_core, trim_t7_null_src);
  tcase_add_test(tcase_core, trim_t8_null_trim_chars);
  tcase_add_test(tcase_core, trim_t9_invalid_trim_chars);
  tcase_add_test(tcase_core, trim_t10_all_chars);
  tcase_add_test(tcase_core, trim_t11_trim_multiple_chars);
  tcase_add_test(tcase_core, trim_t12_trim_partial_match);

  tcase_add_test(tcase_core, to_lower_t1_simple);
  tcase_add_test(tcase_core, to_lower_t2_all_upper);
  tcase_add_test(tcase_core, to_lower_t3_mixed);
  tcase_add_test(tcase_core, to_lower_t4_no_change);
  tcase_add_test(tcase_core, to_lower_t5_empty_str);
  tcase_add_test(tcase_core, to_lower_t6_special_characters);

  tcase_add_test(tcase_core, to_upper_t1_simple);
  tcase_add_test(tcase_core, to_upper_t2_all_lower);
  tcase_add_test(tcase_core, to_upper_t3_mixed);
  tcase_add_test(tcase_core, to_upper_t4_no_change);
  tcase_add_test(tcase_core, to_upper_t5_empty_string);
  tcase_add_test(tcase_core, to_upper_t6_special_characters);

  suite_add_tcase(s, tcase_core);
  return s;
}

int main() {
  int fails = 0;
  Suite *s = suite_string();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_VERBOSE);
  fails = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (fails == 0) ? 0 : 1;
}