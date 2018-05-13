#include <iostream>
#include <string>

using namespace std;

int get_lpf(string prime_number_string, int prime_number)
{
  int i, divisor;
  int length = prime_number_string.length();
  divisor = 0;
  for (i = 2; i < prime_number; i++)
  {
    if (length == 1 && (prime_number_string[0]- '0')%i == 0)
    {
      divisor = i;
      break;
    }
    int last = prime_number_string[length-1]- '0';
  	int second_last = prime_number_string[length-2]- '0';
    if ((second_last*10 + last) % i == 0)
    {
      divisor = i;
      break;
    }
  }
  if (divisor == 0)
    return prime_number;
  return divisor;
}

// Since input number may be very large, n % x can not be used to check if a number is divisible by x (especially in a language like C++). The idea is based on following fact that a number is divisible by x if the number formed by last two digits of it is divisible by x.

int main ()
{
  int prime_number, prime_number_start, i, j, lpf;
  string prime_number_string;
  cin >> prime_number;
  prime_number_start = prime_number;
  int *array = new int[prime_number](); // initializing every element in dynamic array to zero
  for (i = 0; i < prime_number_start; i++)
  {
    prime_number_string = to_string(prime_number);
    lpf = get_lpf(prime_number_string, prime_number);
    array[i] = lpf;
    cout << array[i] << " ";
    prime_number -= 1;
  }
}
