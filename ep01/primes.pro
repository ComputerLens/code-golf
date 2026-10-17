p(N):-forall((between(2,N,I),I<N),0<N mod I).
main:-forall((between(2,99,N),p(N)),(write(N),write(' '))).