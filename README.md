# OpenMP
```
macbook:OpenMP palina$ clang -Xpreprocessor -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp ibm.c -o ibm
macbook:OpenMP palina$ ./ibm 
Initial values:
x[0] = 1.00
p[0] = 0.50
x[1] = 2.00
p[1] = 1.50
x[2] = 3.00
p[2] = 2.50
x[3] = 4.00
p[3] = 3.50
x[4] = 5.00
p[4] = 4.50
x[5] = 6.00
p[5] = 5.50
x[6] = 7.00
p[6] = 6.50
x[7] = 8.00
p[7] = 7.50
x[8] = 9.00
p[8] = 8.50
x[9] = 10.00
p[9] = 9.50
Updated values:
x[0] = 3.00
p[0] = -0.50
x[1] = 4.00
p[1] = 0.50
x[2] = 5.00
p[2] = 1.50
x[3] = 6.00
p[3] = 2.50
x[4] = 7.00
p[4] = 3.50
x[5] = 8.00
p[5] = 4.50
x[6] = 9.00
p[6] = 5.50
x[7] = 10.00
p[7] = 6.50
x[8] = 11.00
p[8] = 7.50
x[9] = 12.00
p[9] = 8.50
After atomicReadWriteUpdate:
x[0] = 12.00
x[1] = 16.00
x[2] = 20.00
x[3] = 24.00
x[4] = 28.00
x[5] = 32.00
x[6] = 36.00
x[7] = 40.00
x[8] = 44.00
x[9] = 48.00
After atomicCapture:
x[0] captured = 12, updated = 13
x[1] captured = 16, updated = 17
x[2] captured = 20, updated = 21
x[3] captured = 24, updated = 25
x[4] captured = 28, updated = 29
x[5] captured = 32, updated = 33
x[6] captured = 36, updated = 37
x[7] captured = 40, updated = 41
x[8] captured = 44, updated = 45
x[9] captured = 48, updated = 49

```
