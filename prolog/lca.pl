tree(leaf(X)).
tree(_,leaf(X), leaf(Y)).
tree(_,B1,B2).


swap(leaf(A),leaf(A)).


swap( tree(V, L, R),
      tree(V, SWAP_R, SWAP_L)):-
              swap(R,SWAP_R),
              swap(L,SWAP_L).

pathTo(X,leaf(X),[X]).

pathTo(X, tree(X,L,R), [X]).

pathTo(X, tree(V,L,R), [V|Path]):-
      pathTo(X, L, Path);
      pathTo(X, R, Path).

lastCommon([A|_],[B|_],root):-
      A\=B.
lastCommon([Common,A|_],[Common,B|_],Common):-
      A\=B.
lastCommon([Common|P1],[Common|P2],Result):-
      lastCommon(P1,P2,Result).      

lca(X,Y,T,Return):-
      pathTo(X,T,P1),
      pathTo(Y,T,P2),
      lastCommon(P1,P2,Return).
      
