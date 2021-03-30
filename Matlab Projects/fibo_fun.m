function fibo = fibo_fun(n)
fibo = zeros(n,1);
fibo(1) = 1;
fibo(2) = 1;
for i = 3 : n
    fibo(i) = fibo(i - 1) + fibo(i -2);
end
return