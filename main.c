#include "ft_printf.h"
#include <stdio.h>

int main(void) {
  int ft_res;
  int std_res;

  printf("=== STARTING FT_PRINTF TESTS ===\n\n");

  // 1. Character test (%c)
  printf("[1. Character (%%c)]\n");
  ft_res = ft_printf("  ft_printf: [%c] [%c]\n", 'A', '4');
  std_res = printf("   standard: [%c] [%c]\n", 'A', '4');
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 2. String test (%s)
  printf("[2. String (%%s)]\n");
  ft_res = ft_printf("  ft_printf: [%s]\n", "Hello, 42 world!");
  std_res = printf("   standard: [%s]\n", "Hello, 42 world!");
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 3. NULL String test
  printf("[3. NULL String Protection]\n");
  ft_res = ft_printf("  ft_printf: [%s]\n", (char *)NULL);
  std_res = printf("   standard: [%s]\n", (char *)NULL);
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 4. Signed Integer tests (%d, %i)
  printf("[4. Integers (%%d / %%i)]\n");
  ft_res = ft_printf("  ft_printf: [%d] [%i] [%d]\n", 0, -42, 2147483647);
  std_res = printf("   standard: [%d] [%i] [%d]\n", 0, -42, 2147483647);
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 5. INT_MIN Edge Case test
  printf("[5. INT_MIN Edge Case]\n");
  ft_res = ft_printf("  ft_printf: [%d]\n", -2147483648);
  std_res = printf("   standard: [%d]\n", -2147483648);
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 6. Unsigned Integer test (%u)
  printf("[6. Unsigned (%%u)]\n");
  ft_res = ft_printf("  ft_printf: [%u] [%u]\n", 0, 4294967295U);
  std_res = printf("   standard: [%u] [%u]\n", 0, 4294967295U);
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 7. Hexadecimal tests (%x, %X)
  printf("[7. Hexadecimal (%%x / %%X)]\n");
  ft_res = ft_printf("  ft_printf: [%x] [%X]\n", 255, 3735928559U);
  std_res = printf("   standard: [%x] [%X]\n", 255, 3735928559U);
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 8. Pointer Address test (%p)
  printf("[8. Pointer (%%p)]\n");
  int x = 42;
  ft_res = ft_printf("  ft_printf: [%p]\n", &x);
  std_res = printf("   standard: [%p]\n", &x);
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 9. NULL Pointer Address test
  printf("[9. NULL Pointer Address]\n");
  ft_res = ft_printf("  ft_printf: [%p]\n", NULL);
  std_res = printf("   standard: [%p]\n", NULL);
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 10. Percent sign escape (%%)
  printf("[10. Percent Escape (%%%%)]\n");
  ft_res = ft_printf("  ft_printf: [100%% Success]\n");
  std_res = printf("   standard: [100%% Success]\n");
  printf("  Counts -> ft: %d | std: %d\n\n", ft_res, std_res);

  // 11. Error Handling Edge Cases
  printf("[11. Trailing Percent Error Handlers]\n");
  ft_res = ft_printf("  ft_printf trailing percent check: ");
  fflush(stdout); // Clear stdout buffer to view output cleanly
  int ft_err = ft_printf("%");
  printf("\n  Returned Value (Should be -1) -> %d\n", ft_err);

  printf("\n=== TESTS COMPLETED ===\n");
  return (0);
}
