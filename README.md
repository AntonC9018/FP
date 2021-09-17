**Important!**

You need to compile with the GNU C++ Compiler (gcc)! 
The code makes extensive use of stack arrays of size not known at compile time.

For example code like this will not work with MSVC:

```c++
int main() 
{
    int n;
    printf("Introduceti n:");
    scanf("%i", &n);

    int nums[n];
}
```

To compile it with MSVC, you need to preallocate the buffer:

```c++
#define BUFFER_MAX_SIZE 128

int main()
{
    int nums[BUFFER_MAX_SIZE];
}
```

Or do a malloc:

```c++
int main() 
{
    int n;
    printf("Introduceti n:");
    scanf("%i", &n);

    int* nums = (int*) malloc(n * sizeof(int));
}
```


Any PR's are welcome. Leave a star as a way to say "Thank you".