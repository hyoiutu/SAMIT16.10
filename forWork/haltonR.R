vandercorput <- function(b,n,i=0){
  if(n == 0)
  {
    return(0)
  }
  return((n%%b)/b^(i+1) + vandercorput(b, n/b, i+1))
}
N <- 1000
x <-list(1:N)
y <- list(1,N)

for(i in 1:N){
  x[i] <- vandercorput(2,i)
  y[i] <- vandercorput(3,i)
}

plot(x,y)